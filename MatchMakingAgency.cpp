/* 
Author: Itamar Azran
*/
#include "MatchMakingAgency.h"
MatchMakingAgency::MatchMakingAgency() {
	clientnum = 0;
	clientslist.clear();
}
//-------------------------------------------------------------------------------------------------------------
bool MatchMakingAgency::operator +=(const Client& str) {//will add new client to database
	if (clientslist.size() == 0) {
		clientslist.push_back(str);//client is new, add him to vector of clients
		clientnum++;//increse number of clients in database by 1
		return true;
	}
	for (int i = 0; i < clientslist.size(); i++) {//check if new client is alredy in database
		if (clientslist[i].ID == str.ID) {//client is alredy in database, dont need to add him
			return false;
		}
		continue;
	}
	clientslist.push_back(str);//client is new, add him to vector of clients
	clientnum++;//increse number of clients in database by 1
	return true;
}
//-------------------------------------------------------------------------------------------------------------
bool MatchMakingAgency::operator -=(const Client& str) {//will delete client from database
	if (clientslist.size() == 0) {
		return false;//client is not in database
	}
	for (int i = 0; i < clientslist.size(); i++) {//check if client is not in database
		if (clientslist[i].ID == str.ID) {//?????????????????????????????????????????????????????????????????????????????
			clientslist.erase(clientslist.begin() + i);//delete client from database
			clientnum--;//decrease number of clients in database by 1
			return true;
		}
		continue;
	}
	return false;//client is not in database
}
//-------------------------------------------------------------------------------------------------------------
void MatchMakingAgency::operator =(const MatchMakingAgency& str) {
	clientnum = str.clientnum;
	clientslist = str.clientslist;
}
//-------------------------------------------------------------------------------------------------------------
void MatchMakingAgency::matches(char ID[]) {
	int index,matchcounter=0;
	index=findclient(ID);//index of chosen client
	if (index == 0) {//there is no such client!!
		cout << endl << "There is no registered client with chosen ID";
	}
	index--;
	for (int i = 0; i < clientslist.size(); i++) {
		if (i == index) {//dont need to check match to himself
			continue;
		}
		else if (clientslist[index] == clientslist[i]) {
			matchcounter++;
			cout << endl << "Full Name: ";
			clientslist[i].FullName.operator<<(clientslist[i].FullName);
			cout << endl << "ID: ";
			clientslist[i].ID.operator<<(clientslist[i].ID);
			cout << endl << "Gender: " << clientslist[i].gender;
			cout << endl << "Age: " << clientslist[i].age << endl << "Number of hobbies: " << clientslist[i].NumHobbies << endl << "List of hobbies: ";
			for (int j = 0; j != clientslist[i].NumHobbies; j++) {
				cout << clientslist[i].hobbies[j];
				if (j != clientslist[i].NumHobbies - 1) {
					cout << ", ";
				}
			}
			cout << endl << "----------------------------------------------------------";
			continue;
		}
	}
	cout << endl << "==========================================================";
	cout << endl << "//////////////////////////////////////////////////////////";
}
//-------------------------------------------------------------------------------------------------------------
Client MatchMakingAgency::findclient2(int index) {
	return clientslist[index];
}
//-------------------------------------------------------------------------------------------------------------
int MatchMakingAgency::findclient(char ID[]) {//find the needed client
	String SID(ID);
	for (int i = 0; i < clientslist.size(); i++) {//search client in database
		if (SID == clientslist[i].ID) {//client was found	
		      return i+1;
		}

	}
	return 0;//client with chosen ID isnt registered in database
}
//------------------------------------------------------------------------------------------------------------------
void MatchMakingAgency:: operator <<(const MatchMakingAgency& new_client) {
	if (this->clientnum == 0) {
		cout << endl << "No clients in database" ;
		cout << endl << "==========================================================";
		cout << endl << "//////////////////////////////////////////////////////////";
	}
	else {
		int i = 0,j=0;
		while (i != this->clientnum) {
			cout << endl << "Full Name: ";
			this->clientslist[i].FullName.operator<<(this->clientslist[i].FullName);
			cout << endl << "ID: ";
			clientslist[i].ID.operator<<(clientslist[i].ID);
			cout << endl << "Gender: " << this->clientslist[i].gender;
			cout<<endl<<"Age: "<<this->clientslist[i].age << endl << "Number of hobbies: " << clientslist[i].NumHobbies << endl << "List of hobbies: ";
			for(j=0; j != this->clientslist[i].NumHobbies;j++) {
				cout << this->clientslist[i].hobbies[j];
				if (j != this->clientslist[i].NumHobbies - 1) {
					cout<< ", ";
				}
			}
			cout << endl << "----------------------------------------------------------";
			i++;
		}
		cout << endl << "There are " << clientnum << " clients registered in database.";
		cout << endl << "==========================================================";
		cout << endl << "//////////////////////////////////////////////////////////";
	}
}
//-------------------------------------------------------------------------------------------------------------------
