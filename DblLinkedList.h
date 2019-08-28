//Name: Ethan Thomas
//Class: CS 132 Section: A

//Functions:
//1. Default constructor
//2. Deconstructor
//3. Copy constructor
//4. Pushes the last string back into the stream
//5. Resets the iterator
//6. Inserts a word based on size and will only 
//   allow one of the same word in the list
//7. Removes a string based on the input
//8. Assigment operator
//9. Will check if there is more data in the list
//10. Checks if list is empty
//11. Returns the string and moves the iterator
//12. Makes sure the list's connections are all set
//13. returns lists count
//14. Write operator
//15. Constructor


#ifndef DblLinkedList_H
#define DblLinkedList_H
#include "stdafx.h"
#include <string>
#include "ETString.h"
using namespace std;

class Node
{
public:
	Node()//1
	{
		next = prev = nullptr;
	}
	Node(ETString num)//15
	{
		data = num;
		next = prev = nullptr;
	}
	ETString data;
	Node *next;
	Node *prev;
};


class DblLinkedList
{
public:
	DblLinkedList();//1
	~DblLinkedList();//2
	DblLinkedList(const DblLinkedList& dll);//3
	const DblLinkedList& operator=(const DblLinkedList& dll);//8
	void resetIterator()const;//5
	void testConnections();//12
	bool insert(const ETString &str);//6
	bool remove(const ETString& str);//7
	bool hasMore()const;//9
	bool empty()const;//10
	ETString next()const;//11
	int getCount();//13
	friend ostream & operator<<(ostream &istr, const DblLinkedList &dll);//14

private:
	void push_back(const ETString& str);//4
	Node *head, *tail;
	mutable Node *it;
	int count;
};


#endif // !DblLinkedList_H

