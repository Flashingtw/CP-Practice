#include <iostream>
#include <vector>
using namespace  std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for (int i=0;i<n;i++)cin>>v[i];
    v[n] = 0;
    int s=0,best=0,count=0,num=0;
    for (int f=0;f<n;f++) {
        num+=v[f];

        while (num>k) {
            num-=v[s];
            s++;
        }
        if (best<num) {
            best=num;
            count=1;
        }
        else if (best==num){
            count++;
        }
    }
    cout << best << "\n" << count;
}