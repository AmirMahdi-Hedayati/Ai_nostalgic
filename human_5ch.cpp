/* IN THE NAME OF GOD */

#include <bits/stdc++.h>

using namespace std;

string ramz = "DJCF";

string pop[5];

bool finish = true ;


void get_pop()
{
	for(int i = 0; i < 5; i++)	cin >> pop[i];
}


void check()
{
	int ans;
	
	for(int i = 0; i < 5; i++)
	{
		ans = 0;
		
		for(int j = 0; j < 4; j++)
		if(pop[i].at(j) == ramz.at(j)) ans++;
		
		cout << ans << " ";
		
		if(ans == 4) finish = false;
	}
	
	cout << endl;
}
int main()
{
	srand(time(NULL));
	
	for(int i = 0; i < 4; i++)
	ramz.push_back('A' + (rand() % 26));
	
	while(finish)
	{
		
		get_pop();
		
		check();
		
	}
	
	cout << "exellent!" ;
	
	cin.get();
	cin.get();
	
	return 0;
}