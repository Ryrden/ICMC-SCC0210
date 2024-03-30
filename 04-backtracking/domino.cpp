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
// #define USACO_FILE 

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+5;

bool is_possible(map<string, int> pieces, int origin, int dest, int k){
    if (k == 0 && origin == dest){
        return true;
    }
    if (k > 0){
        for(auto [piece, count] : pieces){
            int left = piece[0] - '0';
            int right = piece[1] - '0';
            
            if (origin == left && count > 0) {
                pieces[piece]--;
                if (is_possible(pieces, right, dest, k - 1)){
                    return true;
                }
                pieces[piece]++;
            }else if (origin == right && count > 0){
                pieces[piece]--;
                if (is_possible(pieces, left, dest, k - 1)){
                    return true;
                }
                pieces[piece]++;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    while(true){
        cin >> n;
        if (n == 0){
            break;
        }
        int m; cin >> m;
        int left_1, left_2, right_1, right_2;
        cin >> left_1 >> left_2;
        cin >> right_1 >> right_2; 

        map<string, int> pieces;
        for(int i = 0; i < m; i++){
            string a,b;
            cin >> a >> b;
            pieces[string(a+b)]++;
        }  
        cout << (is_possible(pieces, left_2, right_1, n) ? "YES" : "NO") << endl;
    }
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