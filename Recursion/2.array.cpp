#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> &arr, int ind, int data)
{
	if (ind == arr.size())
	{
		return false;
	}

	if (data == arr[ind]) return true;
	else return find(arr, ind + 1, data);
}

int maximum(vector<int> &arr, int ind)
{
	if (ind == arr.size() - 1)
	{
		return arr[ind];
	}

	return max(arr[ind], maximum(arr, ind + 1));
}

int lastIndex(vector<int> &arr, int ind, int data)
{
	// if(last_ind == 0) return -1;

	// if(arr[last_ind-1] == data) return last_ind-1;
	// else return lastIndex(arr,last_ind-1,data);
	if (ind == arr.size())
	{
		return -1;
	}

	int rec_ans = lastIndex(arr, ind + 1, data);
	if (rec_ans != -1) return rec_ans;
	else return arr[ind] == data ? ind : -1;
}

// vector<int> allIndex(vector<int> &arr, int ind, int data, int size)
int * allIndex(vector<int> &arr, int ind, int data, int size)
{
	//BY USING VECTOR WITHOUT PUSH_BACK
	// if (ind == arr.size())
	// {
	//     vector<int> v(size);
	//     return v;
	// }

	// if (arr[ind] == data)
	//     size++;

	// vector<int> v = allIndex(arr, ind + 1, data, size);

	// if (arr[ind] == data)
	//     v[size - 1] = ind;

	// return v;

	if (ind == arr.size())
	{
		int * v = new int[size];
		return v;
	}

	if (arr[ind] == data)
		size++;

	int* v = allIndex(arr, ind + 1, data, size);

	if (arr[ind] == data)
		v[size - 1] = ind;

	return v;

}

void solve()
{
	vector <int> arr = {10, 6, 8, 10, 4, 5, 5, 6, 8, -3, 2, 12, 8, 3};

	cout << find(arr, 0, 8) << endl;

	cout << maximum(arr, 0) << endl;

	cout << lastIndex(arr, 0, 8) << endl;

	// vector<int> v = allIndex(arr, 0, 8, 0);
	int *  v = allIndex(arr, 0, 8, 0);
	for (int i = 0; i < 3/* v.size()*/; i++)cout << v[i] << " ";
	cout << endl;




}

int main()
{
	solve();
	return 0;
}

