// we have been given two sentences if one sentence can be converted to another by inserting only one sentence
// then both sentences are similar

#include <bits/stdc++.h>
using namespace std;

deque<string> sentenceToWords1(string s){

    deque<string> words;
    string word="";

    for(int i=0;i<s.size();i++){

        if(s[i]!=' '){
            word.push_back(s[i]);
        }
        else{
            if(word!=""){
                words.push_back(word);
                word="";
            }
        }
    }

    if(word!="") words.push_back(word);
    return words;
}

vector<string> sentenceToWords(string s){

    vector<string> words;
    string word="";

    for(int i=0;i<s.size();i++){

        if(s[i]!=' '){
            word.push_back(s[i]);
        }
        else{
            if(word!=""){
                words.push_back(word);
                word="";
            }
        }
    }

    if(word!="") words.push_back(word);
    return words;
}

bool areSimilar(string s1,string s2){

    vector<string> s1Words=sentenceToWords(s1);
    vector<string> s2Words=sentenceToWords(s2);

    if(s1Words.size()>s2Words.size()) swap(s2Words,s1Words);

    int n=s1Words.size();
    int m=s2Words.size();
    int start=0;
    int end1=n-1;
    int end2=m-1;

    while(start<s1Words.size() and (s1Words[start]==s2Words[start])) start++;

    while(end1>=0 and (s1Words[end1]==s2Words[end2])) end1--,end2--;

    return end1<start;    
    
}

bool areSimilar1(string s1,string s2){

    deque<string> d1=sentenceToWords1(s1);
    deque<string> d2=sentenceToWords1(s2);

    while(!d1.empty() and !d2.empty() and d1.front()==d2.front()) d1.pop_front(),d2.pop_front();

    while(!d1.empty() and !d2.empty() and d1.back()==d2.back()) d1.pop_back(),d2.pop_back();

    return d2.empty()||d1.empty();
}

int main(){

    string s1="My name is John";
    string s2="My";

    areSimilar1(s1,s2) ? cout << "YES" <<endl : cout << "NO" <<endl;
}