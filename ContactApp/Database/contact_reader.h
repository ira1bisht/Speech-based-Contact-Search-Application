#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
ifstream file_pointer;
string contact[1000];


vector<string> read_contact_address(int s){
	vector<string> c;
	for(int i=0;i<500;i++)contact[i]="";//clear array
file_pointer.open("Database\\contact_address.txt",ios::in);
string ss="";
int count=0;
while(count!=s){
file_pointer>>ss;
if(ss.front()=='_')count++;
}//got starting point of contact
file_pointer>>ss;
int i=0;
c.clear();
while(ss.front()!='_'){
	contact[i++]=ss;
	c.push_back(ss);
	file_pointer>>ss;
}
contact[i]="#";//string ends at #
file_pointer.close();
return c;
}