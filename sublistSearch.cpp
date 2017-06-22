#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
};

node *newNode(int key) {
    node *newnode=new node;
    newnode->data=key;
    newnode->next=NULL;
    return newnode;
}

bool findList(node *first, node *second) {
    if(first==NULL && second ==NULL)
        return true;
    if(first==NULL || (first!=NULL && second==NULL))
        return false;
    node *ptr1=first;
    node *ptr2=second;
    while(second!=NULL) {
        ptr2=second;

        while(ptr1!=NULL) {
            if(ptr2==NULL)
                return false;
            else if(ptr1->data==ptr2->data){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else
                break;
        }

        if(ptr1==NULL)
            return true;

        ptr1=first;
        second=second->next;
    }
    return false;
}
int main()
{
    int x;
    node *ahead=NULL, *ptr1=NULL;
    int i=0;
    cout<<"\nEnter the first list";
    while (true){
        cout<<"\nEnter element (-1 to exit input)";
        cin>>x;
        if(x==-1)
            break;
        node *a=newNode(x);
        if(i==0){
            i=1;
            ahead=a;
            ptr1=ahead;
        }
        else{
            ptr1=ptr1->next;
            ptr1=a;
        }
    }
    node *bhead=NULL, *ptr2=NULL;
    i=0;
    cout<<"\nEnter the second list";
    while(true) {
        cout<<"\nEnter elements (-1 to exit input)";
        cin>>x;
        if(x==-1)
            break;
        node *a=newNode(x);
        if(i==0) {
            i=1;
            bhead= a;
            ptr2=bhead;
        }
        else{
            ptr2=ptr2->next;
            ptr2=a;
        }
    }

    findList(ahead,bhead) ? cout << "LIST FOUND" :
                    cout << "LIST NOT FOUND";

    return 0;
}
