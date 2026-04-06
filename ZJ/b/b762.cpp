#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    int k = 0, d = 0, a = 0;
    int streak = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Get_Kill") {
            k++;
            streak++;
            if (streak < 3) {
                cout << "You have slain an enemie.\n";
            } else if (streak == 3) {
                cout << "KILLING SPREE!\n";
            } else if (streak == 4) {
                cout << "RAMPAGE~\n";
            } else if (streak == 5) {
                cout << "UNSTOPPABLE!\n";
            } else if (streak == 6) {
                cout << "DOMINATING!\n";
            } else if (streak == 7) {
                cout << "GUALIKE!\n";
            } else {
                cout << "LEGENDARY!\n";
            }
        } else if (s == "Get_Assist") {
            a++;
        } else if (s == "Die") {
            d++;
            if (streak >= 3) {
                cout << "SHUTDOWN.\n";
            } else {
                cout << "You have been slained.\n";
            }
            streak = 0;
        }
    }
    cout << k << "/" << d << "/" << a << '\n';
}