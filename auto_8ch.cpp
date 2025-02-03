/* IN THE NAME OF GOD */

#include <bits/stdc++.h>

using namespace std;

string pop[8]; // save the strings

int ans[8]; // save the answers of user

int poss[8][27]; // save possibility of each character in each place 

int swi = 0 ;

//get the first values of array poss
void reset_poss()
{
	for(int i = 0 ; i < 8 ; i++)
	{
		poss[i][26] = 20800 ;
		
		for (int j = 0; j < 26; j++) poss[i][j] = 800;
	}	
}



// save values in array poss
void char_poss()
{
	for(int i = 0; i < 8; i++)
	{
		
		for(int j = 0; j < 8; j++)
		{
			
		poss[j][(pop[i].at(j)) - 'A'] += ( ans[i] * ans [i] ) /2  ;
		
		poss[j][26] += (ans[i] * ans[i]) / 2 ;
		
		}
		
	}	
}



// percent rand
bool p_rand(int p)
{
	if ((rand() % 100) < p ) return true;
	else return false;
}


// out the random char by getting data from array poss
char crand(int  n)
{
	int sum = poss[n][26];
	
	for(int i = 0 ; i < 26 ; i++)
	{
		if(rand() % sum < poss[n][i]) return ('A' + i) ;
		else sum -= poss[n][i];
	}
	
	return 'a';
}



// making a random string and return it
string strand()
{
	string s = "";
	
	for(int i = 0; i < 8; i++)
	{
		int x = rand();
		char ch = 'A' + x % 26;
		s.push_back(ch);
	}
	
	return s;
}



// making a random string from string g by changing n character of g the return it
string jahesh(string g , int n)
{
	int i;
	char ch;
	
	string o = g;
	
	while(n--)
	{
		i = rand() % 8;
		
		ch = g.at(i) + rand() % 25 + 1;
		if(ch > 'Z') ch = ch - 'Z' - 1 + 'A' ;
		
		o.erase(i , 1);
		o.insert(i , 1 , ch);
	}
	
	return o;
}



// making a random string with combination of tow string g1 & g2 then return it
string edgham(string g1 , string g2 )
{
	string o;

	for(int i = 0; i < 8; i++)
	{
		if(p_rand(1)) o.push_back(rand() % 26 + 'A');
		else if(p_rand(7))  o.push_back (crand(i));
		else if( (g1.at(i)) != (g2.at(i)) && p_rand(70 - 50 * swi) ) o.push_back (crand(i));
		else if(p_rand(60)) o.push_back (g1.at(i));
		else o.push_back (g2.at(i));
		
	}
	
	return o;
}



// make 8 random string , put them in array pop and print them
void eight_strand ()
{
	for(int i = 0; i < 8; i++)
	{
		pop[i] = strand();
		cout << pop[i] << "\n";
	}
}



// make 8 random string by combination of g1 & g2 , put them in array pop and print them
void eight_edgham(string g1 , string g2 )
{
	for(int i = 0; i < 8; i++)
	{
		pop[i] = edgham(g1 , g2);
		cout << pop[i] << "\n";
	}
}



// make 8 random better string by changing n letters og g1
void eight_jahesh(string g1 , int n)
{
	for(int i = 0; i < 8; i++)
	{
		pop[i] = jahesh(g1 , n);
		cout << pop[i] << "\n";
	}
}


  
// check the answers like a user
void check()
{
	string ramz = "AMIRMAHD" ;
	int an;
	
	cout << "\n";
	for (int i = 0; i < 8 ; i++)
	{
		an = 0;
		
		for(int j = 0; j < 8; j++)
		if (pop[i].at(j) == ramz.at(j)) an++;
		
		ans[i] = an;
		
		cout << an << "  ";
	}
	
	cout << "\n";
	cout << "\n";
}


// check to finish program
bool finish()
{
	for(int i = 0 ; i < 8; i++) 
	if(ans[i] == 8) return false;
	
	return true;
}
// the main function
int main()
{
	string s;
	int mx1 , mx2;
	string g1 , g2 ;
	int t = 0;
	
	srand(time(NULL));
	reset_poss();
	
	eight_strand();
	
	check();
	t++;
	cout << t << "\n \n";	
	while(finish())
	{
		mx1 = 0;
		mx2 = 0;
		
		g1 = "";
		g2 = "";
		
		char_poss();
		
		for(int i = 0; i < 8; i++) // finding first and second maximom answers of user (mx1,mx2) and find the best strings to make next generation
		{
			if (ans[i] > mx1)
			{
				mx2 = mx1;
				g2 = g1;
				mx1 = ans[i];
				g1 = pop[i];
			}
			else if(ans[i] > mx2)
			{
				mx2 = ans[i];
				g2 = pop[i];
			}
		}
		
		if(mx1 == 0) eight_strand();
		else if((mx1 - mx2) < 2 && mx2 != 0) eight_edgham(g1 , g2 );
		else eight_jahesh(g1 , (8 - mx1) / 2);
		
		check();
		
		t++;
		
		cout << t << "\n \n";
		
		swi = 0;
		for(int i = 0; i < 8; i++) if(ans[i] == 7) swi = 1;
	}
	
	return t;
}



