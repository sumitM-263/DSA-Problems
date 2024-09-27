// here, we need to find the maximum element in all subarrays
// First approach using set and second one using deque

#include <bits/stdc++.h>
using namespace std;

vector<int> subarrayMax(vector<int>& A,int k){
    vector<int> ans;
    set<pair<int,int>,greater<pair<int,int>>> st;
    int n=A.size();

    for(int i=0;i<k;i++){
        st.insert({A[i],i});
    }

    ans.push_back(st.begin()->first);
    
    for(int i=k;i<n;i++){

        st.insert({A[i],i});

        st.erase({A[i-k],i-k});

        ans.push_back(st.begin()->first);
    }

    return ans;
}

vector<int> subarrayMaxi(vector<int>& A,int k){

    vector<int> ans;

    deque<int> dq(k);

    for(int i=0;i<k;i++){
        while(!dq.empty() and A[i]>=A[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }

    int n=A.size();

    for(int i=k;i<n;i++){
        ans.push_back(A[dq.front()]);

        while(!dq.empty() and dq.front()<=i-k) dq.pop_front();

        while(!dq.empty() and A[i]>=A[dq.back()]) dq.pop_back();

        dq.push_back(i);
    }

    ans.push_back(A[dq.front()]);

    return ans;
}

int main(){

    vector<int> A={8,5,10,7,9,4,15,12,90,13};
    int k=4;

    vector<int> ans=subarrayMaxi(A,k);
    for(auto i: ans) cout << i << " ";
    cout << endl;
}