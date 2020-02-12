#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    int freq;

    Node(char data, int freq, Node* left, Node*right)
    {
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

unordered_map<char, string> decode;

void TreeTraverse(Node* root, string ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        decode[root->data] = ans;
        return ;
    }

    TreeTraverse(root->left, ans + "0");
    TreeTraverse(root->right, ans + "1");
}

class custom {
public:
    bool operator()(const Node* root1, const Node* root2)
    {
        return root1->freq > root2->freq;
    }
};

void huffman(vector<pair<char, int>> v)
{
    priority_queue<Node*, vector<Node*>, custom> pq;

    for (int i = 0; i < v.size(); i++)
    {
        Node* n = new Node(v[i].first, v[i].second, NULL, NULL);
        pq.push(n);
    }

    Node*root ;
    while (pq.size() != 1)
    {
        Node* root1 = pq.top();
        pq.pop();
        Node* root2 = pq.top();
        pq.pop();

        root = new Node('z', root1->freq + root2->freq, root1, root2);
        pq.push(root);
    }

    TreeTraverse(root, ""); //pq.top() would also have work

    for (auto f :  decode)
    {
        cout << f.first << " " << f.second << endl;
    }
}

int main()
{
    vector<pair<char, int>> v = {{'a', 10}, {'b', 20}, {'c', 5}, {'d', 2}, {'e', 1}};

    huffman(v);

}