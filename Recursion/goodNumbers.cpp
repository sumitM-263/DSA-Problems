// Here, we need to find numbers of good numbers that can be formed by using 0-9 digits with even digits at even places and 
// prime digits at odd places in a string 
// 0<=n<=10^15

#include <bits/stdc++.h>
using namespace std;

int modExponentiation(long long x,long long n,int M){

    if(n==0) return 1;

    else if(n&1){
        return (x*modExponentiation((x*x)%M,(n-1)/2,M))%M;
    }
    else return modExponentiation((x*x)%M,n/2,M)%M;

}

int countGoodNumbers(long long n){

    long long ans=1;
    int M=1e9+7;
    return (ans*(modExponentiation(4,n/2,M)%M)*(modExponentiation(5,n-(n/2),M)%M))%M;
}


int main(){

    long long n=50;
    cout << countGoodNumbers(n) <<endl;

}