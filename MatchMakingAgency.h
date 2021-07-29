/* Assignment C++: 2
Author: Itamar Azran, ID: 307955450
Author: yevgeniy Gluhoy, ID: 336423629
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