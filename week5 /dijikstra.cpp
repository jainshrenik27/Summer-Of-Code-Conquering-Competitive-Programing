#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;


using ll = long long;
const ll INF = 1e18;

int main() 

{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);  

  
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);

        adj[v].emplace_back(u, w);  
    }

    // Dijkstra
    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) 
        {
            if (dist[v] > dist[u] + w) {

                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }

        }
    }
    if (dist[n] == INF) {
        cout << -1 << '\n';
        return 0;
    }

  
    vector<int> path;

    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for (int v : path)

        cout << v << " ";

    cout << '\n';

    return 0;
}
