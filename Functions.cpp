//Functions:
//1. checks if read is connected
//2. checks if write is connected
//3. sorts words alphabetically
//4. Checks copy constructor
#include "stdafx.h"
#include "ETString.h"
#include "Functions.h"
#include "DblLinkedList.h"
#include <vector>
#include <fstream>
#include<ostream>
#include <iomanip>
using namespace std;




void checkRead(fstream & istr)
{
	if (istr.fail())
	{
		cout << "Unable to find the output file." << endl;
		system("pause");
		exit(1);
	}
}

void checkWrite(ofstream & istr)
{
	if (istr.fail())
	{
		cout << "Unable to find the output file." << endl;
		system("pause");
		exit(1);
	}
}


void sort(fstream & istr, vector<ETString>&vector_of_char_str)
{
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < vector_of_char_str.size() - 1; i++)
		{
			if (vector_of_char_str[i + 1] < vector_of_char_str[i])
			{
				ETString temp;
				swapped = true;
				temp = vector_of_char_str[i + 1];
				vector_of_char_str[i + 1] = vector_of_char_str[i];
				vector_of_char_str[i] = temp;
			}
		}
	}
}

void changer(DblLinkedList dll)
{
	dll.insert("ZIP");
	dll.insert("ZAP");
	cout << "The size of the list is " << dll.getCount() << endl;
	

}
