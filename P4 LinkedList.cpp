//Name: Ethan Thomas
//Class: CS 132 Section: A
//Program Description: This program will read
//into two files and then remove words from
//list 1 if list 2 contains the same word and
//vice versa for list 2. It will then output the 
//amount of words left held in the list.

#include "stdafx.h"
#include <iostream>
#include <string>    
#include <fstream>
#include <istream>
#include <iomanip>
#include "Functions.h"
#include "DblLinkedList.h"
using namespace std;
int main()
{
	DblLinkedList list1, list2, modList1, modList2;
	fstream fin;
	ETString temp;

	fin.open("infile1.txt");
	checkRead(fin);

	while (fin >> temp)
	{
		list1.insert(temp);
	}

	fin.close();
	fin.open("infile2.txt");
	checkRead(fin);

	while (fin >> temp)
	{
		list2.insert(temp);
	}
	fin.close();
	
	cout << "The size of list 1 is " << list1.getCount() << endl;
	cout << "The size of list 2 is " << list2.getCount() << endl;
	cout << "The size of mod list 1 is " << modList1.getCount() << endl;
	cout << "The size of mod list 2 is " << modList2.getCount() << endl;

	modList1 = list1;
	modList2 = list2;

	cout << "The size of list 1 is " << list1.getCount() << endl;
	cout << "The size of list 2 is " << list2.getCount() << endl;
	cout << "The size of mod list 1 is " << modList1.getCount() << endl;
	cout << "The size of mod list 2 is " << modList2.getCount() << endl;
	list1.resetIterator();
	list2.resetIterator();
	modList1.resetIterator();
	modList2.resetIterator();

	while (list2.hasMore())
	{
		modList1.remove(list2.next());
	}
	list1.resetIterator();
	list2.resetIterator();
	modList1.resetIterator();
	modList2.resetIterator();
	
	while (list1.hasMore())
	{
		modList2.remove(list1.next());
	}
	list1.resetIterator();
	list2.resetIterator();
	modList1.resetIterator();
	modList2.resetIterator();

	cout << "The size of list 1 is " << list1.getCount() << endl;
	cout << "The size of list 2 is " << list2.getCount() << endl;
	cout << "The size of mod list 1 is " << modList1.getCount() << endl;
	cout << "The size of mod list 2 is " << modList2.getCount() << endl;

	changer(modList1);
	changer(modList2);


	ofstream fout("test1.txt");
	checkWrite(fout);
	fout << modList1;
	fout.close();

	ofstream fout2("test2.txt");
	checkWrite(fout2);
	fout2 << modList2;
	fout2.close();
	
	


	
	
	system("pause");
    return 0;
}

//Output:
//just the lists
//The size of list 1 is 1104
//The size of list 2 is 1040
//The size of mod list 1 is 0
//The size of mod list 2 is 0
//assigning mods to lists
//The size of list 1 is 1104
//The size of list 2 is 1040
//The size of mod list 1 is 1104
//The size of mod list 2 is 1040
//after removal of words
//The size of list 1 is 1104
//The size of list 2 is 1040
//The size of mod list 1 is 759
//The size of mod list 2 is 695
//after added words
//The size of the list is 761
//The size of the list is 697