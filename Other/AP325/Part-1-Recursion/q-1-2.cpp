#include <iostream>
using namespace std;
long long eval() {
    string n;
    cin>>n;
    if (n=="f") {
        return eval()*2-3;
    }
    if (n=="g") {
        return eval()*2+eval()-7;
    }
    if (n=="h") {
        return eval()*3-eval()*2+eval();
    }
    return stoi(n);
}

int main() {
    cout << eval() << endl;
}
