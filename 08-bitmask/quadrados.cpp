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

vector<int> dp;
int tamanho_alvo, total_palitos;

bool can_form_square(vector<int>& palitos, int mask, int current_sum, int count) {
    if (dp[mask] != -1) {
        return dp[mask];
    }
    if (count == 4) {
        return true;
    }
    if (current_sum > tamanho_alvo) {
        return false;
    }
    if (current_sum == tamanho_alvo) {
        return can_form_square(palitos, mask, 0, count + 1);
    }
    bool answer = false;
    for (int i = 0; i < total_palitos; ++i) {
        if (!(mask & (1 << i)) && current_sum + palitos[i] <= tamanho_alvo) {
            if (can_form_square(palitos, mask | (1 << i), current_sum + palitos[i], count)) {
                answer = true;
                break;
            }
        }
    }
    
    dp[mask] = answer;
    return answer;
}

bool _solve(vector<int>& palitos) {
    int sum_palitos = accumulate(palitos.begin(), palitos.end(), 0);
    if (sum_palitos % 4 != 0) {
        return false;
    }
    tamanho_alvo = sum_palitos / 4;
    sort(palitos.rbegin(), palitos.rend());
    total_palitos = palitos.size();
    dp.assign(1 << total_palitos, -1);
    return can_form_square(palitos, 0, 0, 0);
}

bool dfs(vector<int>& palitos, vector<int>& lados, int idx, int tamanho_alvo) {
    if (idx == palitos.size()) {
        return lados[0] == tamanho_alvo && lados[1] == tamanho_alvo && lados[2] == tamanho_alvo && lados[3] == tamanho_alvo;
    }
    for (int i = 0; i < 4; i++) {
        if (lados[i] + palitos[idx] <= tamanho_alvo) {
            lados[i] += palitos[idx];
            if (dfs(palitos, lados, idx + 1, tamanho_alvo)) {
                return true;
            }
            lados[i] -= palitos[idx];
        }
    }
    return false;
}

bool _solve_without_bitmask(vector<int>& palitos) {
    int total = accumulate(all(palitos), 0);
    if (total % 4 != 0) {
        return false;
    }
    int tamanho_alvo = total / 4;
    sort(palitos.rbegin(), palitos.rend());
    vector<int> lados(4, 0);
    return dfs(palitos, lados, 0, tamanho_alvo);
}


void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> palitos(n);
        for (int i = 0; i < n; i++) {
            cin >> palitos[i];
        }
        if (_solve(palitos)) {
            cout << "sim" << endl;
        } else {
            cout << "nao" << endl;
        }
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