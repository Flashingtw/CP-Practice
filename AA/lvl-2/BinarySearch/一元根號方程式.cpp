#include <bits/stdc++.h>
using namespace std;
double sqt(double tar){
    return (tar*tar)+sqrt(tar);
}
int main(){
    double c;
    cin>>c;
    double l = 0,r=c;
    for(int i=0;i<100;i++){
        double mid = (l+r)/2;
        if(sqt(mid)>=c){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << fixed << setprecision(15) << (l+r)/2;
}