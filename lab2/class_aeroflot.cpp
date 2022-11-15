#define _CRT_SECURE_NO_WARNINGS
#include "class_aeroflot.h"

int mscanf(const char* _f, void* _x)
{
while (1)
{
	if (scanf(_f, _x) != 1)
		printf("invalid input, try again\n");
	else
	{
		if (getchar());
		return 1;
	}
	if (getchar());
}
}


using namespace std;

FLIGHT::FLIGHT()
{
	printf("FLIGHT()\n");
	number = 0;
	next = nullptr;
	set_destination_name("");
	set_plane_type("");
}

FLIGHT::~FLIGHT()
{
	printf("~FLIGHT()\n");
}

void FLIGHT::set_destination_name(std::string _name)
{
	destination_name = _name;
}

void FLIGHT::set_plane_type(std::string _type)
{
	plane_type = _type;
}

void FLIGHT::set_number(int _num)
{
	number = _num;
}

std::string FLIGHT::get_destination_name()
{
	return destination_name;
}

std::string FLIGHT::get_plane_type()
{
	return plane_type;
}

int FLIGHT::get_number()
{
	return number;
}


std::ostream& operator<<(std::ostream& out, const FLIGHT& ptr)
{
	out << "flight N" << ptr.number << " destination: " << ptr.destination_name << " plane type:" << ptr.plane_type << endl;
	return out;
}

std::istream& operator>>(std::istream& in, FLIGHT& ptr)
{
	int num = -1;
	while (num < 0)
	{
		std::cout << "enter flight number: ";// << endl;
		mscanf("%d", &num);
	}
	ptr.set_number(num);

	std::cout << "enter destitation name: ";
	getline(in, ptr.destination_name);


	std::cout << "enter plane type: ";
	in.clear();

	getline(in, ptr.plane_type);
	in.sync();
	return in;
}

void FLIGHT::edit()
{
	int c = 0;
	while (true)
	{
		printf("\nedit flight menu\n");
		printf("-1 back\n");
		printf("0 see values\n");
		printf("11 edit flight number\n");
		printf("12 edit flight destination\n");
		printf("13 edit flight plane type\n");


		mscanf("%d", &c);
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
				mscanf("%d", &n);
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


void AEROFLOT::add_to_end()
{
	FLIGHT* add_obj = new FLIGHT;
	std::cin >> *add_obj;
	LAST->next = add_obj;
	LAST = add_obj;
	size++;
}

void AEROFLOT::remove_last()
{
	FLIGHT* prev_to_last = (*this)[size - 1];
	delete LAST;
	LAST = prev_to_last;
	LAST->next = nullptr;
	size--;
}

void AEROFLOT::swap(int _idx1, int _idx2)
{
	FLIGHT* ptr0 = (*this)[_idx1 - 1];
	FLIGHT* ptr1 = (*this)[_idx1];
	FLIGHT* ptr2 = (*this)[_idx2];
	FLIGHT* ptr3 = (*this)[_idx2 + 1];

	ptr0->next = ptr2;
	ptr1->next = ptr3;
	ptr2->next = ptr1;
}


AEROFLOT::AEROFLOT()
{
	printf("AEROFLOT()\n");
	HEAD = new FLIGHT;
	LAST = HEAD;
	size = 0;
}

AEROFLOT::~AEROFLOT()
{
	printf("~AEROFLOT()\n");
	FLIGHT* ptr = HEAD->next;
	FLIGHT* prev_ptr = HEAD;

	while (size != 0)
	{
			
		delete prev_ptr;
		prev_ptr = ptr;
		ptr = ptr->next;
		size--;
	}
}

FLIGHT* AEROFLOT::operator[](int i)
{
	if (i < 0 || i > size)
	{
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



void AEROFLOT::add(int i)
{
	// if add to end
	if (i == size + 1)
	{
		add_to_end();
		return;
	}

	FLIGHT* prev_ptr = (*this)[i - 1];
	if (prev_ptr == nullptr)
		return;

	FLIGHT* add_obj = new FLIGHT;
	if (add_obj == nullptr)
		throw -1;

	std::cin >> *add_obj;

	FLIGHT* next_ptr = prev_ptr->next;
	if (next_ptr == nullptr)
		return;

	prev_ptr->next = add_obj;
	add_obj->next = next_ptr;
	size++;
}

void AEROFLOT::edit(int i)
{
		
	FLIGHT* ptr = (*this)[i];
	if (ptr == nullptr)
		return;

	ptr->edit();
}

void AEROFLOT::remove(int i)
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



void AEROFLOT::sort()
{
	if (size <= 1)
	{
		return;
	}


	FLIGHT* ptr = HEAD->next;

	int idx = 1;
	while (idx != size)
	{
		FLIGHT* next_ptr = ptr->next;
		int current_ptr_num = ptr->get_number();
		int next_ptr_num = next_ptr->get_number();

		if (current_ptr_num > next_ptr_num)
		{
			swap(idx, idx + 1);
			idx = 1;
			ptr = HEAD->next;

		}
		else
		{
			ptr = ptr->next;
			idx++;
		}
	}
}

void AEROFLOT::print_all()
{
	if (size == 0)
	{
		printf("list is empty\n");
		return;
	}

	printf("\nALL RECORDS\n\n");
	
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

void AEROFLOT::find_by_dest()
{
	cout << "search for: ";// << endl;
	string str;
	cin.clear();
	getline(cin, str);

	FLIGHT* ptr = HEAD->next;
	bool found_flag = false;

	while (ptr != nullptr)
	{
		if (ptr->get_destination_name() == str)
		{
			cout << *ptr << endl;
			found_flag = true;
		}

		ptr = ptr->next;
	}
	if (!found_flag)
	{
		printf("none found\n");
	}
}

int AEROFLOT::get_size()
{
	return size;
}

