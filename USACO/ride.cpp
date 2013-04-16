/*
ID: zixiaoj1 
LANG: C++
TASK: ride
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fpin("ride.in");
	ofstream fpout("ride.out");
	string comet;
	string group;
	fpin>>comet>>group;
	unsigned int cv = 1;
	unsigned int gv = 1;
	for(string::iterator it = comet.begin(); it != comet.end(); ++it)
	{
		cv *= (*it) - 'A' + 1;
		cv %= 47;
	}
	for(string::iterator it = group.begin(); it != group.end(); ++it)
	{
		gv *= (*it) - 'A' + 1;
		gv %= 47;
	}
	if(cv == gv)
		fpout<<"GO"<<endl;
	else
		fpout<<"STAY"<<endl;
	fpout.close();
	fpin.close();
	return 0;
}

