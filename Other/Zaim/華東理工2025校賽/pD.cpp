#include <bits/stdc++.h>
using namespace std;

string b = "ECUST";
string s = "ecust";

void dfs(int idx,string &st){
    if(idx>=5){
        cout << st << '\n';
        return;
    }
    st.push_back(b[idx]);
    dfs(idx+1,st);
    st.pop_back();

    st.push_back(s[idx]);
    dfs(idx+1,st);
    st.pop_back();
}

int main(){
    string a;
    dfs(0,a);
}