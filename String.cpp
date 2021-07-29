/* 
Author: Itamar Azran
*/
#include "String.h"
#pragma warning(disable : 4996)
String::String(){}//default Ctor
//------------------------------------------------------------------------------------------------------------------
String:: ~String() {//Dtor
	delete[] fullname;
}
//-----------------------------------------------------------------------------------------------------
String::String(char* newname) {//custom Ctor
	spacedelete(newname);
}
//-----------------------------------------------------------------------------------------------------  
void String::operator= (const String& str) {
	fullname = new char[strlen(str.fullname) + 1];//allocating memory
	strcpy(fullname, str.fullname);//copies the string
}
//-----------------------------------------------------------------------------------------------------  
bool String:: operator ==(const String& str) {
	if (strlen(str.fullname) != strlen(fullname)) {//if lengh of two names isn's same, return false
		return false;
	}
	for (int index = 0; index < strlen(str.fullname); index++) {//matching all chars in two names
		if (fullname[index] != str.fullname[index]) {
			return false;
		}
	}
	return true;
}
//-----------------------------------------------------------------------------------------------------  
void String::operator << (const String& str) {
	cout << str.fullname;
	return;
}
//-----------------------------------------------------------------------------------------------------  
void String::spacedelete(char* newname){
	int i = 0,j=0, charcounter=0;
	for (i = 0; i <= strlen(newname); i++) {//loop counts number of chars in string without spaces
		if ((int)newname[i] == 32) {//skip spaces
			continue;
		}
		charcounter++;
	}
	String::fullname = new char[charcounter];//allocating memory in object for the new client's name according to charcounter + space between the words+'/n' in end of array
	for (i = 0; i < strlen(newname); i++) {
		if ((j == 0 || j==charcounter) && newname[i] == 32) {
			continue;
		}
		else if ((int)fullname[j - 1] == 32 && (int)newname[i] == 32) {
			continue;
		}
		fullname[j] = newname[i];//copy the values
		j++;//j is the index only in object's array
	}
	fullname[j] = 0;//add '/n' in the end of array
}
//-----------------------------------------------------------------------------------------------------
