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
#include <direct.h>

std::string GetUser()
{
	TCHAR s[UNLEN + 1];
	DWORD sizethis = UNLEN + 1;
	GetUserName((TCHAR*)s, &sizethis);
	std::wstring ws(s);
	std::string userName(ws.begin(), ws.end());
	return userName;
}


void Sessions(string logo)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	bool logoShow = true;
	string space = "          ";
	string command = "";
	string line = "";
	string something = "";
	string curentUSER = "";
	logoShow = true;
	string ip = "";
	string pc = "";
	string use = "";
	string date = "";
	string mac = "";
	string os = "";
	string lang = "";
	string curentUsers = R"U( )U";
	int i = 0;
	int counte = 0;
	system("cls");
	string user = "Modules\\Grabbed\\users.txt";
	string comands_sessions = "Modules\\Commands\\Sessions.txt";
	string pcUser = GetUser();
	string seesionPath = "C:/Users/" + pcUser + "/AppData/Local/Temp/Windows_cache_34266834736";
	int result = _mkdir(seesionPath.c_str());
	seesionPath += "/cache.txt";

	while (true)
	{
		if (logoShow)
		{
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << logo << endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("--------------------------------------------------------------------------------------------------------------------------\n");
			printf("|                                                        Sessions                                                         |\n");
			printf("--------------------------------------------------------------------------------------------------------------------------\n");
			printf("|            User|              PC|              IP|               MAC|            Install_date|           OS|   Language|\n");
			printf("--------------------------------------------------------------------------------------------------------------------------\n");
			ifstream file(user);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (counte == 0 + (7 * i))
						use = line;
					if (counte == 1 + (7 * i))
						pc = line;
					if (counte == 2 + (7 * i))
						ip = line;
					if (counte == 3 + (7 * i))
						mac = line;
					if (counte == 4 + (7 * i))
						date = line;
					if (counte == 5 + (7 * i))
						os = line;
					if (counte == 6 + (7 * i))
					{
						lang = line;
						printf("|%16s|%16s|%16s|%18s|%24s|%13s|%11s|\n", use.c_str(), pc.c_str(), ip.c_str(), mac.c_str(), date.c_str(), os.c_str(), lang.c_str());
						printf("--------------------------------------------------------------------------------------------------------------------------\n");
						i++;
					}
					counte++;
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
			try 
			{
				ifstream file(seesionPath);
				if (file.is_open()) 
				{
					while (getline(file, line))
					{
						if (counte == 0 + (7 * i))
							use = line;
						if (counte == 1 + (7 * i))
							pc = line;
						if (counte == 2 + (7 * i))
							ip = line;
						if (counte == 3 + (7 * i))
							mac = line;
						if (counte == 4 + (7 * i))
							date = line;
						if (counte == 5 + (7 * i))
							os = line;
						if (counte == 6 + (7 * i))
						{
							lang = line;
							printf("|%16s|%16s|%16s|%18s|%24s|%13s|%11s|\n", use.c_str(), pc.c_str(), ip.c_str(), mac.c_str(), date.c_str(), os.c_str(), lang.c_str());
							printf("--------------------------------------------------------------------------------------------------------------------------\n");
							i++;
						}
						counte++;
					}
				}
			}
			catch (...){}
			printf("Hi %s!!!\n   !help ==for==> command list\n", curentUSER.c_str());
		}
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		cin >> command;
		logoShow = false;
		if (command == "!help")
		{
			Help(comands_sessions);
		}
		if (command == "!menu")
		{
			system("cls");
			logoShow = true;
			break;
		}
		if (command == "!open")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("User: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin.clear();
			cin.ignore(32767, '\n');
			getline(cin, use);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("PC: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin.clear();
			//cin.ignore(32767, '\n');
			getline(cin, pc);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("IP: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> ip;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("MAC: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> mac;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Install_date: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin.clear();
			cin.ignore(32767, '\n');
			getline(cin, date);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("OS: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin.clear();
			//cin.ignore(32767, '\n');
			getline(cin, os);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Language: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> lang;
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
			ofstream file(user, ios::app);
			if (file.is_open())
			{
				file << use << endl;
				file << pc << endl;
				file << ip << endl;
				file << mac << endl;
				file << date << endl;
				file << os << endl;
				file << lang << endl;
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
			cout << "\n\n";
			system("pause");
			system("cls");
			logoShow = true;
			Sessions(logo);
			break;
		}
		if (command == "!close")
		{
			cout << "\n\n";
			i = 0;
			counte = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Session number (remember everything starts from 0): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> i;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			ifstream file(user);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					if (counte >= 0 + (8 * i) && counte <= 7 + (8 * i))
					{
					}
					else
					{
						curentUsers.insert(curentUsers.length() - 1, line + "\n");
					}
					counte++;
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
			ofstream newfile;
			newfile.open(user);
			if (newfile.is_open())
			{
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
			system("cls");
			logoShow = true;
			Sessions(logo);
			break;
			cout << "\n\n";
		}

		if (command == "!closeAll")
		{
			cout << "\n\n";
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
			ofstream newfile;
			newfile.open(user);
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
			Sessions(logo);
			break;
			cout << "\n\n";
		}
		if (command == "!test")
		{
			i = 0;
			counte = 0;
			int test = 0;
			srand(time(NULL));
			cout << "\n\n";

			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			ifstream file(user);
			if (file.is_open())
			{

				while (getline(file, line))
				{
					if (counte == 0 + (8 * i))
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
							printf("[ofline]\n");
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
						cout << "\n";
						i++;

					}
					counte++;

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
			cout << "\n\n";
		}
		if (command == "!choose")
		{
			cout << "\n\n";
			i = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Session number (remember everything starts from 0): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cin >> i;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			Choose(logo, i);
			break;
		}
		else if (command != "!test" && command != "!choose" && command != "!test" && command != "!closeAll" && command != "!close" && command != "!open" && command != "!help" && command != "!menu")
		{
			cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!\n");
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
	}
}
