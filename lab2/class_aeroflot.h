#define _SRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;
class FLIGHT
{
	std::string destination_name;
	int number;
	std::string plane_type;

public:
	
	FLIGHT* next;


	void set_destination_name(std::string _name)
	{
		destination_name = _name;
	}

	void set_plane_type(std::string _type)
	{
		plane_type = _type;
	}

	void set_number(int _num)
	{
		number = _num;
	}

	std::string get_destination_name()
	{
		return destination_name;
	}

	std::string get_plane_type()
	{
		return plane_type;
	}

	int get_number()
	{
		return number;
	}


	friend std::ostream& operator<<(std::ostream& out, const FLIGHT& ptr)
	{
		out << ptr.number << " " << ptr.destination_name << " " << ptr.plane_type;
		return out;
	}

	friend std::istream& operator>>(std::istream &in, FLIGHT& ptr)
	{
		
		do {
			std::cout << "enter flight number: " << endl;
			in.clear();
			in.ignore(256, '\n'); 
			//in.clear();
			in >> ptr.number;
			
		} while (!in.good());
		
			
		in.clear();
		in.ignore(256, '\n');
		std::cout << "enter destitation name: ";
		getline(in, ptr.destination_name);
		

		std::cout << "enter plane type: ";
		in.clear();

		getline(in, ptr.plane_type);
		in.sync();
		return in;
	}

	void edit()
	{
		int c = 0;
		while (true)
		{
			printf("edit flight menu\n");
			printf("-1 back\n");
			printf("0 see values\n");
			printf("11 edit flight number\n");
			printf("12 edit flight destination\n");
			printf("13 edit flight plane type\n");


			scanf("%d", &c);
			switch (c)
			{
			case -1:
				return;

			case 0:
				cout << *this;
				break;

			case 11:
			{
				int n = -1;
				printf("enter new value: ");
				while (true)
				{
					scanf("%d", &n);
					if (n <= 0)
						printf("invalid input\n");
					else
						break;
				}
				set_number(n);

			}
				break;

			case 12:
			{	
				string str;
				printf("enter new value: ");
				getline(cin, str);
				set_destination_name(str);
			}	
			break;

			case 13:
			{	
				string str;
				printf("enter new value: ");
				getline(cin, str);
				set_plane_type(str);
			}
			break;


			default:
				printf("unknown command\n");
			}



		}
	}

};

class AEROFLOT
{
	FLIGHT* HEAD;
	FLIGHT* LAST;
	int size;

protected:
	void add_to_end()
	{
		FLIGHT* add_obj = new FLIGHT;
		std::cin >> *add_obj;
		LAST->next = add_obj;
		LAST = add_obj;
		size++;
	}

	void remove_last()
	{
		FLIGHT* prev_to_last = (*this)[size - 1];
		delete LAST;
		LAST = prev_to_last;
		LAST->next == nullptr;
		size--;
	}


public:

	AEROFLOT()
	{
		HEAD = new FLIGHT;
		LAST = HEAD;
		size = 0;
	}

	FLIGHT* operator[](int i)
	{
		if (i < 0 || i > size)
		{
			printf("index is out of range\n");
			system("pause");
			return nullptr;

		}
		int count = 0;

		FLIGHT* ptr = HEAD;
		if (ptr == nullptr)
			return nullptr;

		while (count != i)
		{
			ptr = ptr->next;
			count++;
		}
		return ptr;
	}

	

	void add(int i)
	{
		// if add to end
		if (i == size + 1)
		{
			add_to_end();
			return;
		}
		
		FLIGHT* prev_ptr = (*this)[i-1];
		if (prev_ptr == nullptr)
			return;

		FLIGHT* add_obj = new FLIGHT;
		std::cin >> *add_obj;

		FLIGHT* next_ptr = prev_ptr->next;
		if (next_ptr == nullptr)
			return;

		prev_ptr->next = add_obj;
		add_obj->next = next_ptr;
		size++;
	}

	void edit(int i)
	{
		FLIGHT* ptr = (*this)[i];
		if (ptr == nullptr)
			return;

		ptr->edit();
	}

	void remove(int i)
	{
		if (i == size)
		{
			remove_last();
			return;
		}

		FLIGHT* next_ptr = (*this)[i + 1];
		if (next_ptr == nullptr)
			return;
		FLIGHT* prev_ptr = (*this)[i - 1];
		if (prev_ptr == nullptr)
			return;
		delete (*this)[i];
		prev_ptr->next = next_ptr;
		size--;
	}


	void sort();

	void print_all()
	{
		if (size == 0)
			return;

		FLIGHT* ptr = HEAD->next;
		if (ptr == nullptr)
			return;

		while (ptr != NULL)
		{	
			std::cout << *ptr;
			std::cout << std::endl;

			ptr = ptr->next;
		}
	}

	void find_by_dest();

	int get_size()
	{
		return size;
	}

};
