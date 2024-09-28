// dynamic programming problem

#include <bits/stdc++.h>
using namespace std;

int minimalCost(vector<int>& A,int k){

    int n=A.size();

    unordered_map<int,int> mpp;

    mpp[A[0]]=0;

    for(int i=1;i<n;i++){

        int minCost=INT_MAX;

        for(int j=i-1;j>=i-k and i-j>=0;j--){
            minCost=min(minCost,mpp[A[j]]+abs(A[j]-A[i]));
        }

        mpp[A[i]]=minCost;
    }

    return mpp[A[n-1]];
}

int minimalCost1(vector<int>& A,int k){

    int n=A.size();

    vector<int> v(n);

    v[0]=0;

    for(int i=1;i<n;i++){

        int minCost=INT_MAX;

        for(int j=i-1;j>=i-k and i-j>=0;j--){
            minCost=min(minCost,v[j]+abs(A[j]-A[i]));
        }

        v[i]=minCost;
    }

    return v[n-1];
}


int main(){

    vector<int> A={35,1,70,25,79,59,63,65};
    int k=2;

    cout << minimalCost1(A,k) <<endl;
}