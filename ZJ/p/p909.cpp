#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w;
    cin>>h>>w;
    int origin[w][h];
    for (int i=0;i<w;i++) {
        for (int j=0;j<h;j++) {
            cin>>origin[i][j];
        }
    }
    int change[w*2][h*2];
    for (int i=0;i<w;i++) {
        for (int j=0;j<h;j++) {
            change[i][j] = origin[i][j];
        }
    }
    for (int i=0;i<w;i++) {
        for (int j=h;j<h*2;j++) {
            change[i][j] = origin[i][h*2-1-j];
        }
    }
    for (int i=w;i<w*2;i++) {
        for (int j=0;j<h;j++) {
            change[i][j] = origin[w*2-1-i][j];
        }
    }
    for (int i=w;i<w*2;i++) {
        for (int j=h;j<h*2;j++) {
            change[i][j] = origin[w*2-1-i][h*2-1-j];
        }
    }
    for (int i=0;i<w*2;i++) {
        for (int j=0;j<h*2;j++) {
            cout << change[i][j] << " ";
        }
        cout << "\n";
    }
}