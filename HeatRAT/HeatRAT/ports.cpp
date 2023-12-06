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
#include "modules.h"



void Ports()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	std::string command = "";
	std::string line = "";
	std::string something = "";
	std::string port = "";
	std::string curentPorts = R"U( )U";
	system("cls");

	col = 13;
	SetConsoleTextAttribute(hConsole, col);
	std::cout << Modules::logo << std::endl;
	col = 9;
	SetConsoleTextAttribute(hConsole, col);
	printf("%40s-----------------------------------------\n", Modules::space.c_str());
	printf("%40s|                 Ports                 |\n", Modules::space.c_str());
	printf("%40s-----------------------------------------\n", Modules::space.c_str());
	printf("Hi %s!!!\n>>> !help ==for==> command list\n", Modules::curentUSER.c_str());

	while (true)
	{
		col = 9;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> command;
		if (command == "!help")
		{
			Help(Modules::commands_port);
		}
		if (command == "!menu")
		{
			system("cls");
			break;
		}
		if (command == "!open")
		{
			std::cout << "\n\n";
			
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("port number: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> port;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("type (TCP/UDP/ALL): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			if (something != "TCP" && something != "UDP" && something != "ALL")
			{
				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("ERROR ==> 320\n");
				col = 11;
				SetConsoleTextAttribute(hConsole, col);
			}
			else
			{
				col = 8;
				SetConsoleTextAttribute(hConsole, col);
				printf("opening...\n");
				printf("[");
				for (int i = 0; i <= 60; i++)
				{
					printf("=");
					Sleep(2);
				}
				printf("]\n");
				if (stoi(port) >= 1025 && stoi(port) <= 5000 || stoi(port) == 80)
				{
					std::ofstream file(Modules::prefrences, std::ios::app);
					if (file.is_open())
					{
						file << port << std::endl;
					}
					else
					{

						col = 4;
						SetConsoleTextAttribute(hConsole, col);
						printf("Fatal ERROR!!!\n");
					}
					file.close();
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("port number %s is open\n", port.c_str());
				}
				else
				{
					col = 4;
					SetConsoleTextAttribute(hConsole, col);
					printf("port reserved\n");
				}

			}
			std::cout << "\n\n";
		}
		if (command == "!close")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("port number: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> port;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("closing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			std::ifstream file(Modules::prefrences);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (stoi(line) != stoi(port))
					{
						curentPorts.insert(curentPorts.length() - 1, line + "\n");
					}
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
			curentPorts.pop_back();
			std::ofstream newfile;
			newfile.open(Modules::prefrences);
			if (newfile.is_open())
			{
				newfile << "";
				newfile << curentPorts;
				col = 2;
				SetConsoleTextAttribute(hConsole, col);
				printf("port number %s is closed\n", port.c_str());
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			newfile.close();
			std::cout << "\n\n";
		}
		if (command == "!closeAll")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("closing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			std::ofstream newfile;
			newfile.open(Modules::prefrences);
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
			std::cout << "\n\n";
		}
		if (command == "!ports")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::ifstream file(Modules::prefrences);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					printf("========================================================================================================================\n");
					printf("port number ==================> %s\n", line.c_str());
					printf("port status ==================> ");
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("[active]\n");
					col = 8;
					SetConsoleTextAttribute(hConsole, col);
					printf("port type ====================> ");
					col = 2;
					SetConsoleTextAttribute(hConsole, col);
					printf("[online]\n");
					col = 8;
					SetConsoleTextAttribute(hConsole, col);
					line.pop_back();
					printf("port IPv4 address ============> 196.128.0.%s\n", line.c_str());
					printf("port gateway =================> 196.128.%s.1\n", line.c_str());

				}
			}
			else
			{

				col = 4;
				SetConsoleTextAttribute(hConsole, col);
				printf("Fatal ERROR!!!\n");
			}
			printf("========================================================================================================================\n");

			file.close();
			line = "";
			std::cout << "\n\n";
		}
		if (command == "!test")
		{
			int test = 0;
			srand(time(NULL));
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			std::ifstream file(Modules::prefrences);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					col = 8;
					SetConsoleTextAttribute(hConsole, col);
					printf("checking...\n");
					printf("[");
					for (int i = 0; i <= 60; i++)
					{
						printf("=");
						Sleep(2);
					}
					printf("]\n");
					printf("port number %s ====> ", line.c_str());
					test = rand() % (10 - 1) + 1;
					switch (test)
					{
					case 1:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 2:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 3:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 4:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 5:
						col = 4;
						SetConsoleTextAttribute(hConsole, col);
						printf("[failed]\n");
						break;
					case 6:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 7:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 8:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 9:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					case 10:
						col = 2;
						SetConsoleTextAttribute(hConsole, col);
						printf("[passed]\n");
						break;
					default:
						col = 4;
						SetConsoleTextAttribute(hConsole, col);
						printf("Fatal ERROR!!!\n");
						break;
					}
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
			std::cout << "\n\n";
		}
		else if (command != "!test" && command != "!ports" && command != "!closeAll" && command != "!close" && command != "!open" && command != "!menu" && command != "!help")
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
