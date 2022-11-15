#include "stdio.h"
#include "fstream"
#include "iostream"
#include <string>

bool is_a_vowel(char _ch)
{
	return _ch == 'a' || _ch == 'A' || _ch == 'e' || _ch == 'E' 
		|| _ch == 'i' || _ch == 'I' || _ch == 'o' || _ch == 'O'
		|| _ch == 'u' || _ch == 'U' ;
}

bool is_a_devider(char _ch)
{
	return (_ch < 65 || (_ch >= 91 && _ch <= 96) || _ch >= 123);
}


int main()
{
	std::ifstream fin;
	fin.open("file.txt");
	if (!fin.is_open())
	{
		printf("could not open file\n");
		return 0;
	}

	char ch;
	bool print_flag = true;
	while (!fin.eof())
	{
		fin.get(ch);

		if (!is_a_devider(ch))
		{
			if (is_a_vowel(ch))
				print_flag = true;
			else
				print_flag = false;

			if (print_flag)
			{
				printf("word: ");
				std::cout << ch;
			}

			while (!fin.eof() && !is_a_devider(ch))
			{
				fin.get(ch);
				if (print_flag && !is_a_devider(ch)) 
					std::cout << ch;
			}

			if (print_flag) 
				printf("\n");
		}

	}

	fin.close();

	return 0;
}