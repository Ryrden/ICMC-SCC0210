#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define minHeap priority_queue<int, vector<int>, greater<int>>
#define maxHeap priority_queue<int>
#define print(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< ' '; cout << endl
#define printArray(arr) for(auto x : arr) cout << x << ' '; cout << endl;
#define printStack(s) while(!s.empty()){cout << s.top() << ' '; s.pop();} cout << endl;
#define printQueue(q) while(!q.empty()){cout << q.front() << ' '; q.pop();} cout << endl;
#define printMap(m) for(auto x : m) cout << x.first << ' ' << x.second << endl;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define _ << ' ' <<
#define endl '\n'
// #define USACO_FILE 

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+5;

vector<vector<ll>> residual_graph(MAXN, vector<ll>(MAXN));
vector<vector<int>> graph(MAXN);

bool bfs(int source, int sink, vector<int>& parent, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor] && residual_graph[node][neighbor] > 0) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = node;
                if (neighbor == sink) {
                    return true;
                }
            }
        }
    }
    return false;
}

ll ford_fulkerson(int source, int sink, int n) {
    vector<int> parent(n + 1, -1);
    ll max_flow = 0;
    
    while (bfs(source, sink, parent, n)) {
        ll path_flow = LLONG_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        residual_graph[u][v] += c;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    int source = 1, sink = n;
    ll max_flow = ford_fulkerson(source, sink, n);
    cout << max_flow << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef USACO_FILE
    freopen((string(USACO_FILE)+".in").c_str(), "r", stdin);
    freopen((string(USACO_FILE)+".out").c_str(), "w", stdout);
#endif

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}