#include <bits/stdc++.h>
using namespace std;

vector<int> vec1;
vector<int> vec2;
vector<int> ans;

void read1(){
  // 这部分可以注意一下。
    int tmp = 0;
    while(cin.peek() != '\n' && cin >> tmp)
        vec1.push_back(tmp);
    cin.ignore();
}

void read2(){
    int tmp = 0;
    while(cin.peek() != '\n' && cin >> tmp)
        vec2.push_back(tmp);
    cin.ignore();
}

int main(){
    read1();
    read2();
    auto iter1 = vec1.begin();
    auto iter2 = vec2.begin();
    while(iter1 != vec1.end() && iter2 != vec2.end()){
        if(*iter1 <= *iter2){
            ans.push_back(*iter1);
            iter1++;
        }else{
            ans.push_back(*iter2);
            iter2++;
        }
    }
    while(iter1 != vec1.end()){
      // 处理剩余部分。
        ans.push_back(*iter1);
        ++iter1;
    }
    while(iter2 != vec2.end()){
        ans.push_back(*iter2);
        ++iter2;
    }
    for(auto iter = ans.begin(); iter != ans.end(); ++iter){
        cout << *iter << (next(iter) == ans.end() ? '\n' : ' ');
    }
    return 0;
}
