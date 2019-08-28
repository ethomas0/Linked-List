#include "stdafx.h"
#include "DblLinkedList.h"
#include <iostream>
#include <string>
using namespace std;


DblLinkedList::DblLinkedList()//1
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

DblLinkedList::~DblLinkedList()//2
{
	Node *curr = head;
	while (curr)
	{
		Node *next = curr->next;
		delete curr;
		--count;
		curr = next;
	}

}

DblLinkedList::DblLinkedList(const DblLinkedList & dll)//3
{
	dll.resetIterator();
	head = nullptr;
	tail = nullptr;
	count = 0;
	resetIterator();

	while (dll.it->next != nullptr)
	{
		push_back(dll.it->data);
		dll.it = dll.it->next;
	}
	push_back(dll.it->data);
	dll.resetIterator();
	
}

void DblLinkedList::push_back(const ETString& str)//4
{
	Node *temp = new Node(str);
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		count++;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		count++;
	}

	
}

void DblLinkedList::resetIterator()const//5
{
	it = head;

}

bool DblLinkedList::insert(const ETString & str)//6
{
	Node *curr;
		
	  // Insertion into an Empty List.
    if(empty())
    {
       Node* temp = new Node(str);
       head = temp;
       tail = temp;
	   count++;
       return true;
    }
	else if (str < head->data)
	{
		
		Node* temp = new Node(str);
		temp->next = head;
		head->prev = temp;
		head = temp;
		count++;
		return true;
	}
	else if (str > tail->data)
	{
		Node* temp = new Node(str);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		count++;
		return true;
	}
	else
	{
		curr = head;
		while (str > curr->data)
		{
			curr = curr->next;
		}

       if(curr->data == str)
       {
		   return false;
       }
	   else
	   {
			Node* temp = new Node(str);
			temp->next = curr;
			temp->prev = curr->prev;
			curr->prev->next = temp;
			curr->prev = temp;			
			count++;
			return true;
	   }
    }
}

bool DblLinkedList::remove(const ETString &str)//7
{
	Node *curr;

	
	for (curr = head; curr != nullptr; curr = curr->next) 
	{

		if (curr->data == str ) 
		{  
			if (curr->prev == nullptr) 
			{ /* Remove from beginning */
											/* Fix beginning pointer. */
				head = curr->next;
				
			}
			else if (curr->next == nullptr)
			{ /* Remove from end */
				curr->prev->next = nullptr;
				tail = curr->prev;
				
			}
			else { /* Remove from middle */
				   /*
				   * Fix previous node's next to
				   * skip over the removed node.
				   */
				curr->prev->next = curr->next;
				
				/*
				* Fix next node's prev to
				* skip over the removed node.
				*/
				curr->next->prev= curr->prev;
				
			}

			delete curr;  /* Deallocate the node. */
			--count;
			return true;   /* Done searching. */
		}
	}

	return false;  /* Not in the list. */
}

const DblLinkedList &DblLinkedList::operator=(const DblLinkedList &dll)//8
{
	Node *curr;
	if (!empty())
	{
		for (curr = head; curr->next != nullptr; curr = curr->next)
		{
			remove(curr->data);
		}
	}
	
	for (curr = dll.head; curr->next != nullptr; curr = curr->next )
	{
		push_back(curr->data);
	}
	push_back(curr->data);
	resetIterator();
	return *this;
}

bool DblLinkedList::hasMore()const//9
{
	if (it != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DblLinkedList::empty() const//10
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ETString DblLinkedList::next()const//11
{
	ETString temp;
	temp = it->data;
	it = it->next;
	return (temp);
}

void DblLinkedList::testConnections()//12
{
	resetIterator();
	while (it !=tail)
	{
		if (it->next->prev != it)
		{
			cout << "FAILED at " << it->data << endl;
			return;
		}
		it = it->next;
	}
	cout << "TEST CONNECTIONS Passed" << endl;
}

int DblLinkedList::getCount()//13
{
	return count;
}

ostream & operator<<(ostream & istr, const DblLinkedList & dll)//14
{
	Node *curr;
	for (curr = dll.head; curr->next != nullptr; curr = curr->next)
	{
		istr << curr->data << " ";
	}
	istr << curr->data;
	return istr;
}
