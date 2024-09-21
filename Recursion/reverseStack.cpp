// In this problem, we have been given a stack. Our task is to reverse it using recursion

#include <bits/stdc++.h>
using namespace std;


void insertAtLast(stack<int>& st,int v){

    if(st.empty()){
        st.push(v);
        return;
    }

    int top=st.top();
    st.pop();
    insertAtLast(st,v);
    st.push(top);
}

void reverseStack(stack<int>& st){

    if(st.size()<=1) return;

    int top=st.top();
    st.pop();
    reverseStack(st);
    insertAtLast(st,top);
}

void printStack(stack<int>& st){

    if(st.empty()) return;

    cout << st.top() <<" ";
    int t=st.top();
    st.pop();
    printStack(st);
    st.push(t);

}

int main(){

    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(9);
    st.push(6);

    printStack(st);
    cout << endl;

    reverseStack(st);

    printStack(st);
    cout << endl;
    

}