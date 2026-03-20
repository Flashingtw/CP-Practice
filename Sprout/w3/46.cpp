#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    multiset<int> ms;
    int n;
    cin>>n;
    while(n--){
        int a;
        string q;
        cin>>q>>a; 
        if(q[0]=='i'){
            ms.insert(a);
        }
        if(q[0]=='d'){
            ms.erase(ms.find(a));
        }
        if(q[0]=='q'){
            auto it = ms.upper_bound(a);
            auto it_prev = prev(it);
            if(abs(*it_prev-a)<abs(*it-a)){
                cout << *it_prev << '\n'; 
            }
            else if (abs(*it_prev-a)==abs(*it-a)) cout << min(*it,*it_prev) << ' ' << max(*it,*it_prev) << '\n';
            else cout << *it << '\n'; 
        }
    }
}