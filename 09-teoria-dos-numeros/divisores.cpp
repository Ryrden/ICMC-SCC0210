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

vector<int> primes;

void sieve(int upperbound) {
    int size = upperbound + 1;
    vector<bool> is_prime(size, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= upperbound; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= upperbound; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    for (int p = 2; p <= upperbound; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

void solve() {
    int n; cin >> n;

    map<int, int> factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (n != 1 && (PF * PF <= n)) {
        while (n % PF == 0) {
            n /= PF;
            factors[PF]++;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors[n]++; // caso especial se N for um primo
    int count = 1;
    for (auto &factor : factors) {
        count *= (factor.second + 1);
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef USACO_FILE
    freopen((string(USACO_FILE)+".in").c_str(), "r", stdin);
    freopen((string(USACO_FILE)+".out").c_str(), "w", stdout);
#endif

    int t = 1; cin >> t;
    sieve(1000000);
    while(t--) {
        solve();
    }
    return 0;
}