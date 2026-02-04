#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int> enemy,our;
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        enemy.push(num);
    }
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        our.push(num);
    }
    int win = 0;
    while(!our.empty()) {
        while (!enemy.empty()&&enemy.top()>=our.top()) {
            enemy.pop();
        }
        if (enemy.empty()) break;
        win++;
        enemy.pop();
        our.pop();
    }

    cout << win;
}