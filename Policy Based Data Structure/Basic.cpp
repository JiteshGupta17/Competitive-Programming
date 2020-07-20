#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> new_data_set;

int main()
{
	new_data_set st;
	st.insert(2);
	st.insert(3);
	st.insert(3);
	st.insert(5);
	st.insert(7);
	st.insert(9);

	// Both queries take logN
	// 2,3,5,7,9

	auto index = st.find_by_order(2); //i.e iterator to element at 2nd index
	cout<<*index<<'\n';

	cout<<st.order_of_key(10)<<'\n'; // point to index having element >= 6

	cout<<st.size();
}