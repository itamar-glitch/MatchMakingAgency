/* 
Author: Itamar Azran
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

