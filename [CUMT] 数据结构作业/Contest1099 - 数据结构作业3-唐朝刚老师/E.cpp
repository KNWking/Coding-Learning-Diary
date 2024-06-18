#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

struct Student{
    int id;
    int seat;
    string name;
}stu[N];

int main(){
    int n = 0; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> stu[i].id >> stu[i].name >> stu[i].seat;
    }
    int goalid = 0; cin >> goalid;
    for(int i = 0; i < n; ++i){
        if(stu[i].id == goalid){
            cout << stu[i].name << " " << stu[i].seat << endl;
            return 0;
        }
    }
    return 0;
}
