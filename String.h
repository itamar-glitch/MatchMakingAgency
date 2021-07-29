/* Assignment C++: 2
Author: Itamar Azran, ID: 307955450
Author: yevgeniy Gluhoy, ID: 336423629
*/
#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
class String
{
public:
	String();//default Ctor
	String(char* newname);//custom Ctor
	String(const String& newname) {//Cctor
		fullname = new char[strlen(newname.fullname) + 1];
		fullname = newname.fullname;
	}
	virtual ~String();
	void operator =(const String& str);//overloading of operator =
	bool operator ==(const String& str);//overloading of operator ==
	void operator <<(const String& str);//overloading of operator cout<< 
private:
	char* fullname;
	void spacedelete(char* newname);//delete the spaces before,after and betwen the words
};

