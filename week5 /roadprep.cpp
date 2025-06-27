#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN];
int comp_size[MAXN];

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB)
        return false;
    if (comp_size[rootA] < comp_size[rootB])
        swap(rootA, rootB);
    parent[rootB] = rootA;
    comp_size[rootA] += comp_size[rootB];
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;  // (cost, a, b)
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }

    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        comp_size[i] = 1;
    }

    
    sort(edges.begin(), edges.end());
    long long total_cost = 0;
    int edges_used = 0;

    for (auto [cost, a, b] : edges) {
        if (unite(a, b)) {
            total_cost += cost;
            edges_used++;
            if (edges_used == n - 1)
                break;
        }
    }

    if (edges_used == n - 1)
        cout << total_cost << "\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}
