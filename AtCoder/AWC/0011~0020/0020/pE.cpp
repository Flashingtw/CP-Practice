#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int tree[4*N];//maximum
int v[N];

void push(int idx){
	tree[idx] = max(tree[idx*2],tree[idx*2+1]);
}
void build(int idx,int l,int r){
	if(l==r){
		tree[idx]=v[l];
		return;
	}
	int mid = (l+r)/2;
	build(idx*2,l,mid);
	build(idx*2+1,mid+1,r);
	push(idx);
}
void update(int idx,int l,int r,int pos){
	if(l==r){
		tree[idx] = 0;
		return;
	}
	int mid = (l+r)/2;
	if(pos<=mid) update(idx*2,l,mid,pos);
	else update(idx*2+1,mid+1,r,pos);
	push(idx);
}
//query
int query(int idx,int l,int r,int val){
	if(tree[idx] < val) return 0;
	if(l==r) return l;
	int mid = (l+r)/2;
	if(tree[idx*2]>=val) return query(idx*2,l,mid,val);
	else return query(idx*2+1,mid+1,r,val);
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
    vector<int> book(n);
    for(int i=0;i<n;i++) cin>>book[i];
	for(int i=1;i<=m;i++) cin>>v[i];
	build(1,1,m);
    int ans=0;
	for(int i=0;i<n;i++){
        int num = query(1,1,m,book[i]);
        if(num!=0){
            update(1,1,m,num);
            ans++;
        }
	}
    cout << ans;
}
