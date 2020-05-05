#include <iostream>
using namespace std;

// Input
// 1 3 4 7 8  -1
// 0 2 8 10 12 -1

class node{
    public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};


void insertAtTail(node* &head,int x)
{
    if(head==NULL)
    {
        head = new node(x);
        return;
    }
    node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    node* n = new node(x);
    n->next = temp->next;
    temp->next = n;
    
}


void BuidList(node* &head)
{
    int x;
    cin>>x;

    while(x != -1)
    {
        insertAtTail(head,x);
        cin>>x;
    }
}

node* merge(node* a,node* b)
{
    if(a==NULL) return b;
    else if(b == NULL) return a;

    node* c;
    
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next,b);
    }
    else
    {
        c = b;
        c-> next = merge(a,b->next);
    }
    return c;
}

void print(node* head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    node* a = NULL,*b = NULL;
    BuidList(a);
    BuidList(b);
    print(a);
    print(b);
    node *c = merge(a,b);
    print(c);
 

    
}
