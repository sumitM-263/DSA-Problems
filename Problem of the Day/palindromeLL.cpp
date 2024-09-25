#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    struct Node* next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

Node* reverseLL(Node* head){

    Node* temp=head;
    Node* nextNode;
    Node* previous=NULL;

    while(temp!=NULL){
        nextNode=temp->next;
        temp->next=previous;
        previous=temp;
        temp=nextNode;
    }

    return previous;
}

bool isPalindrome(Node* head){

    Node* slow=head;
    Node* fast=head->next;

    // find the middle node

    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    // split the linked list
    Node* t1=head;
    Node* t2=slow->next;
    Node* temp=slow->next;
    slow->next=NULL;
    
    // reverse the second half of the linked list
    t2=reverseLL(t2);

    // compare both the halves 
    bool flag=true;
    while(t1!=NULL and t2!=NULL){
        if(t1->data!=t2->data){
            flag=false;
            break;
        }
        t1=t1->next;
        t2=t2->next;
    }

    // rejoin both the halves

    Node* p=head;
    while(p->next!=NULL) p=p->next;
    p->next=temp;


    if(!flag) return false;
    return true;
}

int main(){

    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);
    head->next->next->next= new Node(1);

    if(isPalindrome(head)) cout << "YES" <<endl;
    else cout << "NO" <<endl;
}