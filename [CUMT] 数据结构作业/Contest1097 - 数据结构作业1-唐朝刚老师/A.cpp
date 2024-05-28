#include <bits/stdc++.h>
using namespace std;

const int N= 1e4 + 10;

struct Student{
    string id;
    int score;
}stu[N];

int main() {
    ios::sync_with_stdio(false);
    int n = 0; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> stu[i].id >> stu[i].score;
    }
    string search; cin >> search;
    for(int i = 0; i < n; ++i){
        if(stu[i].id == search){
            cout << stu[i].score << endl;
            break;
        }
    }
    return 0;
}
