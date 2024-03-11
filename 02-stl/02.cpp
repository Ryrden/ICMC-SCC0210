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
#define _ << ' ' <<
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+5;

void solve(int t) {
    int n; cin >> n;
    unordered_map<string, int> m;
    for(int i = 0; i < n; i++){
        string a; int days;
        cin >> a >> days;
        m.insert({a, days});
    }
    int d; cin >> d;
    string task; cin >> task;
    cout << "Case " << t << ": ";
    if (m.find(task) != m.end()){
        int days = m[task];
        if (days <= d){
            cout << "Yesss" << endl;
        }else if (days <= d+5){
            cout << "Late" << endl;
        }else{
            cout << "Do your own homework!" << endl;
        }
    }else{
        cout << "Do your own homework!" << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}