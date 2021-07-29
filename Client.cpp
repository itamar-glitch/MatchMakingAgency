/* Assignment C++: 2
Author: Itamar Azran, ID: 307955450
Author: yevgeniy Gluhoy, ID: 336423629
*/
#include "Client.h"
#pragma warning(disable : 4996)
Client::Client(const String& id, const String& name,char gender, double age, int NumHobbies, char** new_hobbies) {
	this->gender = gender;
	this->age = age;
	this->NumHobbies = NumHobbies;
	this->ID=id;
	this->FullName=name;
	insert_hobbies(new_hobbies);//coping the list of hobbies
}
//------------------------------------------------------------------------------------------------------------------
bool Client::operator ==(Client new_client) {
	bool same_hoobies;
	double a = this->age - new_client.age;//check the difference between two ages
	if (a < 0) {//case when result is negative
		a = -1 * a;
	}
	if (this->NumHobbies>= new_client.NumHobbies) {//check the lenght of two hobbies lists
		same_hoobies = this->similiar_hobbies(new_client.hobbies, new_client.NumHobbies);//check similar hobbies
	}
	else {
		same_hoobies = new_client.similiar_hobbies(this->hobbies, this->NumHobbies);//check similar hobbies
	}
	if ((same_hoobies) && (a<5) && (this->gender != new_client.gender)) {//check if all conditions is True
		return true;
	}
	else {
		return false;
	}
}
//------------------------------------------------------------------------------------------------------------------
void Client:: operator= (const Client& new_Client) {//CCtor
	this->ID = new_Client.ID;//insert new string type id 
	this->FullName = new_Client.FullName;
	gender = new_Client.gender;
	age = new_Client.age;
	NumHobbies = new_Client.NumHobbies;
	insert_hobbies(new_Client.hobbies);
}
//------------------------------------------------------------------------------------------------------------------
void Client:: insert_hobbies(char** new_hobbies) {
	int num;
	int index;
	index = 0;
	num = this->NumHobbies;
	this->hobbies = new char* [this->NumHobbies];//making char* array (nre pointer for ich hobbies)
	while (num != 0) {//number of hobbies
		this->hobbies[index] = new char[strlen(new_hobbies[index]) + 1];//making a place for new char(hobbie name)
		strcpy(this->hobbies[index], new_hobbies[index]);//copy the name no old pointers
		num--;
		index++;
	}
}
//------------------------------------------------------------------------------------------------------------------
void Client::release() {//relaese all hobbies list memory
	if (this->hobbies != nullptr) {
		for (int i = 0; i < NumHobbies; i++) {
			delete[] this->hobbies[i];
		}
		delete[] this->hobbies;
	}
	return;
}
//------------------------------------------------------------------------------------------------------------------
bool Client::similiar_hobbies(char** less_hobbies,int num_les_h) {//chec if ther is at least one similar hobbie
	int num_max = this->NumHobbies;
	int index_max=0, index_less = 0;
	int num_max_hobbies = this->NumHobbies;
	while (num_max != 0) {
		int num = num_les_h;
		index_less = 0;
		while (num!=0){
			if (strcmp(this->hobbies[index_max],less_hobbies[index_less])==0) {//"The char's that you compared match!"
				return true;
			}
			else {//"The char's that you compared DON'T match"
				index_less++;
				num--;
			}
		}
		num_max--;
		index_max++;
	}
	return false;
}
//------------------------------------------------------------------------------------------------------------------