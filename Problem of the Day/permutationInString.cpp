// we have been given strings s2 and s1 and we need to check if s1's permutation is a substring of s2

#include <bits/stdc++.h>
using namespace std;

bool areEqual(int A[],int B[]){

    for(int i=0;i<26;i++) if(A[i]!=B[i]) return false;
    return true;
}

bool permutationInString(string s1,string s2){

    int n=s1.size();
    int m=s2.size();
    if(n>m) return false;

    int h1[26]={0};
    for(auto &i:s1) h1[i-'a']++;

    for(int i=0;i<=m-n;i++){

        int h2[26]={0};

        for(int j=0;j<n;j++){
            h2[s2[i+j]-'a']++;
        }

        if(areEqual(h1,h2)) return true;
    }

    return false;

}


// accepted 
bool permutationInString2(string s1,string s2){

    int n=s1.size();
    int m=s2.size();
    if(n>m) return false;

    int h1[26]={0};
    int h2[26]={0};

    for(int i=0;i<n;i++){
        h1[s1[i]-'a']++;
        h2[s2[i]-'a']++;
    }

    int l=0;
    int r=n-1;
    while(r<m){
        if(areEqual(h1,h2)) return true;

        h2[s2[l]-'a']--;
        l++;
        r++;
        h2[s2[r]-'a']++;
    }

    return areEqual(h1,h2);
}

int main(){

    string s1="abc";
    string s2="eidxcyuygbaooo";

    if(permutationInString2(s1,s2)) cout << "s1 is present in s2" <<endl;
    else cout << "s1 is not present in s2" <<endl;
}