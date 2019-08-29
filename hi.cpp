#include <bits/stdc++.h>
using namespace std;

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void TransferUsing1stack(stack <int> &s1,stack <int> &s2,int n)
{
    for(int i=0;i<n;i++)
    {
        int x = s1.top();
        s1.pop();
        s2.push(x);
    }
}

void ReverseStack(stack<int> &s1)
{
    stack<int> s2;
    int n= s1.size();

    for(int i=0;i<n;i++)
    {
        int x = s1.top();
        s1.pop();
        TransferUsing1stack(s1,s2,n-1-i);
        s1.push(x);
        TransferUsing1stack(s2,s1,n-1-i);
    }
}

void Transfer(stack <int> &a,stack <int> &b)
{
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
}

void Insert(stack<int> &s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int y = s.top();
    s.pop();
    Insert(s,x);
    s.push(y);
}

void ReverseRec(stack<int> &s)
{
    if(s.empty()) return ;

    int x = s.top();
    s.pop();
    ReverseRec(s);
    Insert(s,x); // insert x at bottom of s
}

int main() {
    stack <int> s;

    int n; cin>>n;

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        s.push(x);
    }

    cout<<"Original Stack = ";
    print(s);

    stack <int> s1,s2 ;
    Transfer(s,s1);
    Transfer(s1,s2);
    Transfer(s2,s);

    cout<<"Using 2 stack = ";
    print(s);

    //Using 1 stack s1 now to reverse s
    ReverseStack(s);
    cout<<"Using 1 stack = ";
    print(s);

    //Using Recursion
    ReverseRec(s);
    cout<<"Using Recursion = ";
    print(s);

}
