#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// changing int to pair<int,int>
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

int main()
{

	// Given an Array
	// Find i < j && arr[i] > arr[j] for all indices

	int arr[] = {5, 2, 3, 2, 3, 8, 1};
	//   0,1,1,2,1,5,6  expeced
	int n = sizeof(arr) / sizeof(int);

	vector<int> ans(n);

	new_data_set St;
	for (int i = 0; i < n; i++)
	{
		// Now to find lower_bound of a no. x in this case we can either use {x,n+1} or {x+1,0}
		int cur = St.order_of_key({arr[i], n + 1}); // St.order_of_key({arr[i]+1,0})

		ans[i] = St.size() - cur;

		St.insert({arr[i], i}); // Store element along with index to store all
	}

	for (auto & ele : arr) cout << ele << " "; cout << endl;
	for (auto & ele : ans) cout << ele << " "; cout << endl;


}