#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin>>n;
    stack<int> stk;
    for (int i=0; i<n; i++) {
        int d;
        cin>>d;
        switch (d) {
            case 1:
                stk.pop();
                break;
            case 2:
                cout << stk.top() << "\n";
                break;
            case 3:
                int a;
                cin >> a;
                stk.push(a);
                break;
            default:
                break;
        }
    }
}