#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
int main(){
    int n,k,e;
    cin>>n>>k>>e;
    vector<int> hole(n),s(k);
    for(int i=0;i<n;i++) cin>>hole[i];
    for(int i=0;i<e;i++) cin>>s[i];
    sort(all(hole),greater());
    sort(all(s),greater());
    int cur=0;
    vector<int> st;
    while(1){
        bool can=false;
        for(int step:s){
            if(!binary_search(all(hole),cur+step)&&cur+step<=e){
                cur+=step;
                can=true;
                st.push_back(cur);
                break;
            }
        }
        if(!can){
            st.pop_back();
            cur = st.back();
        }
        if(cur+s.back()>e){
            cout << -1 ;
            return 0;
        }
        if(cur==e) break;
    }
    cout << st.size() << "\n";
    for(int i:st) cout << i << " ";
}