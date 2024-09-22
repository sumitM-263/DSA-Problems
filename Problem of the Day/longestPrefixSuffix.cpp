#include <bits/stdc++.h>
using namespace std;

int lps(string s){

    int n=s.size();
    int A[s.size()]={0};
    int len=0;
    int i=1;

    while (i<n)
    {
        if(s[i]==s[len]){
            len++;
            A[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=A[len-1];
            }
            else{
                A[i]=0;
                i++;
            }
        }
        
    }
    return A[n-1];
    
}

int main(){

    string s="ddbbbbcddd";
    cout << lps(s) <<endl;

}