#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "class_aeroflot.h"

AEROFLOT list;

void menu_commands()
{
	printf("-1 exit\n");
	printf("0 see all records\n");
	printf("1 add new record\n");
}

void menu()
{
	int c = 0;
	while (true)
	{
		menu_commands();
		std::cin >> c;
		switch (c)
		{
		case -1:
			return;

		case 0:
			list.print_all();
			break;

		case 1:
		{
			int idx = 0;
			printf("enter idx to witch to add: from 1 to %d\n", list.get_size()+1);
			scanf("%d", &idx);
			list.add(idx);
			break;
		}
		default:
			printf("unknown command\n");
		}
	}



}

int main()
{

	menu();

	return 0;
}