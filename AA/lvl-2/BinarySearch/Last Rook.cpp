#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int l = 1 ,r = n,row,col;
    while(l<=r){
        int mid = (l+r)/2;
        cout << '?' << row << " " << row << " " << l << " " << mid << " " << endl;
        int a;
        cin>>a;
        if(a==mid-l+1){
            l = mid+1;       
        }
        else{
            col=mid;
            r = mid-1;
        }
    }
    l = 1,r = n;
    while(l<=r){
        int mid = (l+r)/2;
        cout << '?' << l << " " << mid << " " << 1 << " " << n << " " << endl;
        int a;
        cin>>a;
        if(a==mid-l+1){
            l = mid+1;       
        }
        else{
            row=mid;
            r = mid-1;
        }
    }
    cout << '!' << col << ' ' << row << endl;
}