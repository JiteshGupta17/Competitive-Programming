#include<bits/stdc++.h>
using namespace std;

class Node {
public:

	char data;
	unordered_map<char, Node*> children;
	bool terminal;
	int occur;

	Node(char ch)
	{
		data = ch;
		terminal = false;
		occur = 1;
	}

};

class Trie {
public:

	Node* root;
	int cnt;

	Trie()
	{
		root = new Node('\0');
	}

	void insert(string s)
	{
		Node* temp = root;
		for (char ch : s)
		{
			if (temp->children.count(ch))
			{
				temp = temp->children[ch];
				temp->occur++;
			}
			else {
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}

		temp->terminal = true;
	}

	bool find(string s)
	{
		Node* temp = root;
		for (char ch : s)
		{
			if (temp->children.count(ch))
			{
				temp = temp->children[ch];
			}
			else {
				return false;
			}
		}

		return temp->terminal;
	}

	string UniquePrefix(string s)
	{
		string ans = "";
		bool f = false;
		Node* temp = root;
		for (char ch : s)
		{
			if (temp->children.count(ch))
			{
				temp = temp->children[ch];
				ans += ch;
				if (temp->occur == 1)
				{
					f = true;
					break;
				}
			}
		}

		if (f) return ans;
		return "Not Possible";
	}

};

int main()
{
	Trie t;
	vector<string> words = {"zebra", "dog", "dove", "duck"};
	for (string s : words) t.insert(s);

	for (string s : words)
	{
		string ans = t.UniquePrefix(s);
		cout << s << " -> " << ans << endl;
	}

	words.push_back("zebras");
	t.insert("zebras");

	for (string s : words)
	{
		string ans = t.UniquePrefix(s);
		cout << s << " -> " << ans << endl;
	}
}