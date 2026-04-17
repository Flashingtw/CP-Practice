#include <bits/stdc++.h>
#include "lib0114.h"
using namespace std;

void Report(int x1, int y1, int x2, int y2, int x3, int y3);

void rec(int x1,int y1,int x2,int y2,int scale,int hx,int hy){
    if(scale==0){
        return;
    }
    int mx = (x1+x2)/2;
    int my = (y1+y2)/2;
    int 
    cx1 = mx,cy1 =my, 
    cx2 = mx,cy2 = my+1,
    cx3 = mx+1,cy3 =my,
    cx4 = mx+1,cy4 = my+1;
    if(hx<=mx&&hy<=my){
        Report(cx2,cy2,cx3,cy3,cx4,cy4);

        rec(x1,y1,mx,my,scale-1,hx,hy);

        rec(x1,my+1,mx,y2,scale-1,cx2,cy2);
        rec(mx+1,y1,x2,my,scale-1,cx3,cy3);
        rec(mx+1,my+1,x2,y2,scale-1,cx4,cy4);
    }
    if(hx<=mx&&hy>my){
        Report(cx1,cy1,cx3,cy3,cx4,cy4);

        rec(x1,my+1,mx,y2,scale-1,hx,hy);
        
        rec(x1,y1,mx,my,scale-1,cx1,cy1);
        rec(mx+1,y1,x2,my,scale-1,cx3,cy3);
        rec(mx+1,my+1,x2,y2,scale-1,cx4,cy4);
    }
    if(hx>mx&&hy<=my){
        Report(cx2,cy2,cx1,cy1,cx4,cy4);

        rec(mx+1,y1,x2,my,scale-1,hx,hy);
        
        rec(x1,y1,mx,my,scale-1,cx1,cy1);
        rec(x1,my+1,mx,y2,scale-1,cx2,cy2);
        rec(mx+1,my+1,x2,y2,scale-1,cx4,cy4);
    }
    if(hx>mx&&hy>my){
        Report(cx2,cy2,cx3,cy3,cx1,cy1);

        rec(mx+1,my+1,x2,y2,scale-1,hx,hy);
        
        rec(x1,y1,mx,my,scale-1,cx1,cy1);
        rec(x1,my+1,mx,y2,scale-1,cx2,cy2);
        rec(mx+1,y1,x2,my,scale-1,cx3,cy3);
    }
}

void solve(int N,int X,int Y){
    rec(1,1,N,N,__lg(N),X,Y);
}