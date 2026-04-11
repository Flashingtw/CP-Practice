    #include <iostream>
    using namespace std;
    int main() {
        int n,a,b,c,ans=0;
        cin>>n>>a>>b>>c;
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=n;j++) {
                int last = n - i * a - j * b;
                if (last%c ==0 && last >=0) {
                    ans = max(ans,i + j+ last/c);
                }
            }
        }
        cout << ans << endl;
    }