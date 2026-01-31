#include <iostream>
using namespace std;
long long eval() {
    string n;
    cin>>n;
    if (n=="f") {
        return eval()*2-1;
    }
    if (n=="g") {
        return eval()+eval()*2-3;
    }
    return stoi(n);
}

int main() {
    cout << eval() << endl;
}
