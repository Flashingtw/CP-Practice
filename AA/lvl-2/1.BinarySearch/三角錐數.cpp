#include <bits/stdc++.h>
using i128 = __int128;
using namespace std;
i128 read_i128() {
    string s;
    cin >> s;
    i128 value = 0;
    int start = 0;
    if (!s.empty() && s[0] == '-') {
        start = 1;
        for (int i = start; i < (int)s.size(); ++i) {
            value = value * 10 - (s[i] - '0');
        }
    } else {
        for (int i = start; i < (int)s.size(); ++i) {
            value = value * 10 + (s[i] - '0');
        }
    }
    return value;
}
void print_i128(i128 value) {
    if (value == 0) {
        cout << "0" << '\n';
        return;
    }

    string out;
    if (value < 0) {
        cout << '-';
        while (value < 0) {
            out.push_back(char('0' + int(-(value % 10))));
            value /= 10;
        }
    } else {
        while (value > 0) {
            out.push_back(char('0' + int(value % 10)));
            value /= 10;
        }
    }
    reverse(out.begin(), out.end());
    cout << out << '\n';
}

i128 x;

i128 cnt(i128 tar){
    i128 n[3] = {tar,tar+1,tar+2};
    for(int i=0;i<3;i++){
        if(n[i]%3==0){
            n[i]/=3;
            break;
        }
    }
    for(int i=0;i<3;i++){
        if(n[i]%2==0){
            n[i]/=2;
            break;
        }
    }
    return n[0]*n[1]*n[2];
}

bool chk(i128 tar){
    return cnt(tar)>=x;
}

int main(){
    int q;
    cin>>q;
    while(q--){
        x = read_i128();
        i128 l = -1e13,r = 1e13,ans=0;
        while(l<=r){
            i128 mid = (l+r)/2;
            if(chk(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        print_i128(cnt(ans));
    }
}