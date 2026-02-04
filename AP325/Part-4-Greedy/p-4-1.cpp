#include <iostream>
using namespace std;
int main() {
    int c[] = {1,5,10,50};
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        int count=0;
        for (int i=3;i>=0;i--){
            while (num>=c[i]) {
                num-=c[i];
                count++;
            }
        }
        cout << count << "\n";
    }
}