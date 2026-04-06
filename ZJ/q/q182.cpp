#include <bits/stdc++.h>
using namespace std;
string s;

void twoswap() {
    for (int i=0;i<s.length();i+=2) {
        char t = s[i];
        s[i] = s[i+1];
        s[i+1] = t;
    }
}

void twosort() {
    for (int i=0;i<s.length();i+=2) {
        if (s[i]>s[i+1]) {
            char t = s[i];
            s[i] = s[i+1];
            s[i+1] = t;
        }
    }
}

void perfect() {
    string a = s.substr(0,s.length()/2);
    string b = s.substr(s.length()/2,s.length()/2);
    for (int i=0,j=0;i<s.length();i+=2) {
        s[i]=a[j];
        s[i+1]=b[j];
        j++;
    }
}

int main() {
    cin>>s;
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int in;
        cin>>in;
        switch (in) {
            case 0:
                twoswap();
                break;
            case 1:
                twosort();
                break;
            case 2:
                perfect();
                break;
        }
    }
    cout << s;
}