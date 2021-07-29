/* 
Author: Itamar Azran
*/
#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include "String.h"
#include "Client.h"
class MatchMakingAgency
{
public:
	MatchMakingAgency();
	~MatchMakingAgency() {};
	void operator =(const MatchMakingAgency& str);//overloading of operator =
	bool operator +=(const Client& str);//overloading of operator +=
	bool operator -=(const Client& str);//overloading of operator +=
	void operator <<(const MatchMakingAgency& new_client);
	//friend std::ostream& operator<<(std::ostream &out, const MatchMakingAgency& new_client);
	void matches(char ID[]);
	Client findclient2(int index);
	int findclient(char ID[]);
private:
	int clientnum;
	vector<Client> clientslist;
};
