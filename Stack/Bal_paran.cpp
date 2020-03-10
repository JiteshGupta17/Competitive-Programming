#include <bits/stdc++.h>
using namespace std;

bool CheckParanthesis(string str)
{
	stack <char> s;
	for(int i=0;i < str.size();i++)
	{
		if(str[i]=='(' || str[i]=='['||str[i]=='{' )
		{
			s.push(str[i]);
			continue;
		}

		if(str[i]==')')
		{
			if(s.empty() || s.top()!='(') return false;
			else s.pop();
		}
		if(str[i]==']')
		{
			if(s.empty() || s.top()!='[') return false;
			else s.pop();
		}
		if(str[i]=='}')
		{
			if(s.empty() || s.top()!='{') return false;
			else s.pop();
		}
	}
	return s.empty();//if empty then true else false
}

int main()
{
	int t;
	cin>>t;
	string str;

	while(t--)
	{	
		cin>>str;
		if(CheckParanthesis(str)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}