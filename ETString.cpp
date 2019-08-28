#include "stdafx.h"
#include "ETString.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctype.h>
using namespace std;

int ETString::createdCount = 0;
int ETString::currentCount = 0;
ETString::ETString()
{
	
	capacity = GROWTH;
	strPtr = new char[capacity];
	createdCount++;
	currentCount++;
	strPtr[0] = '\0';
	end = 0;
}

ETString::ETString(const char* init_val)
{
	int i;
	capacity = GROWTH;
	end = 0;
	int capNeeded = 0;
	for (int j = 0; init_val[j] != '\0'; j++)
	{
		capNeeded++;
	}
	while (capacity <= capNeeded)
	{
		capacity += GROWTH;
	}
	strPtr = new char[capacity];
	for (i = 0; init_val[i] != '\0'; i++)
	{
		strPtr[i] = init_val[i];
		end++;
	}
	strPtr[i] = init_val[i];	
	createdCount++;
	currentCount++;
}

ETString::ETString(const ETString & mstr)
{
	strPtr = nullptr;
	assignmentHelper(mstr);
}

ETString::~ETString()
{
	delete [] strPtr;
	currentCount--;	
}


int ETString::compareTo(const ETString &argStr) const
{
	int total;
	int tempSmall = argStr.end;
	if (end < argStr.end)
	{
		tempSmall = end;
	}
	for (int i = 0; i <=tempSmall; i++)
		{
			total = tolower(strPtr[i]) - tolower(argStr.strPtr[i]);
			if (total != 0)
			{
				return total;
			}
		}
	return total;
	}
	


int ETString::length() const 
{
	return end;
}

int ETString::capacityFunc() const
{
	return capacity;
}

char ETString::operator[](int index)const
{
	if(index < 0 || index > end)
	{
		return '\0';
	}
	else
	{
		return strPtr[index];
	}
}

bool ETString::operator>(const ETString & argStr) const
{
	if (compareTo(argStr) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ETString::operator<(const ETString & argStr) const
{
	if (compareTo(argStr) < 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool ETString::operator==(const ETString & argStr) const
{
	if (compareTo(argStr) == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

istream& operator >> (istream &istr, ETString & arg)
{
	int i;
	char temp[100];
	int capNeeded = 0;
	if (istr >> temp)
	{
		for (i = 0; temp[i] != '\0'; i++)
		{
			capNeeded++;
		}
		while (arg.capacity <= capNeeded)
		{
			arg.capacity += ETString::GROWTH;
		}
		if (arg.capacity > ETString::GROWTH)
		{
			delete arg.strPtr;
			arg.strPtr = new char[arg.capacity];
		}

		for (i = 0; temp[i] != '\0'; i++)
			{
				arg.strPtr[i] = temp[i];
				arg.end++;
			}
		arg.strPtr[i] = temp[i];
		arg.end = i;
		if (ispunct(arg.strPtr[i - 1]))
		{
			arg.strPtr[i - 1] = '\0';
			arg.end--;
		}
	}
	return istr;
}

ostream& operator<<(ostream & istr, const ETString & arg)
{	
	for (int i = 0; arg.strPtr[i] != '\0'; i++)
	{
		istr << arg.strPtr[i];
	}
	return istr;
}


ETString ETString::operator+(const ETString & arg)
{
	int newSize = 0;
	int newCap = GROWTH;
	int i = 0;
	int j = 0;
	newSize = length() + arg.length();
	while (newCap <= newSize)
	{
		newCap += GROWTH;
	}
	
	char *newPtr = new char[newCap];
	for (i; strPtr[i] != '\0'; i++)
	{
		newPtr[i] = strPtr[i];
	}
	for (j; arg.strPtr[j] != '\0'; j++, i++)
	{
		newPtr[i] = arg.strPtr[j];
	}
	
	newPtr[i] = '\0';
	ETString temp = newPtr;
	delete[] newPtr;

	return temp.strPtr;
}

const ETString& ETString::operator=(const ETString& argStr)
{
	if (this != &argStr)
	{
		assignmentHelper(argStr);
	}
	return *this;	
}

const char * ETString::c_str()const
{
	return strPtr;
}

int ETString::getCreatedCount()
{
	return createdCount;
}

int ETString::getCurrentCount()
{
	return currentCount;
}

void ETString::assignmentHelper(const ETString &argStr)
{
	delete[] strPtr;
	int i;
	end = argStr.end;
	capacity = argStr.capacity;
	strPtr = new char[capacity];
	for (i = 0; argStr.strPtr[i] != '\0'; i++)
	{
		strPtr[i] = argStr.strPtr[i];
	}
	strPtr[i] = '\0';
}




