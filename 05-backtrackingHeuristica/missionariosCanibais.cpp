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

int profundidade;

bool isSafe(int ml, int cl, int mr, int cr) {
    return (ml == 0 || ml >= cl) && (mr == 0 || mr >= cr);
}

bool backtrack(int ml, int cl, int mr, int cr, bool margem, int sol){
    if (sol >= profundidade) return false;  // Limitando essa bagaça sifude

    if (ml < 0 || cl < 0 || mr < 0 || cr < 0 || !isSafe(ml, cl, mr, cr)) return false;

    if (ml == 0 && cl == 0 && mr == 3 && cr == 3) {
        profundidade = min(profundidade, sol);
        return true;
    }

    bool found = false;
    if (margem) {
        if(ml >= 1 && cl >= 1) found |= backtrack(ml-1, cl-1, mr+1, cr+1, !margem, sol+1);
        if(cl >= 2) found |= backtrack(ml, cl-2, mr, cr+2, !margem, sol+1);
        if(ml >= 2) found |= backtrack(ml-2, cl, mr+2, cr, !margem, sol+1);
        if(cl >= 1) found |= backtrack(ml, cl-1, mr, cr+1, !margem, sol+1);
        if(ml >= 1) found |= backtrack(ml-1, cl, mr+1, cr, !margem, sol+1);
    } else {
        if(mr >= 1 && cr >= 1) found |= backtrack(ml+1, cl+1, mr-1, cr-1, !margem, sol+1);
        if(cr >= 2) found |= backtrack(ml, cl+2, mr, cr-2, !margem, sol+1);
        if(mr >= 2) found |= backtrack(ml+2, cl, mr-2, cr, !margem, sol+1);
        if(cr >= 1) found |= backtrack(ml, cl+1, mr, cr-1, !margem, sol+1);
        if(mr >= 1) found |= backtrack(ml+1, cl, mr-1, cr, !margem, sol+1);
    }
    return found;
}

void solve() {
    int m, c; bool margem;
    cin >> m >> c >> margem;
    int ml = 0, cl = 0, mr = 0, cr = 0;
    ml = m;
    cl = c;
    if (ml < 3){
        mr = 3 - ml;
    }
    if (cl < 3){
        cr = 3 - cl;
    }
    profundidade = 15;
    if (backtrack(ml, cl, mr, cr, margem, 0)){
        cout << "Profundidade da sol: " << profundidade << endl;
    }else{
        cout << "Nao existe sol" << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef USACO_FILE
    freopen((string(USACO_FILE)+".in").c_str(), "r", stdin);
    freopen((string(USACO_FILE)+".out").c_str(), "w", stdout);
#endif

    int t = 16; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}