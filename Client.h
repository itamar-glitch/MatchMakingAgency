/* Assignment C++: 2
Author: Itamar Azran, ID: 307955450
Author: yevgeniy Gluhoy, ID: 336423629
*/
#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include "String.h"
#pragma warning(disable : 4996)
using namespace std;
class Client
{
public:
	Client() {};//default Ctor
	virtual ~Client() {//Dtor
		release();
	}
	Client(const String& id,const String& name,char gender, double age, int NumHobbies, char** hobbies);//custom Ctor
	Client(const Client& new_client) {//Cctor
		gender = new_client.gender;
		age = new_client.age;
		NumHobbies = new_client.NumHobbies;
		this->ID = new_client.ID;
		this->FullName = new_client.FullName;
		insert_hobbies(new_client.hobbies);
	}//CCtor
    bool operator ==(Client new_client);//overloading of operator ==
    void operator =(const Client& new_client);//overloading of operator =
private:
	String ID;
	String FullName;
	char gender;
	double age;
	int NumHobbies;//number of hobbies
	char** hobbies;//pointer to list of hobbies
	friend class MatchMakingAgency;
	void insert_hobbies(char** new_hobbies);
	void release();
	bool similiar_hobbies(char** less_hobbies, int num_les_h);
};
