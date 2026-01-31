    #include <iostream>
    using namespace std;
    int main() {
        ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int R,C;
        double s=0;
        int per;

        cin>>R>>C;
        int arr[R][C];
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                cin>>arr[i][j];
            }
        }
        int arr2[R][C];
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                cin>>arr2[i][j];
                if (arr2[i][j]==arr[i][j]) s++;
            }
        }
        per = static_cast<int>(s / (R * C) * 100);
        //rot180

        int rot180[R][C];
        s = 0;
        for(int i=R;i>0;i--) {
            for(int j=C;j>0;j--) {
                rot180[i-1][j-1]=arr[R-i][C-j];
                if (rot180[i-1][j-1]==arr2[i-1][j-1]) s++;
            }
        }
        per = max(per , static_cast<int>(s / (R * C) * 100));

        if (R==C) {
            int rot90[R][R];
            s = 0;
            for (int i=0;i<R;i++) {
                for (int j=0;j<R;j++) {
                    rot90[i][R-1-j]=arr[i][j];
                    if (rot90[i][R-1-j]==arr2[i][R-1-j]) s++;
                }
            }
            per = max(per , static_cast<int>(s / (R * C) * 100));
            s=0;
            int rot270[R][R];
            for (int i=0;i<R;i++) {
                for (int j=0;j<R;j++) {
                    rot270[R-j-1][i]=arr[i][j];
                    if (rot270[R-j-1][i]==arr2[R-j-1][i]) s++;
                }
            }
            per = max(per , static_cast<int>(s / (R * C) * 100));
        }
        cout << per << "%"<<endl;
        return 0;
    }