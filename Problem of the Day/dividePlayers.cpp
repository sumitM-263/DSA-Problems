// divide the array into n/2 pairs such sum of values in each pair are equal
// return sum of product of values in each pair

#include <bits/stdc++.h>
using namespace std;

// incorrect solution
int chemistryOfPlayers(vector<int>& A){

    int n=A.size();

    int sum=0;
    for(auto &i:A) sum+=i;

    if(sum&1) return -1;

    int target=(sum*2)/n;

    unordered_map<int,int> mpp;
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){

        int x=A[i];
        int needed=target-x;

        if(mpp.find(needed)!=mpp.end() and cnt<n/2){
            ans=ans+(needed*x);
            cnt++;
        }
        mpp[x]=i;
    }

    return ans;

}


// accepted solution
long long chemistryOfPlayers1(vector<int>& A){

        int n=A.size();
        if(n==2) return A[0]*A[1];

        long long ans=0;
        sort(A.begin(),A.end());

        long long sum=0;
        for(auto &i:A) sum+=i;

        long long target=(sum*2)/n;

        int i=0;
        int j=n-1;
        int cnt=0;
        while(i<=j){
            if(A[i]+A[j]==target){
                ans+=(A[i]*A[j]);
                cnt++;
            }
            i++,j--;
        }

        if(cnt==n/2) return ans;
        return -1;
}

int main(){

    vector<int> A={2,2,2,2};
    cout << chemistryOfPlayers(A) <<endl;
}