#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

// Disjoint Set Union 
class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
bool merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return false;
    parent[rootX] = rootY;
    return true;
}

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        ll p;
        cin >> n >> p;

        vector<ll> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        
        DisjointSet dsu(n);

       
        vector<bool> isConnected(n - 1, false);

      
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int i, int j) {
            return arr[i] < arr[j];
        });

        ll totalWeight = 0;

        for (int i : order) {
            
            if (arr[i] >= p) break;

            for (int j = i - 1; j >= 0; --j) {
                if (arr[j] % arr[i] != 0) break;
                if (dsu.merge(i, j)) {
                    totalWeight += arr[i];
                    isConnected[j] = true;
                } else {
                    break; 
                }
            }

          
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] % arr[i] != 0) break;
                if (dsu.merge(i, j)) {
                    totalWeight += arr[i];
                    isConnected[j - 1] = true;
                } else {
                    break;
                }
            }
        }

       
        for (int i = 0; i < n - 1; ++i) {
            if (!isConnected[i] && dsu.merge(i, i + 1)) {
                totalWeight += p;
            }
        }

        cout << totalWeight << '\n';
    }

    return 0;
}
