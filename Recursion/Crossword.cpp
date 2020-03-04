#include <bits/stdc++.h>
using namespace std;
/*
//Input
+-++++++++ 
+-++++++++
+-++++++++
+-----++++
+-+++-++++
+-+++-++++
+++++-++++
++------++
+++++-++++					
+++++-++++						
LONDON;DELHI;ICELAND;ANKARA     

+L++++++++  //Output
+O++++++++
+N++++++++
+DELHI++++
+O+++C++++
+N+++E++++
+++++L++++
++ANKARA++
+++++N++++
+++++D++++
*/
vector<string> grid(10);
vector<string> words;
bool f;
//int cnt=0;

void call(int index)
{
	//Means we have got the correct solution earlier now just return
	if(f==false) return;

	// Able to fit all words correctly , so just print and f=false so not to print again
	if(index == words.size())
	{
		if(f) {
			// cout<<cnt++<<endl;
			for(auto line : grid) cout<<line<<endl;
		}
		f = false;
		return;
	}

	int i,j,k,p,q;
	for(i = 0 ; i < 10 ; i++)
	{
		for(j = 0 ; j<10;j++)
		{
			p = i; q = j;
			for( k=0; k < words[index].size() && p + k < 10;k++)
			{
				// + sign there -> break or diff char there -> break          
				if(grid[p+k][q] != '-' && grid[p+k][q] != words[index][k])
					break;
			}

			if(k == words[index].size())
			{
				vector<string> temp = grid;
				for(k = 0;k < words[index].size();k++)
					grid[p+k][q] = words[index][k];

				// cout<<cnt++<<endl;
    			//for(auto line : grid) cout<<line<<endl;
				call(index + 1); 
				grid = temp;
			}

			for( k=0; k < words[index].size() && q + k < 10;k++)
			{
				if(grid[p][q + k] != '-' && grid[p][q + k] != words[index][k])
					break;
			}

			if(k == words[index].size())
			{
				vector<string> temp = grid;
				for(k = 0;k < words[index].size();k++)
					grid[p][q + k] = words[index][k];

				// cout<<cnt++<<endl;
   	            // for(auto line : grid) cout<<line<<endl;
				call(index + 1); 
				grid = temp;
			}
		}
	}
}

int main()
{
	f = true;

	for(int i=0;i<10;i++)
	{
		cin>>grid[i];
	}

	string s;
	string w; cin>>w;

	for(auto letter : w)
	{
		if(letter==';')
		{
			words.push_back(s);
			s = "";
		}
		else s += letter;
	}
	words.push_back(s);

	//Function to fill the crossword
	call(0);

	return 0;
}