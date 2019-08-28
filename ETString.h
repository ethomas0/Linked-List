//Name:Ethan Thomas
//Class: CS 132 Section: A
//Description: This is string class that I created.
//the following functions do this:
//1. Default constructor(defaults capacity to 20)
//2. Constructor that takes parameters
//3. Copy Construtor
//4. Deconstructor
//5. Returns end which marks the null pointer on the string
//6. Returns the strings capacity 
//7. Bounds check
//8. Determines if lvalue is greater than rvalue
//9. Determines if lvalue is less than rvalue
//10. Determines if lvalue is equal to rvalue
//11. Read function
//12. Write function
//13. Allows strings to be combined together
//14. Allows str1 = str2
//15. Returns a string pointer
//16. Returns number of instances created
//17. Returns current number of instances 
//18. Helps the equal operator
//19. Returns a difference when two string asci values are compared
#ifndef ETSTRING_H
#define ETSTRING_H
#include <fstream>
#include <iostream>
using namespace std;
class ETString
{
public:
	ETString();//1
	ETString(const char* init_val);//2
	ETString(const ETString &mstr);//3
	~ETString();//4
	int length()const;//5
	int capacityFunc()const;//6
	char operator[](int index)const;//7
	bool operator>(const ETString &argStr)const;//8
	bool operator<(const ETString &argStr)const;//9
	bool operator==(const ETString &argStr)const;//10
friend istream & operator >>(istream &istr, ETString & arg);//11
friend ostream & operator << (ostream &istr, const ETString & arg);//12
ETString operator+(const ETString &arg);//13
	const ETString& operator=(const ETString& argStr);//14
	const char* c_str()const;//15
	static int getCreatedCount();//16
	static int getCurrentCount();//17
	
private:
	void assignmentHelper(const ETString& argStr);//18
	int compareTo(const ETString &argStr) const;//19
	int capacity;
	char *strPtr;
	int end; 
	static int createdCount;
	static int currentCount;
	const static int GROWTH = 20;
};
#endif

