#include<iostream>
#include<fstream>
#include<sstream>

int getdata()
{
	int r;
	ifstream f;
	f.open("data");
	f>>r;
	f.close();
	ofstream fo;
	fo.open("data");
	fo>>r+1;
	fo.close();
	return r;
}

string newaudio()
{
	string fname;
	ostringstream str1;
	int r=getdata();
	str1<<"RecordingModule.exe 3 "<<r<<".wav "<<r<<".txt";
	fname=str1.str();
	
	return fname;
}