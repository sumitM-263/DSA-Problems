// asteroids move in right or left direction
// two different directions asteroids collide
// if same size both destroyed
// otherwise smaller gets destroyed

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroids(vector<int>& A){

    vector<int> st;

    for(int i=0;i<A.size();i++){
        if(A[i]>0) st.push_back(A[i]);
        else{
            while(!st.empty() and st.back()>0 and st.back()<abs(A[i])) st.pop_back();

            if(!st.empty() and st.back()==abs(A[i])) st.pop_back();

            else if(st.empty() or st.back()<0) st.push_back(A[i]);
        }
    }

    return st;

}


int main(){

    vector<int> A={5,-5};
    vector<int> v=asteroids(A);

    for(int i=0;i<v.size();i++) cout << v[i] <<" ";
    cout << endl;
}
