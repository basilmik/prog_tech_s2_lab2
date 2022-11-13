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
		std::cout << "enter flight number: " << endl;
		in >> ptr.number;
		in.ignore();

		std::cout << "enter destitation name: ";
		getline(in, ptr.destination_name);
		

		std::cout << "enter plane type: ";
		in.ignore();

		getline(in, ptr.plane_type);
		in.sync();
		return in;
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
			return nullptr;

		int count = 0;
		FLIGHT* ptr = HEAD;
		while (count != i)
		{
			ptr = ptr->next;
			count++;
		}
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
		prev_ptr->next = add_obj;
		add_obj->next = next_ptr;
		size++;
	}

	void edit(int i);
	void remove(int i);


	void sort();

	void print_all()
	{
		FLIGHT* ptr = HEAD;
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
