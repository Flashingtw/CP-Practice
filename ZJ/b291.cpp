#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string> groundOrder;
    vector<string> animalOrder;
    set<string> animalcheck;
    map<string, map<string, int>> totals;
    for (int i=0;i<n;i++) {
        int num;
        string name,ground;
        cin>>name>>num>>ground;
        if (!totals.count(ground)) {
            groundOrder.push_back(ground);
        }
        if (!animalcheck.count(name)) {
            animalOrder.push_back(name);
            animalcheck.insert(name);
        }
        totals[ground][name]+=num;
    }

    for (auto i : groundOrder) {
        cout << i << " : ";
        for (int j =0,k=0;j<animalOrder.size();j++) {
            if (totals[i].count(animalOrder[j])) {
                if (k!=0) cout << ", ";
                cout << animalOrder[j] << " " << totals[i][animalOrder[j]];
                k++;
            }
        }
        cout << "\n";
    }
}