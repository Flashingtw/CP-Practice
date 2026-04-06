#include <iostream>
using namespace std;
int main() {
    int p,d,t,c;
    cin>>p>>d>>t>>c;
    if ((d>=30&&!c)||(d<=15&&c)) {
        p-=5;
    }
    if ((t>=7&&t<10)||(t>=14&&t<16)) {
        p-=5;
    }
    cout << p;
}