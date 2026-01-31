#include <iostream>
#include <map>
#include <vector>

using namespace std;
int min_point = 1e9;
vector<vector<int>> rect;
void del(int x1,int x2,int y1,int y2,int val){
    if (x2-x1<=1||y2-y1<=1) {
        min_point = min(min_point,val);
        return;
    }
    map<int,int> mp;
    for (int j=x1;j<x2;j++) {
        mp[rect[y1][j]] ++;
    }
    del(x1,x2,y1+1,y2,val+min(mp[0],mp[1]));
    mp[0]=0;
    mp[1]=0;
    for (int j=x1;j<x2;j++) {
        mp[rect[y2-1][j]] ++;
    }
    del(x1,x2,y1,y2-1,val+min(mp[0],mp[1]));
    mp[0]=0;
    mp[1]=0;
    for (int i=y1;i<y2;i++) {
        mp[rect[i][x1]] ++;
    }
    del(x1+1,x2,y1,y2,val+min(mp[0],mp[1]));
    mp[0]=0;
    mp[1]=0;
    for (int i=y1;i<y2;i++) {
        mp[rect[i][x2-1]] ++;
    }
    del(x1,x2-1,y1,y2,val+min(mp[0],mp[1]));
}

int main() {
    int x,y;
    cin>>y>>x;
    rect.resize(y,vector<int>(x));
    for (int i=0;i<y;i++) {
        for (int j=0;j<x;j++) {
            cin>>rect[i][j];
        }
    }
    del(0,x,0,y,0);
    cout << min_point;
}