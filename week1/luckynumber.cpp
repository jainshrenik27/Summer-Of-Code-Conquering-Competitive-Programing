#include <iostream>
using namespace std;

// Returns the luckiness of a number
int luck(int num) {
    int mx = 0, mn = 9;
    while (num) {
        int d = num % 10;
        mx = max(mx, d);
        mn = min(mn, d);
        num /= 10;
    }
    return mx - mn;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int res = l;
        int best = -1;

        for (int x = l; x <= min(r, l + 100); ++x) {
            int cur = luck(x);
            if (cur > best) {
                best = cur;
                res = x;
                if (best == 9) break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
