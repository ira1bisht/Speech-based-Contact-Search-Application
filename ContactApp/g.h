#include "stdafx.h"
#include<iostream>

using namespace std;

void demo()
{
	system("explorer");
}

void player()
{
	
	system("/q sounder 194101044_7_15.wav");
}
string getname(int x)
{
	string name[]={"Aman","Chaitra","Divya","Ema","Faizal","Gagan","Ira","Karan","Lilly","Manish","Preet","Rambo","Sahil","Tanvi","Urja","Varun","Yes","No","Hold"};
	return name[x-1];

}