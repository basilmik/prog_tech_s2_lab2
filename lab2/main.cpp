
#include "stdio.h"
#include "class_aeroflot.h"

AEROFLOT list;

void menu_commands()
{
	printf("\n-1 exit\n");
	printf("0 see all records\n");
	printf("1 add new record\n");
	printf("2 edit record\n");
	printf("3 remove record\n");
	printf("4 sort records\n");
	printf("5 search by destination name\n");
}

void menu()
{
	int c = 0;
	while (true)
	{
		menu_commands();

		mscanf("%d", &c);
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
			printf("enter idx to which to add: from 1 to %d\n", list.get_size()+1);
			while (idx <= 0 || idx > list.get_size()+1)
				mscanf("%d", &idx);
			try {
				list.add(idx);
			}
			catch (...)
			{
				printf("could not add\n");
			}
			break;
		}
		case 2:
		{
			if (list.get_size() <= 0)
			{
				printf("list is empty\n");
				break;			
			}

			int idx = 0;
			printf("enter idx which to edit: from 1 to %d\n", list.get_size());
			while (idx <= 0 || idx > list.get_size())
				mscanf("%d", &idx);
			list.edit(idx);
			break;
		}
		case 3:
		{
			if (list.get_size() <= 0)
			{
				printf("list is empty\n");
				break;
			}

			int idx = 0;
			printf("enter idx which to remove: from 1 to %d\n", list.get_size());
			while (idx <= 0 || idx > list.get_size())
				mscanf("%d", &idx);
			list.remove(idx);
			break;
		}

		case 4:
			if (list.get_size() <= 0)
			{
				printf("list is empty\n");
				break;
			}
			list.sort();
			break;

		case 5:
			if (list.get_size() <= 0)
			{
				printf("list is empty\n");
				break;
			}
			list.find_by_dest();
			break;

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