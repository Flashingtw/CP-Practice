#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;

int prv_n[N],nxt_n[N];
int isin[N];

void init(int x,int prv,int nxt,int ins){
    prv_n[x] = prv;
    nxt_n[x] = nxt;
    isin[x] = ins;
}

//idx 插到 x 後面
void insert(int x,int idx){
    int nxt = nxt_n[x];
    init(idx,x,nxt,1);
    prv_n[nxt] = idx;
    nxt_n[x] = idx;
}

void del(int x){
    int prv = prv_n[x];
    int nxt = nxt_n[x];
    prv_n[nxt] = prv;
    nxt_n[prv] = nxt;
    isin[x] = 0;
}

int main(){
    int m;
    cin>>m;
    init(0,0,0,1);//0 虛擬節點 :  0<-0->0
    for(int i=0;i<m;i++){
        int type,n;
        cin>>type>>n;
        if(type==1){
            insert(0,n);//n插入0後面: n<->0<->n<->0
        }
        if(type==2){//                                         n
            insert(prv_n[0],n); //n插入 0前面的節點 的後面  end->|<-0
        }
        if(type==3){
            int a;
            cin>>a;
            //n插入a前面 == a的前面的節點 後面 插入n
            if(isin[a]) insert(prv_n[a],n);
            else cout << "peko" << '\n';
        }
        if(type==4){
            int a;
            cin>>a;
            //n插入a後面
            if(isin[a]) insert(a,n);
            else cout << "peko" << '\n';
        }
        if(type==5){
            if(isin[n]){
                if(prv_n[n]==0) cout << "NULL" << '\n';
                else cout << prv_n[n] << '\n';
            }
            else cout << "peko" << '\n';
        }
        if(type==6){
            if(isin[n]){
                if(nxt_n[n]==0) cout << "NULL" << '\n';
                else cout << nxt_n[n] << '\n';
            }
            else cout << "peko" << '\n';
        }
        if(type==7){
            if(isin[n]){
                del(n);
            }
            else cout << "peko" << '\n';
        }
    }
}