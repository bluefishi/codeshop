/*
ID: zixiaoj1 
LANG: C++
TASK: gift1
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;

int main()
{
	ifstream fpin("gift1.in");
	ofstream fpout("gift1.out");
	string owner;
	map<string, int> allFriends;
	string friendList[10];
	int left[10];
	for(int i = 0; i < 10; ++i)
	  left[i] = 0;
	int fn = 0;
	int badget;
	int bn;
	string giftto;
	string fname;
	fpin>>fn;
	for(int i = 0; i < fn; ++i)
	{
		fpin>>fname;
		allFriends[fname] = i;
		friendList[i] = fname;
	}
	for(int i = 0; i < fn; ++i)
	{
		fpin>>owner;
		fpin>>badget>>bn;
		left[allFriends[owner]] -= badget;
		if(badget > 0)
		{
			for(int j = 0; j < bn; ++j)
			{
				fpin>>giftto;
				left[allFriends[giftto]] += badget / bn;
			}
			if(bn > 0)
				left[allFriends[owner]] += badget % bn;
			else
				left[allFriends[owner]] += badget;
		}
		else
		{
			for(int j = 0; j < bn; ++j)
				fpin>>giftto;
		}
	}
	for(int i = 0; i < fn; ++i)
		fpout<<friendList[i]<<" "<<left[i]<<endl;
	fpout.close();
	fpin.close();
	return 0;
}

