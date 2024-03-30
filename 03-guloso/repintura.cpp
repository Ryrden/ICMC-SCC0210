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
#define _ << ' ' <<
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+5;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<char>> wall(n, vector<char>(m));
    int b = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch; cin >> ch;
            if (ch == 'B') b++;
            wall[i][j] = ch;
        }
    }
    
    if (b == 0){
        cout << "0 0" << endl;
        return;
    }

    int line = n;
    int columnFirstAppear = INT_MAX;
    int columnLastAppear = INT_MIN;
    for(int i = 0; i < n; i++){
        bool found = false;
        for(int j = 0; j < m; j++){
            if (wall[i][j] == 'B'){
                line = i;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (wall[j][i] == 'B'){
                columnFirstAppear = min(columnFirstAppear, i);
                columnLastAppear = max(columnLastAppear, i);
            }
        }
    }
    line = n - line;
    cout << line _ columnLastAppear - columnFirstAppear + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}