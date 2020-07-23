#include <bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/DISUBSTR/

struct TrieNode {

    char data;
    unordered_map<char, TrieNode*> children;

    TrieNode(char ch)
    {
        data = ch;
    }

};

void insert(TrieNode* root, string cur)
{
    TrieNode* temp = root;

    for (char ch : cur)
    {
        if (temp->children.count(ch))
        {
            temp = temp->children[ch];
        }
        else {
            TrieNode* n = new TrieNode(ch);
            temp->children[ch] = n;
            temp = n;
        }
    }
}

int count(TrieNode* root)
{
    if (root == NULL) return 0;
    int cnt = 0;
    for (auto ele : root->children)
    {
        cnt += 1 + count(ele.second);
    }

    return cnt;
}

int main() {

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;

    while (t--)
    {
        string s; cin >> s;
        TrieNode* root = new TrieNode('\0');

        string back = "";

        for (int i = s.length() - 1; i >= 0; i--)
        {
            back = s[i] + back;
            insert(root, back);
        }

        int ans = count(root);
        // cout<<root->children.size();
        // for(auto ele : root->children)
        // {
        //     cout<<ele.first<<" ";
        // }
        cout << ans << endl;

    }
}
