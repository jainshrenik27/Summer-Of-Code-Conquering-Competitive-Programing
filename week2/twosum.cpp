#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> arr(n); 

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = {a, i + 1};
    }

    sort(arr.begin(), arr.end()); // sort based on value

    int i = 0, j = n - 1;
    bool found = false;

    while (i < j) {
        int sum = arr[i].first + arr[j].first;
        if (sum == x) {
            cout << arr[i].second << " " << arr[j].second << "\n";
            found = true;
            break;
        } else if (sum < x) {
            i++;
        } else {
            j--;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
