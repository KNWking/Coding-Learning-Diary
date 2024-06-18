#include<bits/stdc++.h> 
using namespace std;  
// 这也是个若至题目。使用标准二分查找不能通过。这是我网上找的代码，懒得重构了。
void halfsearch(int arr[], int len, int index, bool flag) {  
    int count = 1;  
    int low = 0, high = len - 1, mid;  
    int tag = 0;  
    while ((low <= high) && tag == 0) {  
        mid = (low + high) / 2;  
        if (low == high - 1)  
            tag++;  
        if (index > arr[mid] && flag || index < arr[mid] && !flag) {  
            low = mid;  
            count++;  
        } else if (index < arr[mid] && flag || index > arr[mid] && !flag) {  
            high = mid;  
            count++;  
        } else {  
            cout << count << endl;  
            return;  
        }  
    }  
    cout << "NO" << endl;  
    return;  
}  
   
int main() {  
    int n;  
    cin >> n;  
    int* arr = new int[n];  
    int k;  
    for (int i = 0; i < n; i++) {  
        cin >> k;  
        arr[i] = k;  
    }  
    int m;  
    cin >> m;  
    halfsearch(arr, n, m, arr[n - 1] > arr[0]);  
    return 0;  
}
