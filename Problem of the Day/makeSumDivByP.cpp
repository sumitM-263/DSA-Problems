#include <bits/stdc++.h>
using namespace std;

int minLengthSub(vector<int>& A,int p){

    int n=A.size();
    int totalSum=0;

    for(auto i:A) totalSum=(totalSum+i)%p;

    int target=totalSum%p;

    if(target==0) return 0;

    int currentSum=0;
    int minLen=n;

    unordered_map<int,int> mpp;

    for(int i=0;i<n;i++){
        currentSum=(currentSum+A[i])%p;

        int needed=(currentSum-target+p)%p;

        if(mpp.find(needed)!=mpp.end()) minLen=min(minLen,i-mpp[needed]);

        mpp[currentSum]=i;
    }

    return minLen==n? -1: minLen;
}

int main(){

    vector<int> A={6,3,5,2,7};
    int p=9;

    int x=minLengthSub(A,p); 

    cout << x <<endl;
}