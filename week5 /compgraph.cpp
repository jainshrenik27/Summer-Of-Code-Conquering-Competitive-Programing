#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1005;

struct Edge {
    int u, v;
    long long w;
    bool unknown;
};

int n, m, s, t;
long long L;
vector<Edge> edges;
vector<pair<int, int>> adj[MAXN];  

vector<long long> dijkstra() {
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, idx] : adj[u]) {
            long long w = edges[idx].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m >> L >> s >> t;

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        bool unknown = (w == 0);
        if (unknown) w = 1; 
        edges.push_back({u, v, w, unknown});
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    
    auto dist = dijkstra();
    if (dist[t] < L) {
       
        long long delta = L - dist[t];
        
       
        for (int i = 0; i < m; ++i) {
            if (!edges[i].unknown) continue;
            
            edges[i].w += delta;

            dist = dijkstra();
            if (dist[t] == L) break;

           
            edges[i].w -= delta;
        }

        // Final check
        dist = dijkstra();
        if (dist[t] != L) {
            cout << "NO\n";
            return 0;
        }
    }
    else if (dist[t] > L) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (auto e : edges) {
        cout << e.u << " " << e.v << " " << e.w << "\n";
    }

    return 0;
}
