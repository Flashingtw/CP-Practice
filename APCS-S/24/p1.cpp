#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,speed=0;
    cin>>n;
    for (int i=0;i<n;i++) {
        char in;
        cin>>in;
        if (in=='S') speed+=5;
        if (speed==0&&in=='B') {
            cout << "Sheep are u serious??";
            return 0;
        }
        if (speed!=0&&in=='G') speed+=1;
        if (speed!=0&&in=='B') speed-=3;
        speed = max(speed,0);
    }
    cout << speed;
}