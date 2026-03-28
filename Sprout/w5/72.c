#pragma GCC optimize("O3,unroll-loops")
#include <stdlib.h>
#include <stdio.h>
typedef long long ll;
int readll(){
    int res = 0;
    char c = getchar_unlocked();
    while(c>='0'&&c<='9'){
        res = res*10+(c-'0');
        c = getchar_unlocked();
    }
    return res;
}
int v[1000001];

int main(){
    int t = readll();
    while(t--){
int n = readll();
    v[0]=readll();
    int chk=1;
    int cur=1;
    for(int i=1;i<n;i++){
        int a=readll();
        if(chk&&a>v[cur-1]){
            v[cur-1]=a;
        }
        else if(chk&&a<v[cur-1]){
            v[cur]=a;
            chk=0;
            cur++;
        }
        else if (!chk&&a>v[cur-1]){
            v[cur]=a;
            chk=1;
            cur++;
        }
        else if (!chk&&a<v[cur-1]){
            v[cur-1]=a;
        }
    }
    printf("%d\n",chk?cur:cur-1);
    }
}