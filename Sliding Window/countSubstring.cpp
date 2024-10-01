// count substrings with every vowel and k consonants

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
    return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u');
}

long long solve(string s,int k){

    unordered_map<char,int> mpp;
    int left=0;
    long long ans=0;
    int x=0;

    for(int right=0;right<s.size();right++){
        if(isVowel(s[right])) mpp[s[right]]++;
        else x++;

        while(mpp.size()==5 && x>k){
            if(isVowel(s[left])) {
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
            }else x--;
            left++;
        }
        ans+=left;
    }

    return ans;
}

long long noOfSubstrings(int k,string A){

    return solve(A,k-1)-solve(A,k);
    
}

int main(){
    string s="iqeaouqi";
    int k=2;

    cout << noOfSubstrings(k,s) <<endl;
}