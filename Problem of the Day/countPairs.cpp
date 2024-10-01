#include <bits/stdc++.h>
using namespace std;

bool canMakePairs(vector<int>& A,int k){

    int n=A.size();

    int hash[k]={0};

    for(auto i:A){
        int rem=((i%k)+k)%k;

        hash[rem]++;
    }

    if(hash[0]&1) return false;

    for(int i=1;i<=k/2;i++){
        if(hash[i]!=hash[k-i]) return false;
    }

    return true;
}

int main(){

    vector<int> A={1,2,3,4,5,6};
    int k=10;

    cout << canMakePairs(A,k) <<endl;
}