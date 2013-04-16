/*
ID: zixiaoj1 
LANG: C++
TASK: friday
*/
#include<iostream>
#include<fstream>
using namespace std;
inline int LeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int main()
{
	ifstream fpin("friday.in");
	ofstream fpout("friday.out");
	int month[][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	int thirtheenth[7];
	for(int i = 0; i < 7; ++i)
		thirtheenth[i] = 0;
	int startYear = 1900;
	int startDay = 0;
	int years = 0;
	fpin>>years;
	int leap = 0;
	for(int i = 0; i < years; ++i)
	{
		leap = LeapYear(startYear + i);
		for(int j = 0; j < 12; ++j)
		{
			thirtheenth[(startDay + 13) % 7] += 1;
			startDay += month[leap][j];
			startDay %= 7;
		}
	}
	int ps = 6;
	for(int i = 0; i < 6; ++i)
	{
		fpout<<thirtheenth[(ps + i) % 7]<<" ";
	}
	fpout<<thirtheenth[5]<<endl;
	fpin.close();
	fpout.close();
	return 0;
}


