#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    while (true) {
        int N;
        cin>>N;
        if (N==0) break;
        bool tp = false;
        while (true) {
            queue<int> st_input{};
            for (int i=0;i<N;++i) {
                st_input.push(i+1);
            }
            queue<int> st_output{};
            for (int i=0;i<N;i++) {
                int a;
                cin>>a;
                if (a==0) {
                    tp=true;
                    break;
                }
                st_output.push(a);
            }
            if (tp) break;
            stack<int> sta{};
            while (!st_output.empty()) {
                if (!st_input.empty() && st_input.front() == st_output.front()) {
                    st_input.pop();
                    st_output.pop();
                }
                else if (!sta.empty() && sta.top() == st_output.front()) {
                    sta.pop();
                    st_output.pop();
                }
                else if (!st_input.empty()) {
                    sta.push(st_input.front());
                    st_input.pop();
                }
                else {
                    break;
                }
            }
            cout << (st_output.empty()?"Yes\n":"No\n");
        }
        cout << endl;
    }
}