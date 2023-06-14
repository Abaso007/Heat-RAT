#####################################################################
#
# "Getting Started with CMake", a tutorial video by Eric Wing.
#   Part 1 of 6: http://www.youtube.com/watch?v=CLvZTyji_Uw
#   Part 2 of 6: http://www.youtube.com/watch?v=gUW-RrRQjEg
#   Part 3 of 6: http://www.youtube.com/watch?v=sz6cPhbuTk4
#   Part 4 of 6: http://www.youtube.com/watch?v=JICZOkyNXbg
#   Part 5 of 6: http://www.youtube.com/watch?v=lAiuLHy4dCk
#   Part 6 of 6: http://www.youtube.com/watch?v=fAtJNzDZdH8
#
# You can use notepad++ for syntax highlighting.
# Naming conventions:
#   WITH_*   : option to use an external package or not
#   ENABLE_* : option to use an internal feature/code or not
#   HAVE_*   : internal variable indicating if we have and are using something
#
# Maintainers: Flavio J. Saraiva (feel free to send complaints or suggestions)
#   flaviojs @ rAthena forum/irc
#   flaviojs2005 \A-T/ gmail <D.o,T> com
#   lightaisme \A-T/ gmail <D.o,T> com
#
#####################################################################


#cmake_minimum_required( VERSION 2.8.4 )
# Functional changes from 2.8.3 to 2.8.4:
#   string(SUBSTRING) works with length -1 as "rest of string"
#   changes to some CPack generators
#   CYGWIN no longer defines WIN32
#   CMP0017: Prefer files from the CMake module directory when including from there.
# Update to 3.1 for CMAKE_CXX_STANDARD cross support definition