#by: Nick_Vinesmoke
#https://github.com/Nick-Vinesmoke
#################################################################
set( CMAKE_LEGACY_CYGWIN_WIN32 0 )
cmake_minimum_required( VERSION 3.1 )
project( rAthena )
if( CYGWIN )
	unset( WIN32 )
endif()
set(CMAKE_CXX_STANDARD 17) # C++17...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
#set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

#actually this might be misleading for arm...
if( CMAKE_SIZEOF_VOID_P EQUAL 4 )
	set(architecture x86)
elseif( CMAKE_SIZEOF_VOID_P EQUAL 8 )
	set(architecture x64)
else()
	message( FATAL_ERROR "unexpected architecture (CMAKE_SIZEOF_VOID_P is ${CMAKE_SIZEOF_VOID_P})" )
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${suffixInstallStr})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${suffixInstallStr})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_C_CREATE_SHARED_LIBRARY)
set(CMAKE_CXX_CREATE_SHARED_LIBRARY)
set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_RELEASE_POSTFIX "r")

# Set a default build type if none was specified
set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

#
# Global stuff
#
set( GLOBAL_LIBRARIES ${LINK_LIBRARIES}  CACHE INTERNAL "" )# list (comma separated values)
set( GLOBAL_INCLUDE_DIRS ${INCLUDE_DIRECTORIES}  CACHE INTERNAL "" )# list (comma separated values)
set( GLOBAL_DEFINITIONS ${COMPILE_DEFINITIONS}  CACHE INTERNAL "" )# string (space separated values -DFOO=bar)
mark_as_advanced( GLOBAL_LIBRARIES  GLOBAL_INCLUDE_DIRS  GLOBAL_DEFINITIONS )
if( WIN32 )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DFD_SETSIZE=4096" )
endif()
if( MSVC )
	set_property( CACHE GLOBAL_LIBRARIES    PROPERTY VALUE ${GLOBAL_LIBRARIES} "oldnames.lib" "ws2_32.lib" )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE" )
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCC)
  set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -fno-strict-aliasing" )
  #set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -O2" ); #need more test to enable this
endif()

#
# networking library (Solaris/MinGW)
#
if( NOT MSVC )
message( STATUS "Detecting networking library (socket/nsl/ws2_32)" )
#set( CMAKE_REQUIRED_LIBRARIES ${GLOBAL_LIBRARIES} )
#find_function_library( bind FUNCTION_BIND_LIBRARIES socket ws2_32 )
#if( FUNCTION_BIND_LIBRARIES )
#	message( STATUS "Adding global library: ${FUNCTION_BIND_LIBRARIES}" )
#	set_property( CACHE GLOBAL_LIBRARIES  PROPERTY VALUE ${GLOBAL_LIBRARIES} ${FUNCTION_BIND_LIBRARIES} )
#endif()
set( CMAKE_REQUIRED_LIBRARIES ${GLOBAL_LIBRARIES} )
find_function_library( gethostbyname FUNCTION_GETHOSTBYNAME_LIBRARIES nsl )
if( FUNCTION_GETHOSTBYNAME_LIBRARIES )
	message( STATUS "Adding global library: ${FUNCTION_GETHOSTBYNAME_LIBRARIES}" )
	set_property( CACHE GLOBAL_LIBRARIES  PROPERTY VALUE ${GLOBAL_LIBRARIES} ${FUNCTION_GETHOSTBYNAME_LIBRARIES} )
endif()
message( STATUS "Detecting networking library (socket/nsl/ws2_32) - done" )
endif()

#
# Test monotonic clock
#
# CLOCK_MONOTONIC clock for clock_gettime
# Normally defines _POSIX_TIMERS > 0 and _POSIX_MONOTONIC_CLOCK (for posix
# compliant systems) and __FreeBSD_cc_version >= 500005 (for FreeBSD
# >= 5.1.0, which does not have the posix defines (ref. r11983)) would be
# checked but some systems define them even when they do not support it
# (ref. bugreport:1003).
#
message( STATUS "Check for monotonic clock" )
find_library( RT_LIBRARY rt )# (optional, rt on Debian)
mark_as_advanced( RT_LIBRARY )
set( CMAKE_REQUIRED_LIBRARIES ${GLOBAL_LIBRARIES} ${RT_LIBRARY} )
file( READ "${CMAKE_SOURCE_DIR}/3rdparty/cmake/tests/HAVE_MONOTONIC_CLOCK.c" _SOURCE )
CHECK_C_SOURCE_RUNS( "${_SOURCE}" HAVE_MONOTONIC_CLOCK )
if( HAVE_MONOTONIC_CLOCK )
	message( STATUS "Check for monotonic clock - yes" )
	set_property( CACHE GLOBAL_LIBRARIES    PROPERTY VALUE ${GLOBAL_LIBRARIES} ${RT_LIBRARY} )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DHAVE_MONOTONIC_CLOCK" )
else()
	message( STATUS "Check for monotonic clock - no" )
endif()

#
# Use RDTSC instruction as a timing source (time stamp counter on x86 since Pentium) (default=OFF)
#
# Enable it when you've timing issues. (ex: in conjunction with XEN or Other Virtualization mechanisms)
# Please ensure that you've disabled dynamic CPU-Frequencys, such as power saving options.
# (On the most modern Dedicated Servers cpufreq is preconfigured, see your distribution's manual how to disable it)
#
option( ENABLE_RDTSC "use RDTSC instruction as a timing source (default=OFF)" OFF )
if( ENABLE_RDTSC )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DENABLE_RDTSC" )
	message( STATUS "Enabled RDTSC as a timing source" )
endif()


#
# Enable profiler (default=none)
#
set( PROFILER_OPTIONS "none;gprof" )
set( ENABLE_PROFILER "none" CACHE STRING "enable profiler: ${PROFILER_OPTIONS} (default=none)" )
set_property( CACHE ENABLE_PROFILER  PROPERTY STRINGS ${PROFILER_OPTIONS} )
if( ENABLE_PROFILER STREQUAL "none" )
	# no profiler

elseif( ENABLE_PROFILER STREQUAL "gprof" )
	if( CMAKE_C_COMPILER_ID STREQUAL "GNU" )
		if( NOT HAVE_GPROF_FLAGS )
			set_property( CACHE CMAKE_C_FLAGS  PROPERTY VALUE "${CMAKE_C_FLAGS} -pg" )
			set_property( CACHE CMAKE_EXE_LINKER_FLAGS  PROPERTY VALUE "${CMAKE_EXE_LINKER_FLAGS} -pg" )
			set( HAVE_GPROF_FLAGS ON  CACHE INTERNAL "" )
		endif()
		message( STATUS "Enabled the profiler gprof" )
	else()
		message( FATAL_ERROR "Failed to enable the profiler gprof - not GNU" )
	endif()

else()
	message( FATAL_ERROR "invalid option ENABLE_PROFILER=${ENABLE_PROFILER} (valid options: ${PROFILER_OPTIONS})" )
endif()