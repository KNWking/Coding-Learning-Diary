#include <bits/stdc++.h>

using namespace std;

const double esp = 1e-8;

double n;

int main() {
    cin >> n;
    double l = 0, r = 0;
    if (n > 0) {
        if (n <= 1) {
            r = 1;
        } else {
            r = n;
        }
    } else {
        if (n >= -1) {
            l = -1;
        } else {
            l = n;
        }
    }
    while (fabs(l - r) > esp) {
        double mid = (l + r) / 2;
        if (mid * mid * mid > n) {
            r = mid;
        } else if (mid * mid * mid < n) {
            l = mid;
        } else {
            cout << fixed << setprecision(6) << mid << endl;
            return 0;
        }
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}
