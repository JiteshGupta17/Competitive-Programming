#include<bits/stdc++.h>
using namespace std;

class Mystack {
    //  vector can also be used
    int *arr;
    int idx = -1;
    int length ;

public:
    Mystack()
    {
        arr = new int[100];
        length = 100;
    }

    Mystack(int length)
    {
        arr = new int[length];
        this->length = length;
    }

    void print()
    {
        for (int i = idx; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }

    int size()
    {
        return idx + 1;
    }

    bool isEmpty()
    {
        return idx == -1;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "STACKisEMPTY" << endl;
            return -1;
        }

        return arr[idx];
    }

    void push(int x)
    {
        if (idx >= length - 1)
        {
            cout << "STACKisFULL" << endl;
            return;
        }
        arr[++idx] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "STACKisEMPTY" << endl;
            return;
        }

        arr[idx--] = 0;
    }

};

class MyQueue {
    vector<int> arr;
    int st = 0;
    int end = 0;
    int cur_size = 0;

public:
    MyQueue()
    {
        arr.resize(100);
    }

    MyQueue(int s)
    {
        arr.resize(s);
    }

    int size()
    {
        return cur_size;
    }

    bool isEmpty()
    {
        return cur_size == 0;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "QUEUEisEMPTY" << endl;
            return -1;
        }

        return arr[st];
    }

    void push(int x)
    {
        if (cur_size >= arr.size())
        {
            cout << "QUEUEisFULL" << endl;
            return;
        }

        arr[end] = x;
        cur_size++;
        end = (end + 1) % arr.size();
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "QUEUEisEMPTY" << endl;
            return;
        }

        arr[st] = 0;
        st = (st + 1) % arr.size();
        cur_size--;
    }

    void print()
    {
        int j = st;
        for (int i = 0; i < cur_size; i++ )
        {
            cout << arr[j] << " ";
            j = (j + 1) % arr.size();

        }
        cout << endl;
    }

};

int main()
{
    // Mystack s(50);

    // for(int i = 0;i<10;i++)
    // {
    //     s.push(i+10);
    // }

    // s.print();
    // s.pop();
    // s.pop();
    // cout<<s.size()<<endl;
    // s.print();

    MyQueue q(7);
    for (int i = 0; i < 7; i++)
    {
        q.push(i + 10);
    }
    q.print();

    q.pop();
    q.print();

    q.push(1);
    q.print();
}