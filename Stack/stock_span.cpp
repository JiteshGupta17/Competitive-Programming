#include <bits/stdc++.h>
using namespace std;

void StockSpan(int arr[],int n)
{
	stack <int> s;

	for(int day = 0;day<n;day++)
	{
		while(!s.empty() && arr[s.top()] < arr[day])
		{
			s.pop();
		}
		int betterDay = s.empty() ? 0 : s.top();
		int span = day - betterDay;
		cout<<span<<" ";

		s.push(day);
	}
}

int main()
{
	int arr[] = {100,80,60,70,60,75,85};
	int n = sizeof(arr)/sizeof(int);
	
	StockSpan(arr,n);

}