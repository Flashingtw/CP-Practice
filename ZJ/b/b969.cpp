#include <bits/stdc++.h>

using namespace std;

int main() {
    string line, name, greeting;
    vector<string> names;
    
    getline(cin, line);
    stringstream ss(line);
    while (ss >> name) {
        names.push_back(name);
    }
    
    getline(cin, greeting);
    
    for (int i = 0; i < names.size(); i++) {
        cout << greeting << ", " << names[i] << '\n';
    }
}