#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    stack<int> st;
    bool chk=1;
    for(int a:v){
        if(a<0){
            if(st.empty()||st.top()!=-a){
                chk=0;
                break;
            }
            else{
                st.pop();
            }
        }
        else{
            st.push(a);
        }
    }
    cout << (chk&&st.empty()?"weed":"lose light light");
}