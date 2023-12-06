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


#include "main.h"
#include "transfer.h"
#include "sessionSelecter.h"
#include <Lmcons.h>
#include "modules.h"

std::string GetUser()
{
	TCHAR s[UNLEN + 1];
	DWORD sizethis = UNLEN + 1;
	GetUserName((TCHAR*)s, &sizethis);
	std::wstring ws(s);
	std::string userName(ws.begin(), ws.end());
	return userName;
}


void Sessions()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	bool logoShow = true;
	std::string command = "";
	std::string line = "";
	logoShow = true;
	std::string ip = "";
	std::string pc = "";
	std::string use = "";
	std::string date = "";
	std::string mac = "";
	std::string os = "";
	int extraSessionsNum = 0;
	std::string lang = "";
	std::string curentUsers = R"U( )U";
	int i = 0;
	int count = 0;
	system("cls");
	std::string pcUser = GetUser();
	std::string seesionPath = "C:/Users/" + pcUser + "/AppData/Local/Temp/Windows_cache_34266834736/cache.txt";

	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << Modules::logo << std::endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("--------------------------------------------------------------------------------------------------------------------------\n");
			printf("|                                                        Sessions                                                        |\n");
			printf("--------------------------------------------------------------------------------------------------------------------------\n");
			printf("|            User|              PC|              IP|               MAC|            Install_date|           OS|   Language|\n");
			printf("--------------------------------------------------------------------------------------------------------------------------\n");
			std::ifstream file(Modules::user);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (count == 0 + (7 * i))
						use = line;
					if (count == 1 + (7 * i))
						pc = line;
					if (count == 2 + (7 * i))
						ip = line;
					if (count == 3 + (7 * i))
						mac = line;
					if (count == 4 + (7 * i))
						date = line;
					if (count == 5 + (7 * i))
						os = line;
					if (count == 6 + (7 * i))
					{
						lang = line;
						printf("|%16s|%16s|%16s|%18s|%24s|%13s|%11s|\n", use.c_str(), pc.c_str(), ip.c_str(), mac.c_str(), date.c_str(), os.c_str(), lang.c_str());
						printf("--------------------------------------------------------------------------------------------------------------------------\n");
						i++;
					}
					count++;
				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			extraSessionsNum = i;
			try 
			{
				std::ifstream file(seesionPath);
				if (file.is_open()) 
				{
					while (getline(file, line))
					{
						if (count == 0 + (7 * i))
							use = line;
						if (count == 1 + (7 * i))
							pc = line;
						if (count == 2 + (7 * i))
							ip = line;
						if (count == 3 + (7 * i))
							mac = line;
						if (count == 4 + (7 * i))
							date = line;
						if (count == 5 + (7 * i))
							os = line;
						if (count == 6 + (7 * i))
						{
							lang = line;
							printf("|%16s|%16s|%16s|%18s|%24s|%13s|%11s|\n", use.c_str(), pc.c_str(), ip.c_str(), mac.c_str(), date.c_str(), os.c_str(), lang.c_str());
							printf("--------------------------------------------------------------------------------------------------------------------------\n");
							i++;
						}
						count++;
					}
				}
				else
				{
					extraSessionsNum = -9999999;
				}
			}
			catch (...){
				extraSessionsNum = -9999999;
			}
			printf("Hi %s!!!\n   !help ==for==> command list\n", Modules::curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(Modules::commands_sessions);
		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!open")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("User: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::getline(std::cin, use);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("PC: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin.clear();
			std::getline(std::cin, pc);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("IP: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> ip;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("MAC: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> mac;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Install_date: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::getline(std::cin, date);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("OS: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin.clear();
			//cin.ignore(32767, '\n');
			std::getline(std::cin, os);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Language: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> lang;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("opening...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100 * (i / 5));
			}
			printf("]\n");
			std::ofstream file(Modules::user, std::ios::app);
			if (file.is_open())
			{
				file << use << std::endl;
				file << pc << std::endl;
				file << ip << std::endl;
				file << mac << std::endl;
				file << date << std::endl;
				file << os << std::endl;
				file << lang << std::endl;
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
				col = 9;
				SetConsoleTextAttribute(hConsole, col);
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			std::cout << "\n\n";
			system("pause");
			system("cls");
			logoShow = true;
			Sessions();
			break;
		}
		if (command == "!close")
		{
			std::cout << "\n\n";
			i = 0;
			count = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Session number (remember everything starts from 0): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> i;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			if (i == extraSessionsNum)
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				if (std::remove(seesionPath.c_str()) == 0) {
					printf("session number %d is closed\n", i);
				}
				else 
				{
					col = 4;
					SetConsoleTextAttribute(hConsole, col);
					printf("Fatal ERROR!!!\n");
				}
				
				col = 8;
				SetConsoleTextAttribute(hConsole, col);
				system("pause");
				system("cls");
				logoShow = true;
				Sessions();
				break;
				std::cout << "\n\n";
			}
			else
			{
				std::ifstream file(Modules::user);
				if (file.is_open())
				{
					while (getline(file, line))
					{
						if (count >= 0 + (7 * i) && count <= 6 + (7 * i))
						{
						}
						else
						{
							curentUsers.insert(curentUsers.length() - 1, line + "\n");
						}
						count++;
					}
				}
				else
				{

					col = 4;
					SetConsoleTextAttribute(hConsole, col);
					printf("Fatal ERROR!!!\n");
				}
				curentUsers.pop_back();
				file.close();
				line = "";
				std::ofstream newfile;
				newfile.open(Modules::user);
				if (newfile.is_open())
				{
					newfile << "";
					newfile << curentUsers;
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("session number %d is closed\n", i);
				}
				else
				{

					col = 4;
					SetConsoleTextAttribute(hConsole, col);
					printf("Fatal ERROR!!!\n");
				}
				newfile.close();
				col = 8;
				SetConsoleTextAttribute(hConsole, col);
				system("pause");
				system("cls");
				logoShow = true;
				Sessions();
				break;
				std::cout << "\n\n";
			}
			
		}

		if (command == "!closeAll")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::remove(seesionPath.c_str());
			printf("closing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			std::ofstream newfile;
			newfile.open(Modules::user);
			if (newfile.is_open())
			{
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("done!!!\n");
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			system("pause");
			system("cls");
			logoShow = true;
			Sessions();
			break;
			std::cout << "\n\n";
		}
		if (command == "!test")
		{
			i = 0;
			count = 0;
			int test = 0;
			srand(time(NULL));
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);

			std::ifstream file(Modules::user);
			if (file.is_open())
			{

				while (std::getline(file, line))
				{
					if (count == 0 + (7 * i))
					{
						col = 8;
						SetConsoleTextAttribute(hConsole, col);
						printf("checking...\n");
						printf("[");
						for (int i = 0; i <= 60; i++)
						{
							printf("=");
							Sleep(50);
						}
						printf("]\n");
						printf("%d.USER: %s ====> ", i, line.c_str());
						test = rand() % (10 - 1) + 1;
						switch (test)
						{
						case 1:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 2:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 3:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 4:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 5:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 6:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 7:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 8:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						case 9:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("[offline]\n");
							break;
						case 10:
							col = 2;
							SetConsoleTextAttribute(hConsole, col);
							printf("[online]\n");
							break;
						default:
							col = 4;
							SetConsoleTextAttribute(hConsole, col);
							printf("Fatal ERROR!!!\n");
							break;
						}
						std::cout << "\n";
						i++;

					}
					count++;

				}
				std::ifstream file1(seesionPath);
				if (file1.is_open())
				{
					if(getline(file1, line))
					{
						printf("%d.USER: %s ====> ", i, line.c_str());
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[online]\n");
					}

				}
				file1.close();

			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			file.close();
			line = "";
			std::cout << "\n\n";
		}
		if (command == "!choose")
		{
			std::cout << "\n\n";
			i = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Session number (remember everything starts from 0): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> i;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			if (i >= 0)
			{
				if (i == extraSessionsNum)
				{
					col = 4;
					SetConsoleTextAttribute(hConsole, col);
					printf("\nFatal ERROR!!!\n\tThis session is protected by the admin\n\t\t");
					system("pause");
					system("cls");
					Sessions();
				}
				else
				{
					Choose(i);
					break;
				}
			}
			else 
			{
				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("\nFatal ERROR!!!\n\n\n");
			}
			

		}
		else if (command != "!test" && command != "!choose" && command != "!test" && command != "!closeAll" && command != "!close" && command != "!open" && command != "!help" && command != "!menu")
		{
			std::cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			std::cout << "\n\n";
		}
	}
}