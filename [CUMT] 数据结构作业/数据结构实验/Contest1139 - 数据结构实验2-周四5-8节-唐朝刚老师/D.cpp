#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int ans[N][N];
int n;

int main(){
    cin >> n;
    int count = 1;
    int i = 0, j = 0;
    int dire = 0;
    // 因为走的顺序是右、下、左、上、右……，
    // 是连续且重复的，因此用 dire 表示不同方位。
    while(count <= n * n){
        ans[i][j] = count++;
        if(dire == 0){  // 向右走。
            if(j + 1 >= n || ans[i][j + 1] != 0)
                dire = 1;
        }
        if(dire == 1){  // 向下走。
            if (i + 1 >= n || ans[i + 1][j] != 0)
                dire = 2;
        }
        if(dire == 2){  // 向左走
            if (j - 1 < 0 || ans[i][j - 1] != 0)
                dire = 3;
        }
        if(dire == 3){  // 向上走。
            if (i - 1 < 0 || ans[i - 1][j] != 0)
                dire = 0;
        }
        if(dire == 0) j++;
        else if(dire == 1) i++;
        else if(dire == 2) j--;
        else if(dire == 3) i--;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
