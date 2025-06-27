#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr(n); // (value, original_index)
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // store 1-based index
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int target = x - arr[i].first;
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                // Found the triplet
                cout << arr[i].second << " " << arr[left].second << " " << arr[right].second << "\n";
                return 0;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
