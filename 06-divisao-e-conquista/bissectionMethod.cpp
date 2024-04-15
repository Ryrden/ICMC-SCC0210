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

void solve() {
    cin >> p >> q >> r >> s >> t >> u;
    
    double l = 0.0;
    double r = 1.0;
    
    if (func(l)*func(r) > 0){
        cout << "Sem solucao" << endl;
        return;
    }
    double x = (l+r)/2;
    while((r-l) > eps){
        x = (l+r)/2;
        if (func(x)*func(l) <= 0){
            r = x;
        }else{
            l = x;
        }
    }
    cout << fixed << setprecision(4) << x << endl; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef USACO_FILE
    freopen((string(USACO_FILE)+".in").c_str(), "r", stdin);
    freopen((string(USACO_FILE)+".out").c_str(), "w", stdout);
#endif

    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}