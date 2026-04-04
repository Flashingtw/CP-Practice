#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
bool used[N];
pair<int,int> ans[N];
multimap<int,int> mp_w, mp_h;

int main(){
    int n, h, w;
    cin >> h >> w >> n; 
    
    vector<pair<int,int>> p(n);
    for(int i=0; i<n; i++){
        int hi, wi;
        cin >> hi >> wi;
        mp_w.insert({wi, i});
        mp_h.insert({hi, i});
        p[i] = {wi, hi};
    }

    int cur_r = 1, cur_c = 1;
    int rem_h = h, rem_w = w;

    for(int step=0; step<n; step++){
        int sele = -1;
    
        int type = -1; 
        auto it_w = mp_w.find(rem_w);
        while(it_w != mp_w.end() && it_w->first == rem_w){
            int id = it_w->second;
            if(used[id]){
                it_w = mp_w.erase(it_w);
            }
            else{
                sele = id;
                mp_w.erase(it_w);
                type = 0;
                break;
            }
        }
        if(sele == -1){
            auto it_h = mp_h.find(rem_h);
            while(it_h != mp_h.end() && it_h->first == rem_h){
                int id = it_h->second;
                if(used[id]){
                    it_h = mp_h.erase(it_h);
                }
                else{
                    sele = id;
                    mp_h.erase(it_h);
                    type = 1;
                    break;
                }
            }
        }
        if(sele == -1) break;
        used[sele] = true;
        ans[sele] = {cur_r, cur_c}; 

        if(type == 0){
            cur_r += p[sele].second; 
            rem_h -= p[sele].second;
        }
        else{
            cur_c += p[sele].first;
            rem_w -= p[sele].first;
        }
    }
    for (int i=0; i<n; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}