// input 1 2 3 4 5 -1
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

void IterativeReverse(node* &head)
{
    node* prev = NULL;
    node* cur = head;
    node* next;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        //Update
        prev = cur;
        cur = next;
    }
    head = prev;
}

node* RecursiveReverse(node* head)
{
    if(head->next == NULL || head == NULL)
    {
        return head;
    }

    node* cur = head;
    node* smallHead = RecursiveReverse(head->next);
    cur->next->next = cur;
    cur->next = NULL;
    return smallHead;
}

node* ReverseBtw(node* head,int a,int b)
{
    if(head==NULL || head->next==NULL)return head;

    node* prevBeg = NULL;
    node* beg = head;
    for(int i=1;i<a;i++)
    {
        prevBeg = beg;
        beg = beg->next;
    }

    node* end = head;
    for(int i=1;i<b;i++)
    {
        end = end->next;
    }
    node* nextEnd = end->next;
    end->next = NULL;

    if(a==1)
    {
        head = RecursiveReverse(beg);
    }
    else
    {
        prevBeg->next = RecursiveReverse(beg);
    }

    node* temp = head;
    while(temp->next) temp = temp->next;

    temp->next = nextEnd;

    return head;
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



void ReverseVal(node* head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast !=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    node* Sec_list = slow->next;
    slow->next = NULL;

    IterativeReverse(Sec_list);

    node* h1 = head;
    node* h2 = Sec_list;

    while(h1 && h2)
    {
        int d = h1->data;
        h1->data = h2->data;
        h2->data = d;

        h1 = h1->next;
        h2 = h2->next;
    }

    IterativeReverse(Sec_list);

    slow->next = Sec_list;

}

int main() {
    node* head = NULL;
    BuidList(head);
    print(head);

    // IterativeReverse(head);
    // print(head);

    // head = RecursiveReverse(head);
    // print(head);

    // head = ReverseBtw(head,2,4);
    // print(head);

    ReverseVal(head);
    print(head);


   
}
