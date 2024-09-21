// Here, we have provided with a stack. Our task is to sort the stack using recursion

#include <bits/stdc++.h>
using namespace std;

void insertAtPlace(stack<int>& st,int v){

    if(st.empty()||st.top()<=v){
        st.push(v);
        return;
    }

    int t=st.top();
    st.pop();
    insertAtPlace(st,v);
    st.push(t);
    return;
}

void sortStack(stack<int>& st){
    if(st.size()<=1) return;

    int t=st.top();
    st.pop();
    sortStack(st);
    insertAtPlace(st,t);
    return;
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

    sortStack(st);

    printStack(st);
    cout << endl;
}