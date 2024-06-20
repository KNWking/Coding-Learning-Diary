#include <bitsdc++.h>
using namespace std;

string goal;
string pat;
// 理论上需要 KMP 算法，
// 但是因为 OJ 的数据较弱，
// 所以可以使用朴素字符串匹配算法。

int main(){
    cin >> goal >> pat;
    for(int i = 0; i <= goal.size() - pat.size(); ++i){
        int j = 0, k = i;
        for(; j < pat.size(); ++j, ++k){
            if(goal[k] != pat[j])
                break;
        }
        if(j == pat.size()){
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
