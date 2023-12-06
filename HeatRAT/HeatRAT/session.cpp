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
#include "modules.h"



void Choose(int choose)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	int col = 9;
	std::string command = "";
	std::string line = "";
	std::string something = "";
	std::string curentUSER = "";
	std::string ip = "";
	std::string pc = "";
	std::string use = "";
	std::string date = "";
	std::string mac = "";
	std::string os = "";
	std::string lang = "";
	int count = 0;
	system("cls");
	std::string path = "";
	col = 8;
	SetConsoleTextAttribute(hConsole, col);
	printf("Enter the path for downloading files: ");
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	std::cin >> path;
	system("cls");

	col = 13;
	SetConsoleTextAttribute(hConsole, col);
	std::cout << Modules::logo << std::endl;
	col = 9;
	SetConsoleTextAttribute(hConsole, col);
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	printf("|                                                    Sessions num %2d                                                    |\n", choose);
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	printf("|            User|              PC|              IP|               MAC|            Install_date|           OS|   Language|\n");
	printf("--------------------------------------------------------------------------------------------------------------------------\n");
	std::ifstream file(Modules::user);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (count == 0 + (7 * choose))
				use = line;
			if (count == 1 + (7 * choose))
				pc = line;
			if (count == 2 + (7 * choose))
				ip = line;
			if (count == 3 + (7 * choose))
				mac = line;
			if (count == 4 + (7 * choose))
				date = line;
			if (count == 5 + (7 * choose))
				os = line;
			if (count == 6 + (7 * choose))
			{
				lang = line;
				printf("|%16s|%16s|%16s|%18s|%24s|%13s|%11s|\n", use.c_str(), pc.c_str(), ip.c_str(), mac.c_str(), date.c_str(), os.c_str(), lang.c_str());
				printf("--------------------------------------------------------------------------------------------------------------------------\n");
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
	col = 9;
	SetConsoleTextAttribute(hConsole, col);
	printf("Hi %s!!!\n   !help ==for==> command list\n", curentUSER.c_str());

	while (true)
	{
		col = 6;
		SetConsoleTextAttribute(hConsole, col);
		printf(">>> ");
		col = 11;
		SetConsoleTextAttribute(hConsole, col);
		std::cin >> command;
		if (command == "!help")
		{
			Help(Modules::commands_session);

		}
		if (command == "!menu")
		{
			system("cls");
			break;
		}
		if (command == "!screenshot")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("doing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!photoWebcam")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("doing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!openLink")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("link: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
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
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");

			std::cout << "\n\n";
		}
		if (command == "!directory")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("C:\\\n");

			std::cout << "\n\n";

		}
		if (command == "!directoryContent")
		{

			std::cout << "\n\n";
			int file = 0;
			int type = 0;
			int much = 0;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			srand(time(NULL));

			much = rand() % (30 - 1) + 1;
			for (int i = 0; i <= file; i++)
			{
				file = rand() % (10 - 0) + 0;
				type = rand() % (10 - 0) + 0;
				switch (file)
				{
				case 0:
					printf("new folder");
					break;
				case 1:
					printf("image");
					break;
				case 2:
					printf("need");
					break;
				case 3:
					printf("application");
					break;
				case 4:
					printf("document");
					break;
				case 5:
					printf("my");
					break;
				case 6:
					printf("H8Jd6fe5");
					break;
				case 7:
					printf("374830847");
					break;
				case 8:
					printf("file");
					break;
				case 9:
					printf("_");
					break;
				case 10:
					printf("d3d9");
					break;
				default:
					break;
				}
				switch (type)
				{
				case 0:
					printf("\\");
					break;
				case 1:
					printf(".png");
					break;
				case 2:
					printf(".docx");
					break;
				case 3:
					printf(".exe");
					break;
				case 4:
					printf(".txt");
					break;
				case 5:
					printf(".pdf");
					break;
				case 6:
					printf(".jpg");
					break;
				case 7:
					printf(".zip");
					break;
				case 8:
					printf(".dll");
					break;
				case 9:
					printf(".dat");
					break;
				case 10:
					printf(".mp4");
					break;
				default:
					break;
				}
				std::cout << "\n";
			}


			std::cout << "\n\n";

		}
		if (command == "!createFolder")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder and folder name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("creating...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("folder %s created", something.c_str());
			std::cout << "\n\n";
		}
		if (command == "!deleteFolder")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder and folder name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("deleting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("folder %s deleted", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!deleteFile")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("deleting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s deleted", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!downloadFile")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file on your computer and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("downloading...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100 * (i / 2));
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s downloaded", something.c_str());
			std::cout << "\n\n";


		}
		if (command == "!video")
		{
			float dur = 0;
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("duration in seconds: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> dur;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("recording...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep((dur * 1000) / 60);
			}
			printf("]\n");
			printf("saving...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10 * dur);
			}
			printf("]\n");
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5 * dur);
			}
			printf("]\n");
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100 * dur);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!audio")
		{

			float dur = 0;
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("duration in seconds: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> dur;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("recording...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep((dur * 1000) / 60);
			}
			printf("]\n");
			printf("saving...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10 * dur);
			}
			printf("]\n");
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5 * dur);
			}
			printf("]\n");
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(100 * dur);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!runFile")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s is run\n", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!volume")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("volume: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("volume is: %s\n", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!turnOff")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!restart")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			Sleep(300000);
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("Hi, again!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!alt+f4")
		{
			std::cout << "\n\n";

			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			std::cout << "\n\n";
		}
		if (command == "!crazyCursor")
		{

			std::cout << "\n\n";

			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!wallpaper")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the image on your PC and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("wait...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(5);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!move")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("moveing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(500);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("curent folder %s", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!rename")
		{
			std::cout << "\n\n";

			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("new name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("curent name %s", something.c_str());
			std::cout << "\n\n";


		}
		if (command == "!encrypt")
		{
			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("encrypting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s encrypted", something.c_str());
			std::cout << "\n\n";


		}
		if (command == "!decrypt")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the file and file name, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("decrypting...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(10);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("file %s decrypted", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!logs")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("searching...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("packing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(2);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("sending...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000);
			}
			printf("]\n");
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("Fatal ERROR!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!screamer")
		{
			std::cout << "\n\n";
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!\n");
			std::cout << "\n\n";

		}
		if (command == "!moveFile")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder and file name without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			printf("path to the new folder without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("moveing...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(500);
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			std::cout << "\n\n";

		}
		if (command == "!lock")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("lock? (y/n): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			std::cout << "\n\n";

		}
		if (command == "!downloadFolder")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("path to the folder, without spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("downloading...\n");
			printf("[");
			for (int i = 0; i <= 60; i++)
			{
				printf("=");
				Sleep(1000 * (i / 2));
			}
			printf("]\n");
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("folder %s downloaded", something.c_str());
			std::cout << "\n\n";

		}
		if (command == "!processes")
		{
			Help(Modules::proc);


		}
		if (command == "!closeProces")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("proces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			std::cout << "\n\n";

		}
		if (command == "!banTM")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("ban? (y/n): ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			std::cout << "\n\n";

		}
		if (command == "!message")
		{

			std::cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			printf("massage, on spaces: ");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			std::cin >> something;
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			std::cout << "\n\n";

		}
		if (command == "!CMDbomb")
		{


			std::cout << "\n\n";
			col = 2;
			SetConsoleTextAttribute(hConsole, col);
			printf("done!!!");
			std::cout << "\n\n";

		}

	}
}

