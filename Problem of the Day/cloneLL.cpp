// Here we have been given a LL and we need to clone it and also add random pointers

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* random;

    Node(int x){
        data=x;
        next=NULL;
        random=NULL;
    }
};

Node* copyList(Node* head){

    if(head==NULL) return head;

    Node* temp=head;
    Node* newHead=new Node(-1);
    Node* p=newHead;

    vector<pair<int,int>> pairs;

    while(temp!=NULL){

        if(temp->random!=NULL){
            pairs.push_back({temp->data,temp->random->data});
        }

        Node* newNode=new Node(temp->data);
        p->next=newNode;
        p=p->next;
        temp=temp->next;
    }

    p=newHead->next;
    unordered_map<int,Node*> mpp;
    while(p!=NULL){
        mpp[p->data]=p;
        p=p->next;
    }

    for(auto it: pairs){
        Node* node=mpp[it.first];
        node->random=mpp[it.second];
    }

    return newHead->next;
}

void printLL(Node* head){

    Node* temp=head;

    while(temp!=NULL){
        cout << temp->data << " " ;
        if(temp->next)cout << temp->next->data << " " ;
        else cout << -1 << " ";
        if(temp->random)cout << temp->random->data << endl;
        else cout << -1 << endl;
        temp=temp->next;
    }

    return;

}

int main(){

    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    head->random=head->next;
    head->next->random=head->next->next->next;

    cout << "Given Linked List: "<< endl;
    printLL(head);

    Node* newList=copyList(head);

    cout << "Copy of Given Linked List: "<< endl;
    printLL(newList);
}