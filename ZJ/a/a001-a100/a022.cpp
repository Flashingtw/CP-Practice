#include <iostream>
using namespace std;
int main() {
    string a;
    cin>>a;
    int left,right;
    if (a.length()%2!=0) {
        left = a.length()/2-1;
        right = a.length()/2+1;
    }
    else{
        left = a.length()/2-1;
        right = a.length()/2;
    }
    bool t = true;
    while (left>=0&&right<a.length()) {
        if (a[left]==a[right]) {
            left--;
            right++;
        }
        else {
            t=false;
            break;
        }
    }
    cout << (t?"yes":"no");
}