#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DST{
    struct NODE{
        ll val,lazy;
        int lc,rc;
        NODE() : val(0),lazy(0),lc(0),rc(0){}
    };
    vector<NODE> nodes;
    int new_node(){
        nodes.push_back(NODE());
        return nodes.size()-1;
    }
    DST(){
        nodes.clear();
        nodes.push_back(NODE());
    }
    void pull(int idx){
        nodes[idx].val =nodes[nodes[idx].lc].val+nodes[nodes[idx].rc].val;
    }
    void push(int idx,int l,int r){
        if(nodes[idx].lazy==0) return;
        ll lz = nodes[idx].lazy;
        int mid = (l+r)/2;
        if(nodes[idx].lc==0) nodes[idx].lc=new_node();
        if(nodes[idx].rc==0) nodes[idx].rc=new_node();
        nodes[nodes[idx].lc].lazy+=lz;
        nodes[nodes[idx].lc].val+=(ll)(mid-l)*lz;
        nodes[nodes[idx].rc].lazy+=lz;
        nodes[nodes[idx].rc].val+=(ll)(r-mid)*lz;
        nodes[idx].lazy=0;
    }
    void update(int &idx,int l,int r,int ql,int qr,int v){
        if(idx==0) idx = new_node();
        push(idx,l,r);
        if(qr<=l||r<=ql) return;
        if(ql<=l&&r<=qr) {
            nodes[idx].val+=(ll)(r-l)*v;
            nodes[idx].lazy+=v;
            return;
        }
        int mid=(l+r)/2;
        update(nodes[idx].lc,l,mid,ql,qr,v);
        update(nodes[idx].rc,mid,r,ql,qr,v);
        pull(idx);
    }
};
