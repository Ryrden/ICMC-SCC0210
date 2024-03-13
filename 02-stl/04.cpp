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

void solve() {
    int n; cin >> n;
    unordered_map<string, vector<int>> db;
    string name;
    for(int i = 0; i < n; i++){
        cin >> name;
        if (db.find(name) == db.end()){
            db.insert({name, vector<int>()});
            cout << "OK" << endl;
        }else{
            vector<int> existentNames = db[name];
            if (existentNames.size() == 0){
                cout << name << "1" << endl;
                existentNames.pb(1);
                db[name] = existentNames;
            }else{
                int lastNum = existentNames[existentNames.size() - 1];
                cout << name << lastNum + 1 << endl;
                existentNames.pb(lastNum + 1);
                db[name] = existentNames;
            }
        }
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