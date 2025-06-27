#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN];
int comp_size[MAXN];
int components;
int max_size = 1;

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]); 
    return parent[x];
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
       
        if (comp_size[rootA] < comp_size[rootB])
            swap(rootA, rootB);
        parent[rootB] = rootA;
        comp_size[rootA] += comp_size[rootB];
        max_size = max(max_size, comp_size[rootA]);
        components--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    components = n;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        comp_size[i] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        cout << components << " " << max_size << "\n";
    }

    return 0;
}
