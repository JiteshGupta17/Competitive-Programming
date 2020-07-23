#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:

    TrieNode* left; // 0
    TrieNode* right; // 1

    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(TrieNode* root,int num)
{
    TrieNode* cur = root;
    for(int i = 31;i>=0;i--)
    {
        int cur_bit = (num>>i) & 1;

        if(cur_bit == 0)
        {
            if(cur->left) cur = cur->left;
            else{
                TrieNode* n = new TrieNode();
                cur->left = n;
                cur = n;
            }
        }
        else{ // 1 and we need to move right

            if(cur->right) cur = cur->right;
            else{
                TrieNode* n = new TrieNode();
                cur->right = n;
                cur = n;
            }
        }
    }
}

int MinXorPair(TrieNode* root,int num)
{
    TrieNode* cur = root;
    int ans = 0;
    for(int i = 31;i>=0;i--)
    {
        int cur_bit = (num>>i) & 1;

        if (cur_bit == 1)
        {
            if (cur->right)
            {
                cur = cur->right;
            }
            else{
                ans |= (1 << i); 
                cur = cur->left;
            }
        }
        else {
            if (cur->left)
            {
                cur = cur->left;
            }
            else
            {
                ans |= (1 << i);
                cur = cur->right;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {0, 4, 7, 9};
    TrieNode* root = new TrieNode();

    int ans = INT_MAX;
    insert(root,nums[0]);

    for(int i  =1;i<nums.size();i++)
    {
        int ele = nums[i];
        ans = min(ans,MinXorPair(root,ele));
        insert(root,ele);

    }

    cout<<ans;

}
