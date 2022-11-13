#include "stdio.h"
#include"string.h"
#include "iostream"

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

	friend std::istream& operator>>(std::istream &in,  FLIGHT& ptr)
	{
		std::cout << "enter flight number: ";
		in >> ptr.number;
		std::cout << "enter destitation name: ";
		in >> ptr.destination_name;
		std::cout << "enter plane type: ";
		in >> ptr.plane_type;
	}


};

class AEROFLOT
{
	FLIGHT* HEAD;
	FLIGHT* LAST;
	int size;

public:

	void add(int i);
	void edit(int i);
	void remove(int i);


	void sort();

	void print_all()
	{
		FLIGHT* ptr = HEAD;
		while (ptr != NULL)
		{
			
			std::cout << ptr;
			std::cout << std::endl;


			ptr = ptr->next;
		}
	}

	void find_by_dest();


};
