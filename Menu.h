/* Assignment C++: 2
Author: Itamar Azran, ID: 307955450
Author: yevgeniy Gluhoy, ID: 336423629
*/
#pragma once
#include "MatchMakingAgency.h"
class Menu
{
public:
	Menu();//default Ctor
	~Menu() {}//Dtor
	int MainMenu();
private:
	void clean_buff();//clean the buffer
	MatchMakingAgency MatchMakingAgencyData;
};

