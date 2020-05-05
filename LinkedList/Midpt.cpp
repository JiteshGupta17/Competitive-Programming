#include <iostream>
using namespace std;


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

node* midPoint(node* head)
{
    if(head->next==NULL || head==NULL)
    {
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast !=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
    node* head = NULL;
    BuidList(head);
    print(head);
    node* mid = midPoint(head);
    cout<<mid->data<<endl;
    
}
