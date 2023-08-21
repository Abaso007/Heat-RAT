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
# Prevent building in the source directory by default
#
option( ALLOW_SAME_DIRECTORY "Allow CMake to build in the source directory." OFF )
if( ALLOW_SAME_DIRECTORY )
elseif( "${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_BINARY_DIR}" )
	message( FATAL_ERROR
		"Do not use the source directory to build your files, instead delete CMakeCache.txt, create a separate folder and build there.\n"
		"Example: (build in subdir 'build' and install to source dir)\n"
		"  rm -f CMakeCache.txt\n"
		"  mkdir build\n"
		"  cd build\n"
		"  cmake -G\"Unix Makefiles\" -DINSTALL_TO_SOURCE=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo ..\n"
		"  make install\n"
		"  cd ..\n"
		"  rm -rf build\n"
		"To skip this check, set ALLOW_SAME_DIRECTORY to ON (-DALLOW_SAME_DIRECTORY=ON)" )
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
# 3rd party
#
set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/cmake  CACHE INTERNAL "" )
include( CheckCSourceCompiles )
include( CheckCSourceRuns )
include( CheckIncludeFile )
include( CheckFunctionExists )
include( FindFunctionLibrary )
include( TestBigEndian )


#
# PACKETVER
#
set( PACKETVER CACHE STRING "Sets the PACKETVER define of the servers. (see src/common/mmo.h)" )
if( PACKETVER )
	list( APPEND GLOBAL_DEFINITIONS  PACKETVER=${PACKETVER} )
endif()


#
# Find git
#
message( STATUS "Detecting git" )
find_package(Git)
if(GIT_FOUND)
	if(GIT_VERSION_STRING)
		message(STATUS "Found git : ${GIT_EXECUTABLE} version (${GIT_VERSION_STRING})")
	else()
		message(STATUS "Found git : ${GIT_EXECUTABLE}")
	endif()
endif()

include(GetGitVersion)
get_git_version()

#include(GetSvnVersion)
#get_svn_version(SVN_VERSION)
#message( STATUS "SVN_VERSION: ${SVN_VERSION}" )


