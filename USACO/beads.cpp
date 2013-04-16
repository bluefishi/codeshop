/*
ID: zixiaoj1 
LANG: C++
TASK: beads
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream fpin("beads.in");
	ofstream fpout("beads.out");
	string necklace;
	int n;
	fpin>>n;
	fpin>>necklace;
	int max = 0;
	int lb;
	int rb;
	int cur = 0;
	char color;
	int j;
	for(int i = 1; i <= n; ++i)
	{
	  cur = 0;
	  lb = i - 1;
	  rb = i;
	  rb %= n;
	  for(j = 0; j < n; ++j)
	  {
		  if(necklace[rb] == 'w')
		  {
			  cur += 1;
			  rb += 1;
			  rb %= n;
		  }
		  else
		  {
			  color = necklace[rb];
			  break;
		  }
	  }
		  
	  for(; j < n; ++j)
	  {
		if(necklace[rb] != color && necklace[rb] != 'w')
			break;
		cur += 1;
		rb += 1;
		rb %= n;
	  }
	  rb -= 1;
	  if(rb < 0)
		  rb += n;
	  while(lb != rb)
	  {
		  if(necklace[lb] == 'w')
		  {
			  cur += 1;
			  lb -= 1;
			  if(lb < 0)
				  lb += n;
		  }
		  else
		  {
			  color = necklace[lb];
			  break;
		  }
	  }
	  while(lb != rb) 
	  {
		  if(necklace[lb] != color && necklace[lb] != 'w')
			  break;
		  cur += 1;
		  lb -= 1;
		  if(lb < 0)
			  lb += n;
	  }
	  if(cur > max)
		  max = cur;
	}
	fpout<<max<<endl;
	//cout<<max<<endl;
	fpin.close();
	fpout.close();
	return 0;
}

