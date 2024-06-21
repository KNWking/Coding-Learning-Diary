#include <bits/stdc++.h>

using namespace std;


vector<int> arr{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void directSort() {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

int main() {
    directSort();
    for (auto a: arr)
        cout << a << " ";
    return 0;
}
