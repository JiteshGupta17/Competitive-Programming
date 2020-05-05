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

void insertAthead(node* &head,int x)
{
    node* n = new node(x);
    n->next = head;
    head = n;
    
}

int length(node* head)
{
    int len = 0;
    while(head)
    {
        head = head->next;
        len++;
    }
    return len;
}

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
    // n->next = temp->next;
    temp->next = n;    
}

void insertAtMiddle(node* &head,int x,int pos)
{
    if(head==NULL || pos == 0)
    {
        insertAthead(head,x);
        return;
    }
    if(pos > length(head))
    {
        insertAtTail(head,x);
        return;
    }
    node* temp = head;
    for(int i=0;i<pos-1;i++)
    {
        temp = temp->next;
    }
    node* n = new node(x);
    n->next = temp->next;
    temp->next = n;

}

void deleteHead(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    node* temp = head;
    head =head->next ;
    delete temp;

}

void deleteTail(node*&head)
{
    node* prev = NULL;
    node* temp = head;
    while(temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}

bool Check(node*head,int x)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->data == x || Check(head->next,x))
    {
        return true;
    }
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
    insertAthead(head,6);
    insertAthead(head,4);
    insertAthead(head,3);
    print(head);
    insertAtMiddle(head,5,2);//insert 5 after 2 positions
    insertAtMiddle(head,2,0);
    print(head);
    insertAtTail(head,7);
    print(head);
    cout<<Check(head,8);
}
