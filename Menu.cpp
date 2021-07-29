/* Assignment C++: 2
Author: Itamar Azran, ID: 307955450
Author: yevgeniy Gluhoy, ID: 336423629
*/
#include<vector>
#include <iostream>
#include "Menu.h"
using namespace std;
//-------------------------------------------------------------------------------------------------------------------------
Menu::Menu() {};
//-------------------------------------------------------------------------------------------------------------------------
int Menu::MainMenu() {
	int department_choise,hobbiesnum,index,counter=0;
	vector<char> newname;
	vector<char> newhobby;
	vector<char*> hobbies;
	Client delcl;
	char newinput,newgender;
	double newage;
	do {
		cout << endl << "Please choose one of the following options:" << endl;
		cout << "==========================================================" << endl;
		cout << "1) Add a new client to the database." << endl << "2) Remove an existing client from the database." << endl; 
		cout << "3) Print all clients." << endl << "4) Print all matches for a client." << endl<<"5) Quit the program."<<endl;
		cout << "==========================================================" << endl;
		clean_buff();
		cin >> department_choise;
		switch (department_choise) {
		case 1: {
			cout << "Please, enter the ID of a new client and press 'Enter': ";
			cin >> noskipws;//cin will not skip the spaces
			newname.clear();
			clean_buff();
			while (cin >> newinput) {//take char by char and saving them into vector until input '0' 'Enter' 
				if ((int)newinput == '\n') {
					break;
				}
				newname.push_back(newinput);//pushing chars into vector
			}
			for (int i = 0; i <= newname.size(); i++) {
				counter++;
			}
			char* IDarr = new char[counter];//allocating memory for array
			counter = 0;
			for (int i = 0; i < newname.size(); i++) {//copy vector to array
				IDarr[i] = newname[i];
			}
			IDarr[newname.size()] = 0;//end of array
			String newID(IDarr);//new object ID, type String
			newname.clear();//clean the vetor befor new use
			cout << endl << "Please, enter the full name of a new client and press 'Enter': ";
			clean_buff();
			while (cin >> newinput) {//take char by char and saving them into vector until input  'Enter' 
				if ((int)newinput == '\n') {
					break;
				}
				newname.push_back(newinput);//pushing chars into vector
			}
			for (int i = 0; i <= newname.size(); i++) {
				counter++;
			}
			char* Namearr = new char[counter];//allocating memory for array
			counter = 0;
			for (int i = 0; i < newname.size(); i++) {//copy vector to array
				Namearr[i] = newname[i];
			}
			Namearr[newname.size()] = 0;//end of array
			String Name(Namearr);//create the object Full name type String
			cout << endl << "Please, enter gender of a new client ('M' - for male, 'F' - for female) and press 'Enter': ";
			clean_buff();
			cin >> newgender;
			if ((int)newgender == 'm') {
				newgender = 'M';
			}
			else if ((int)newgender == 'f') {
				newgender = 'F';
			}
			cout << endl << "Please, enter the age of a new client (18 at least) and press 'Enter': ";
			clean_buff();
			cin >> newage;
			if (newage < 18) {
				cout << endl << "Can not register the client. Client must be at least 18 years old.";
				break;
			}
			cout << endl << "Please, enter the number of hobbies of a new client and press 'Enter': ";
			clean_buff();
			cin >> hobbiesnum;
			for (int i = 0; i < hobbiesnum; i++) {
				cout << endl << "Please, enter hobby number "<<i+1<<" and press 'Enter': ";
				clean_buff();
				while (cin >> newinput) {//take char by char and saving them into vector until input  'Enter' 
					if ((int)newinput == '\n') {
						break;
					}
					if ((int)newinput >= 65 && (int)newinput <= 90) {
						newhobby.push_back(newinput+32);
					}
					else {
						newhobby.push_back(newinput);//pushing chars into vector
					}
				}
				for (int i = 0; i <= newhobby.size(); i++) {
					counter++;
				}
				char* arrhobby = new char[counter];//allocating memory for array
				counter = 0;
				for (int j = 0; j < newhobby.size(); j++) {//copy vector to array
					arrhobby[j] = newhobby[j];
				}
				arrhobby[newhobby.size()] = 0;//end of array
				newhobby.clear();
				hobbies.push_back(arrhobby);//push the array to vector of all hobbies
			}
			for (int i = 0; i <= hobbies.size(); i++) {
				counter++;
			}
			char** arrhobbies = new char*[counter-1];
			counter = 0;
			for (int j = 0; j < hobbies.size(); j++) {//copy vector of all hobbies to array
				arrhobbies[j] = hobbies[j];
			}
			hobbies.clear();
			Client NewClient(newID, Name, newgender, newage, hobbiesnum, arrhobbies);//Ctor
			this->MatchMakingAgencyData.operator+=(NewClient);
			break;
		}
		case 2: {
			cout << endl << "Enter the ID of client you want to remove and press 'Enter': ";
			newname.clear();
			clean_buff();
			while (cin >> newinput) {//take char by char and saving them into vector until input '0' 'Enter' 
				if ((int)newinput == '\n') {
					break;
				}
				newname.push_back(newinput);//pushing chars into vector
			}
			for (int i = 0; i <= newname.size(); i++) {
				counter++;
			}
			char* IDarr = new char[counter];//allocating memory for array
			
			for (int i = 0; i < newname.size(); i++) {//copy vector to array
				IDarr[i] = newname[i];
			}
			IDarr[counter-1] = 0;//end of array
			counter = 0;
			index= this->MatchMakingAgencyData.findclient(IDarr);
			if (index == 0) {
				cout << endl << "Client with chosen ID isn't registered in database.";
			}
			else {
				delcl = this->MatchMakingAgencyData.findclient2(index-1);
				this->MatchMakingAgencyData.operator-=(delcl);
			}
			break;
		}
		case 3: {
			this->MatchMakingAgencyData.operator<<(this->MatchMakingAgencyData);
			break;
		}
		case 4: {
			cout << endl << "Enter the ID of client and press 'Enter': ";
			newname.clear();
			clean_buff();
			while (cin >> newinput) {//take char by char and saving them into vector until input '0' 'Enter' 
				if ((int)newinput == '\n') {
					break;
				}
				newname.push_back(newinput);//pushing chars into vector
			}
			char* IDarr = new char[newname.size() + 1];//allocating memory for array
			for (int i = 0; i < newname.size(); i++) {//copy vector to array
				IDarr[i] = newname[i];
			}
			IDarr[newname.size()] = 0;//end of array
			this->MatchMakingAgencyData.matches(IDarr);
			break;
		}
		case 5: {
			break;
		}
		}
		if (department_choise != 5) {
			printf("\n");
		}
	} while (department_choise != 5);
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Menu::clean_buff() {
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------