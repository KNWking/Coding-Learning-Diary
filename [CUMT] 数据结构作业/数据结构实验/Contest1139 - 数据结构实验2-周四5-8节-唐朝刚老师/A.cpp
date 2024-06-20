#include <bitsdc++.h>
using namespace std;

string s;

int main(){
    while(cin >> s){
        int n = s.size();
        cout << (n*(n+1)) / 2 + 1 << endl;
    }
    return 0;
}
