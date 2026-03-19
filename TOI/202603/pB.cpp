#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char> pii;
const int INF = 1e9+9;
vector<int> pos[26];
int lmt[26];
int main(){
    int n;
    cin>>n;
    for(int i='a';i<='z';i++) {
        cin>>lmt[i-'a'];
    }
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        pos[a-'a'].push_back(i);
    }
    int ans=0;
    vector<pii> seq;
    for(char ma='a';ma<='z';ma++){
        for(char f='a';f<='z';f++){
            if(f==ma) continue;
            for(char s=f+1;s<='z';s++){
                if(s==f||s==ma) continue;
                if(pos[ma-'a'].empty() || pos[f-'a'].empty() || pos[s-'a'].empty()) continue;
                seq.clear();
                int i_ma = 0, i_f = 0, i_s = 0;
                int size_ma = pos[ma-'a'].size(), size_f = pos[f-'a'].size(), size_s = pos[s-'a'].size();
                while(i_ma < size_ma || i_f < size_f || i_s < size_s) {
                    int val_ma = (i_ma < size_ma) ? pos[ma-'a'][i_ma] : INF;
                    int val_f = (i_f < size_f) ? pos[f-'a'][i_f] : INF;
                    int val_s = (i_s < size_s) ? pos[s-'a'][i_s] : INF;

                    if(val_ma <= val_f && val_ma <= val_s) {
                        seq.push_back({pos[ma-'a'][i_ma],ma});
                        i_ma++;
                    } else if(val_f <= val_ma && val_f <= val_s) {
                        seq.push_back({pos[f-'a'][i_f],f});
                        i_f++;
                    } else {
                        seq.push_back({pos[s-'a'][i_s],s});
                        i_s++;
                    }
                }
                int cnt_ma=0,cnt_f=0,cnt_s=0;
                for(int l=0,r=0;r<seq.size();r++){
                    if(r>l){
                        if(seq[r].first-seq[r-1].first>1){
                            l=r;
                            cnt_ma=0,cnt_f=0,cnt_s=0;
                        }
                    }
                    char c = seq[r].second;
                    if(c==ma) cnt_ma++;
                    if(c==f) cnt_f++;
                    if(c==s) cnt_s++;

                    while(cnt_f>lmt[f-'a']||cnt_s>lmt[s-'a']){
                        char cs = seq[l].second;
                        if(cs==f) cnt_f--;
                        if(cs==s) cnt_s--;
                        if(cs==ma) cnt_ma--;
                        l++;
                    }
                    if(cnt_f>0&&cnt_s>0&&cnt_ma>0){
                        ans = max(ans,cnt_ma);
                    }
                }
            }
        }
    }
    cout << ans;
}