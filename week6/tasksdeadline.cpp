#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tsk(n); 

    for (int i = 0; i < n; ++i) {
        int dur, dedline;  
        cin >> dur >> dedline;
        tsk[i] = {dur, dedline};
    }

    sort(tsk.begin(), tsk.end()); 

    long long tm = 0, rew = 0; 
    for (int i = 0; i < n; ++i) {
        tm += tsk[i].first;
        rew += tsk[i].second - tm;
    }

    cout << rew << "\n";
    return 0;
}
