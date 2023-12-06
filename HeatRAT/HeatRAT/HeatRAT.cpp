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




#include"main.h"
#include"transfer.h"
#include"modules.h"



int main()
{

	HANDLE  hConsole;
	int col = 9;
	bool logoShow = true;
	string space = "          ";
	string command = "";
	string line = "";
	string something = "";
	string curentUSER = "";
	string logs = "Modules\\Grabbed\\logs.txt";
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, col);
	HWND hWindowConsole = GetConsoleWindow();
	RECT r;
	GetWindowRect(hWindowConsole, &r);
	MoveWindow(hWindowConsole, r.left, r.top, 910, 500, TRUE);
	printf("\n\n\n\n\n\n\n\n\n\n%56sWelcome\n", space.c_str());
	printf("%55sYour name?\n", space.c_str());
	printf("%56s", space.c_str());
	col = 11;
	SetConsoleTextAttribute(hConsole, col);
	cin >> curentUSER;
	system("cls");


	while (true)
	{
		if (logoShow)
		{
			system("cls");
			col = 13;
			SetConsoleTextAttribute(hConsole, col);
			cout << Modules::logo << endl;
			col = 9;
			SetConsoleTextAttribute(hConsole, col);
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("%40s|                  Menu                 |\n", space.c_str());
			printf("%40s-----------------------------------------\n", space.c_str());
			printf("Hi %s!!!\n>>> !help ==for==> command list\n", curentUSER.c_str());
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
			Help(Modules::comands_menu);
		}
		if (command == "!close")
		{
			abort();
		}
		if (command == "!about")
		{
			Help(Modules::about);
		}
		if (command == "!logs")
		{
			Help(logs);
		}
		if (command == "!build")
		{
			Build();
		}
		if (command == "!preferences")
		{
			Preferences();
			logoShow = true;
		}
		if (command == "!ports")
		{
			Ports();
			logoShow = true;
		}
		if (command == "!sessions")
		{
			Sessions();
			logoShow = true;
		}
		if (command == "!github")
		{
			cout << "\n\n";
			col = 8;
			SetConsoleTextAttribute(hConsole, col);
			cout << "Creator (https://github.com/Nick-Vinesmoke)";
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}
		else if (command != "!help" && command != "!close" && command != "!about" && command != "!github" && command != "!logs" && command != "!build" && command != "!preferences" && command != "!ports" && command != "!sessions")
		{
			cout << "\n\n";
			col = 4;
			SetConsoleTextAttribute(hConsole, col);
			printf("unknown command!!!");
			col = 11;
			SetConsoleTextAttribute(hConsole, col);
			cout << "\n\n";
		}


	}

}