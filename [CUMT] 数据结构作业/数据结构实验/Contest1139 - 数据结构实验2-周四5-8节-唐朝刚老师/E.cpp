#include <bits/stdc++.h>
using namespace std;

void move(int n, char from, char to, char aux, int& step){
    if(n == 0) return;
    move(n - 1, from, aux, to, step);
    cout << ++step << " " << n << " " << from << "->" << to << endl;
    move(n - 1, aux, to, from, step);
}

int main(){
    int n;
    cin >> n;
    int step = 0;
    move(n, 'A', 'C', 'B', step);
    return 0;
}
