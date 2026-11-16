#include<bits/stdc++.h>
using namespace std;
int h;
int n1[15][15];
int a[30],b[30];
int cut[15];
int mx=0;
int ans;
void count(int idx){
    if (idx>=h)
    {
        if(ans>=mx){mx=ans;}
        return;}
    for (int i = 0; i < h; i++)
    {
        if (cut[i]||a[idx+i]||b[i-idx+15]) {
            continue;
        }
        a[idx+i]++;
        b[i-idx+15]++;
        cut[i]++;
        ans+=n1[idx][i];
        count(idx+1);
        a[idx+i]--;
        ans-=n1[idx][i];
        b[i-idx+15]--;
        cut[i]--;
    }
    count(idx+1);
}
int main(){
    cin>>h;
    for (int i = 0; i < h; i++)
    {
        for (int s1=0;s1<h; s1++)
        {
            cin>>n1[i][s1];
        }
        
    }
    ans=0;
    count(0);
    cout<<mx;
}