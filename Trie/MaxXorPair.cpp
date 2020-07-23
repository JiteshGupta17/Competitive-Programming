#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(32*N) ~ O(N)

class TrieNode {
public:

	TrieNode* left; // Represents 0
	TrieNode* right; // Represents 1

	TrieNode()
	{
		left = NULL;
		right = NULL;
	}
};

void insert(TrieNode* root, int ele)
{
	TrieNode* cur = root;
	for (int i = 31; i >= 0; i--)
	{
		int bit = (ele >> i) & 1; // or bit = (1<<i) & ele ? 1 : 0;
		if (bit == 0)
		{
			if (cur->left) cur = cur->left;
			else {
				TrieNode* n = new TrieNode();
				cur->left = n;
				cur = n;
			}
		}
		else {
			if (cur->right) cur = cur->right;
			else {
				TrieNode* n = new TrieNode();
				cur->right = n;
				cur = n;
			}
		}
	}
}

int FIndMaxXorPair(TrieNode* root, int ele)
{
	TrieNode* cur = root;
	int result = 0;
	for (int i = 31; i >= 0; i--)
	{
		int bit = (ele >> i) & 1;

		if (bit == 0)
		{
			// cur_bit of element is 0 and we need to find a 1 if present
			if (cur->right)
			{
				result |= (1 << i);
				cur = cur->right;
			}
			else cur = cur->left; // No other option other than going left
		}
		else {
			// cur_bit of element is 1 and we need to find a 0 if present
			if (cur->left)
			{
				result |= (1 << i);
				cur = cur->left;
			}
			else cur = cur->right; // No other option other than going right
		}
	}
	return result;
}

int main()
{
	TrieNode* root = new TrieNode();
	int arr[6] = {3, 10, 5, 25, 2, 8};
	int result = INT_MIN;

	for (int i = 0; i < 6; i++)
	{
		insert(root, arr[i]);
		int cur_max_pair = FIndMaxXorPair(root, arr[i]);
		result = max(cur_max_pair, result);
	}

	// Time Complexity = O(32*N) ~ O(N)

	cout << result << "\n";
/*
	This can also be used to find subarray with max xor

	Using property -> f(l, r) = f(0, r) ^ f(0, l - 1);

	arr = (3, 10, 5, 25, 2, 8);

	new_arr = {3, 3 ^ 10, 3 ^ 10 ^ 5, 3 ^ 10 ^ 5 ^ 25, 3 ^ 10 ^ 5 ^ 25 ^ 2, 3 ^ 10 ^ 5 ^ 25 ^ 2 ^ 8};

	now this become equivalent to find max xor pair in new_arr

*/

}