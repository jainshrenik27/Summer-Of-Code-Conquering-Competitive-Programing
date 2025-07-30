#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    // Initialize base cases
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1]; // characters match
            else
                dp[i][j] = min({ dp[i-1][j] + 1,      // delete
                                 dp[i][j-1] + 1,      // insert
                                 dp[i-1][j-1] + 1 }); // replace
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}
