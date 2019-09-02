#include <bits/stdc++.h>
using namespace std;

 // INPUT = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

class node{
public:

	int data;
	node* left;
	node* right;

	node (int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree()
{
	int x;
	cin>>x;

	if(x == -1) return NULL; //Base case 

	node* root = new node(x);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void Inorder(node* root)
{
	if(root==NULL) return;

	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void PostOrder(node* root)
{
	if(root==NULL) return;

	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}


int Height(node* root)
{
	if(root == NULL) return 0;

	int h1 = Height(root->left); //Height of left subtree
	int h2 = Height(root->right);//Height of right subtree

	return 1 + max(h1,h2);
}

void PrintKthLevel(node* root, int k)
{
	if(root==NULL) return;

	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}

	PrintKthLevel(root->left,k-1);
	PrintKthLevel(root->right,k-1);
	return;
}

void bfs(node* root)
{
	if(root==NULL) return;

	queue <node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty()) q.push(NULL);//imp to avoid infinite loop
		}
		else
		{	
			cout<<q.front()->data<<" ";
			if(q.front()->left) q.push(q.front()->left);
			if(q.front()->right) q.push(q.front()->right);

			q.pop();
		}	
	}
}

void LevelOrder(node* root)
{
	int h = Height(root);

	for(int k=1;k<=h;k++)
	{
		PrintKthLevel(root,k);
		cout<<endl;
	}
}

void print(node* root)//preorder
{
	if(root == NULL) return;

	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int count(node* root)
{
	if(root==NULL) return 0;

	return 1 + count(root->left) + count(root->right); 
}	//for sum instead of 1 , root->data + ....

int diameter(node* root)
{
	if(root==NULL) return 0;

	int h1 = Height(root->left);
	int h2 = Height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1,max(op2,op3));
}

class Pair{ // Can use inbuild pair but making this for easy name
	public:
		int h; // height
		int d; // Diameter
};

Pair fastDiameter(node* root)
{
	Pair P;
	if(root== NULL)
	{
		P.h = P.d = 0;
		return P;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	P.h = 1 + max(left.h,right.h);
	P.d = max(left.h + right.h, max(left.d,right.d));
	return P;
}

int replaceSum(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    //Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
    //For main root node we didnt print that last line assume it to be for all other nodes
}

int main()
{
	node* root = buildTree();

	print(root);
	cout<<endl;
	Inorder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;

	// cout<<Height(root);
	// PrintKthLevel(root,2);
	LevelOrder(root); //O(n^2) worst case

	bfs(root); //O(n)

	cout<<count(root)<<endl;

	cout<<diameter(root)<<endl;

	Pair p = fastDiameter(root);
	cout<<p.h<<endl;
	cout<<p.d<<endl;

	replaceSum(root);
	bfs(root);
}