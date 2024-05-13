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

const int MOD = 1e9 + 7;

vector<vector<int>> pessoa_blusa;
vector<vector<int>> dp;
int n, m;

int count_ways(int mask, int blusa_id) {
    if (mask == (1 << n) - 1) {
        return 1;
    }
    
    if (blusa_id > m) {
        return 0;
    }
    
    if (dp[mask][blusa_id] != -1) {
        return dp[mask][blusa_id];
    }
    
    int ans = count_ways(mask, blusa_id + 1);
        
    if (!pessoa_blusa[blusa_id].empty()) {
        for (int person : pessoa_blusa[blusa_id]) {
            if (mask & (1 << person)) {
                continue;
            }
            ans += count_ways(mask | (1 << person), blusa_id + 1);
            ans %= MOD;
        }
    }

    dp[mask][blusa_id] = ans;
    return dp[mask][blusa_id];
}

void solve() {
    cin >> n >> m;
    pessoa_blusa.assign(m + 1, vector<int>());
    dp.assign(1 << n, vector<int>(m + 1, -1));

    for (int person = 0; person < n; ++person) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int blusa;
            cin >> blusa;
            pessoa_blusa[blusa].push_back(person);
        }
    }

    cout << count_ways(0, 1) << endl;
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