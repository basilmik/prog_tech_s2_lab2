#include "stdio.h"
#include <string>
#include <iostream>

int mscanf(const char* _f, void* _x);


using namespace std;

class FLIGHT
{
	std::string destination_name;
	int number;
	std::string plane_type;

public:
	
	FLIGHT* next;

	FLIGHT();
	~FLIGHT();

	void set_destination_name(std::string _name);
	void set_plane_type(std::string _type);
	void set_number(int _num);

	std::string get_destination_name();
	std::string get_plane_type();
	int get_number();

	friend std::ostream& operator<<(std::ostream& out, const FLIGHT& ptr);
	friend std::istream& operator>>(std::istream& in, FLIGHT& ptr);
	
	void edit();
};

class AEROFLOT
{
	FLIGHT* HEAD;
	FLIGHT* LAST;
	int size;

protected:

	void add_to_end();
	void remove_last();
	void swap(int _idx1, int _idx2);

	FLIGHT* operator[](int i);

public:

	AEROFLOT();
	~AEROFLOT();

	int get_size();

	void add(int i);
	void edit(int i);
	void remove(int i);
	
	void sort();
	void print_all();
	void find_by_dest();	
};
