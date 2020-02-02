#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> v;
    bool isMax = true;

public:
    PriorityQueue(){}

    PriorityQueue(bool isMax)
    {
        this->isMax = isMax;
    }

    PriorityQueue(vector<int> input,bool isMax)
    {
        this->isMax = isMax;
        for(int i = 0;i<input.size();i++)
        {
            v.push_back(input[i]);
            upHeapify(i);
        }
    }

    void push(int x)
    {
        v.push_back(x);
        upHeapify(v.size()-1);
    }

    void pop() // removes top element
    {
        swap(0,v.size()-1);
        int n  = v.size()-1;
        v.erase(v.begin() + n);

        downHeapify(0,v.size());
    }

    int top()
    {
        if(v.size())
        {
            return v[0];
        }
    }

    int size()
    {
        return v.size();
    }

    void upHeapify(int ci)
    {
        int pi = (ci-1)/2;

        if(pi>=0 && compare(v[ci],v[pi]) > 0)
        {
            swap(ci,pi);
            upHeapify(pi);
        }
    }

    void downHeapify(int pi,int n)
    {
        int maxIdx = pi;

        int lci = 2*pi + 1;
        int rci = 2*pi + 2;

        if(lci < n && compare(v[lci],v[maxIdx]) > 0)
        {
            maxIdx = lci;
        }

        if(rci < n && compare(v[rci],v[maxIdx]) > 0)
        {
            maxIdx = rci;
        }

        if(maxIdx != pi)
        {
            swap(maxIdx,pi);
            downHeapify(maxIdx,n);
        }
    }

    int compare(int val1,int val2)
    {
        if(isMax)
            return val1 - val2;
        
        return val2 - val1;
    }

    void swap(int i,int j)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

};

int main()
{
    // PriorityQueue pq1;
    // for(int i = 0;i<5;i++)
    // {
    //     pq1.push(i+1);
    // }

    // while(pq1.size() != 0)
    // {
    //     cout<<pq1.top()<<" ";
    //     pq1.pop();
    // }

    vector<int> v = {10, 20, 30, -2, -3, -4, 5};
    PriorityQueue pq2(v,true);

    while(pq2.size() != 0)
    {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }

}