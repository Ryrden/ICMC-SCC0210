#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pi pair<int,int>
#define minHeap priority_queue<int, vector<int>, greater<int>>
#define maxHeap priority_queue<int>
#define print(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< ' '; cout << endl
#define printArray(arr) for(auto x : arr) cout << x << ' '; cout << endl;
#define printStack(s) while(!s.empty()){cout << s.top() << ' '; s.pop();} cout << endl;
#define printQueue(q) while(!q.empty()){cout << q.front() << ' '; q.pop();} cout << endl;
#define printMap(m) for(auto x : m) cout << x.first << ' ' << x.second << endl;
#define _ << ' ' <<
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+5;

void solve() {
    string q;
    int id,t;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    while(true){
        cin >> q;
        if (q == "#") break;
        cin >> id >> t;
        pq.push(mt(t, id, t));
    }
    int k; cin >> k;
    vector<int> ans;
    for(int i = 0; i < k; i++){
        auto [time, id, interval] = pq.top();
        pq.pop();
        ans.pb(id);
        pq.push(mt(time+interval, id, interval));
    }
    for(int num : ans){
        cout << num << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}