#
# threads
#
message( STATUS "Detecting threads library" )
set( CMAKE_THREAD_PREFER_PTHREAD 1 )
find_package(Threads REQUIRED)
if( CMAKE_THREAD_LIBS_INIT )
	message( STATUS "Adding global library: ${CMAKE_THREAD_LIBS_INIT}" )
	set_property( CACHE GLOBAL_LIBRARIES  PROPERTY VALUE ${GLOBAL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )
endif()
message( STATUS "Detecting threads library - done" )

message( STATUS "Check if supporting Thread local storage (TLS)" )
file( READ "${CMAKE_SOURCE_DIR}/3rdparty/cmake/tests/HAVE_TLS.c" _SOURCE )
CHECK_C_SOURCE_RUNS( "${_SOURCE}" HAVE_TLS )
if( HAVE_TLS )
	message( STATUS "Check for TLS- yes" )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DHAVE_TLS" )
else()
	message( STATUS "Check for TLS - no" )
endif()


#
# math library (FreeBSD/Linux/Solaris)
#
if( NOT WIN32 )
message( STATUS "Detecting math library (m)" )
CHECK_INCLUDE_FILE( math.h HAVE_MATH_H )
if( NOT HAVE_MATH_H )
	message( FATAL_ERROR "math.h not found" )
endif()
set( CMAKE_REQUIRED_LIBRARIES ${GLOBAL_LIBRARIES} )
find_function_library( floor FUNCTION_FLOOR_LIBRARIES m )
if( FUNCTION_FLOOR_LIBRARIES )
	message( STATUS "Adding global library: ${FUNCTION_FLOOR_LIBRARIES}" )
	set_property( CACHE GLOBAL_LIBRARIES  PROPERTY VALUE ${GLOBAL_LIBRARIES} ${FUNCTION_FLOOR_LIBRARIES} )
endif()
message( STATUS "Detecting math library (m) - done" )
endif()


#
# dynamic loading library (Linux)
#
if( NOT WIN32 )
message( STATUS "Detecting dynamic loading library (dl)" )
set( CMAKE_REQUIRED_LIBRARIES ${GLOBAL_LIBRARIES} )
find_function_library( dlopen FUNCTION_DLOPEN_LIBRARIES dl )
if( FUNCTION_DLOPEN_LIBRARIES )
	message( STATUS "Adding global library: ${FUNCTION_DLOPEN_LIBRARIES}" )
	set_property( CACHE GLOBAL_LIBRARIES  PROPERTY VALUE ${GLOBAL_LIBRARIES} ${FUNCTION_DLOPEN_LIBRARIES} )
endif()
message( STATUS "Detecting dynamic loading library (dl) - done" )
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
# enable web server?
#
option( ENABLE_WEB_SERVER "Build web-server (default=ON)" ON )

#
# Test for big endian
#
TEST_BIG_ENDIAN( BIG_ENDIAN )
if( NOT DEFINED BIG_ENDIAN )
	message( WARNING "unable to determine endianess, only LITTLE ENDIAN is supported" )
elseif( BIG_ENDIAN )
	message( FATAL_ERROR "bigendian is not supported" )
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
# Test if function exists:
#   setrlimit - used to set the socket limit
#   strnlen - string length with upper scan bound
#   getpid - process id
#   gettid - thread id
#
CHECK_FUNCTION_EXISTS( setrlimit HAVE_SETRLIMIT )
CHECK_FUNCTION_EXISTS( strnlen HAVE_STRNLEN )
CHECK_FUNCTION_EXISTS( getpid HAVE_GETPID )
CHECK_FUNCTION_EXISTS( gettid HAVE_GETTID )
foreach( define HAVE_SETRLIMIT HAVE_STRNLEN HAVE_GETPID HAVE_GETTID )
	if( ${define} )
		set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -D${define}" )
	endif()
endforeach()


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
# Enable extra debug code (default=OFF)
#
option( ENABLE_EXTRA_DEBUG_CODE "enable extra debug code (default=OFF)" OFF )
if( ENABLE_EXTRA_DEBUG_CODE )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DDEBUG" )
	message( STATUS "Enabled extra DEBUG code" )
endif()


#
# Enable EPOLL (default=OFF)
# Only for Linux
#
option( ENABLE_EXTRA_SOCKET_POLL "enable SOCKET_EPOLL (default=OFF)" OFF )
if( ENABLE_EXTRA_SOCKET_POLL )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DSOCKET_EPOLL" )
	message( STATUS "Enabled SOCKET_EPOLL" )
endif()


#
# Enable builtin memory manager (default=default)
#
set( MEMMGR_OPTIONS "default;yes;no" )
set( ENABLE_MEMMGR "default" CACHE STRING "enable builtin memory manager: ${MEMMGR_OPTIONS} (default=default)" )
set_property( CACHE ENABLE_MEMMGR  PROPERTY STRINGS ${MEMMGR_OPTIONS} )
if( ENABLE_MEMMGR STREQUAL "default" )
	# use source code default
elseif( ENABLE_MEMMGR STREQUAL "yes" )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DUSE_MEMMGR" )
	message( STATUS "Enabled the builtin memory manager" )
elseif( ENABLE_MEMMGR STREQUAL "no" )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DNO_MEMMGR" )
	message( STATUS "Disabled the builtin memory manager" )
else()
	message( FATAL_ERROR "invalid option ENABLE_MEMMGR=${ENABLE_MEMMGR} (valid options: ${MEMMGR_OPTIONS})" )
endif()


#
# Enable memory library (default=system)
#
set( MEMORY_OPTIONS "system;memwatch;dmalloc;gcollect" )
set( ENABLE_MEMORY "system" CACHE STRING "enable memory library: ${MEMORY_OPTIONS} (default=system)" )
set_property( CACHE ENABLE_MEMORY  PROPERTY STRINGS ${MEMORY_OPTIONS} )
if( ENABLE_MEMORY STREQUAL "system" )
	# use system functions

elseif( ENABLE_MEMORY STREQUAL "memwatch" )
	CHECK_INCLUDE_FILE( memwatch.h HAVE_MEMWATCH_H )
	find_library( MEMWATCH_LIBRARY memwatch )
	mark_as_advanced( MEMWATCH_LIBRARY )
	if( HAVE_MEMWATCH_H AND MEMWATCH_LIBRARY )
		message( STATUS "Adding global library: ${MEMWATCH_LIBRARY}" )
		set_property( CACHE GLOBAL_LIBRARIES    PROPERTY VALUE ${GLOBAL_LIBRARIES} ${MEMWATCH_LIBRARY} )
		set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DMEMWATCH" )
		message( STATUS "Enabled the memory library memwatch" )
	else()
		message( FATAL_ERROR "Failed to enable the memory library memwatch" )
	endif()

elseif( ENABLE_MEMORY STREQUAL "dmalloc" )
	CHECK_INCLUDE_FILE( dmalloc.h HAVE_DMALLOC_H )
	find_library( DMALLOC_LIBRARY dmalloc )
	mark_as_advanced( DMALLOC_LIBRARY )
	if( HAVE_DMALLOC_H AND DMALLOC_LIBRARY )
		message( STATUS "Adding global library: ${DMALLOC_LIBRARY}" )
		set_property( CACHE GLOBAL_LIBRARIES    PROPERTY VALUE ${GLOBAL_LIBRARIES} ${DMALLOC_LIBRARY} )
		set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DDMALLOC -DDMALLOC_FUNC_CHECK" )
		message( STATUS "Enabled the memory library dmalloc" )
	else()
		message( FATAL_ERROR "Failed to enable the memory library dmalloc" )
	endif()

elseif( ENABLE_MEMORY STREQUAL "gcollect" )
	CHECK_INCLUDE_FILE( gc.h HAVE_GC_H )
	find_library( GC_LIBRARY gc )
	mark_as_advanced( GC_LIBRARY )
	if( HAVE_GC_H AND GC_LIBRARY )
		message( STATUS "Adding global library: ${GC_LIBRARY}" )
		set_property( CACHE GLOBAL_LIBRARIES    PROPERTY VALUE ${GLOBAL_LIBRARIES} ${GC_LIBRARY} )
		set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DGCOLLECT" )
		message( STATUS "Enabled the memory library gcollect" )
	else()
		message( FATAL_ERROR "Failed to enable the memory library gcollect" )
	endif()

else()
	message( FATAL_ERROR "invalid option ENABLE_MEMORY=${ENABLE_MEMORY} (valid options: ${MEMORY_OPTIONS})" )
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


#
# Enable extra buildbot code (default=OFF)
#
option( ENABLE_EXTRA_BUILDBOT_CODE "enable extra buildbot code (default=OFF)" OFF )
if( ENABLE_EXTRA_BUILDBOT_CODE )
	set_property( CACHE GLOBAL_DEFINITIONS  PROPERTY VALUE "${GLOBAL_DEFINITIONS} -DBUILDBOT" )
	message( STATUS "Enabled extra BUILDBOT code" )
endif()