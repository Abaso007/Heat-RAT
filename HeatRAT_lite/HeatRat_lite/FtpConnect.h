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
#include <Windows.h>
#include <WinInet.h>
#include <string>

#include "WinApi.h"

#pragma comment(lib, "WinInet.lib")

/**
 * @brief Represents a class for FTP connectivity and file transfer operations.
 *
 * The FtpConnect class provides methods for establishing an FTP connection,
 * uploading and downloading files, creating directories, and navigating the FTP server.
 */
class FtpConnect
{
public:

    /**
     * @brief Constructor for FtpConnect class.
     *
     * @param host The FTP server host.
     * @param username The FTP username.
     * @param password The FTP password.
     */
    FtpConnect(const std::string& host, const std::string& username, const std::string& password);

    /**
     * @brief Destructor for FtpConnect class.
     */
    ~FtpConnect();

    /**
     * @brief Establishes an FTP connection using the provided credentials.
     */
    void connect();

    /**
     * @brief Uploads a local file to the FTP server.
     *
     * @param local_path The path of the local file to be uploaded.
     * @param server_name The name to be given to the file on the FTP server.
     * @return True if the upload is successful; otherwise, false.
     */
    bool upload_file(const std::string& local_path, const std::string& server_name);

    /**
     * @brief Downloads a file from the FTP server to the local machine.
     *
     * @param local_path The path where the file will be saved locally.
     * @param server_name The name of the file on the FTP server.
     * @return True if the download is successful; otherwise, false.
     */
    bool retr_file(const std::string& local_path, const std::string& server_name);

    /**
     * @brief Creates a directory on the FTP server.
     *
     * @param folder_name The name of the folder to be created.
     * @return True if the directory creation is successful; otherwise, false.
     */
    bool mkdir(const std::string& folder_name);

    /**
     * @brief Changes the current working directory on the FTP server.
     *
     * @param server_path The path of the directory to change to on the server.
     * @return True if the directory change is successful; otherwise, false.
     */
    bool cd(const std::string& server_path);

private:
    std::string m_host; /**< The FTP server host. */
    std::string m_username; /**< The FTP username. */
    std::string m_password; /**< The FTP password. */

    HINTERNET FtpIo; /**< Internet Open handle for FTP operations. */
    HINTERNET FtpSession; /**< Internet Open URL handle for FTP operations. */
};
