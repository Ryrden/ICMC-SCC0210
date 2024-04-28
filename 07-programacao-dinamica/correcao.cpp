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

void solve(int t) {
    string str1 = "", str2 = "";
    getline(cin, str1);
    getline(cin, str2);

    int n = str1.size();
    int m = str2.size();
    // matriz (n+1)x(m+1), onde n é o tamanho de str1 e m é o tamanho de str2
    // dp[i][j] é o custo de transformar os primeiros i caracteres de str1 nos primeiros j caracteres de str2
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
    
    // Base da recorrência
    for(int i = 1; i <= n; i++){
        // O custo de transformar os primeiros i caracteres de str1 em uma string vazia é i
        dp[i][0] = i;
    }
    for(int j = 1; j <= m; j++){
        // O custo de transformar uma string vazia nos primeiros j caracteres de str2 é j
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]; // Sem custo se os caracteres são iguais
            }else{
                int sub = dp[i - 1][j - 1]; // Substituição
                int ist = dp[i][j - 1]; // Inserção
                int dlt = dp[i - 1][j]; // Deleção

                dp[i][j] = min({sub, ist, dlt}) + 1;
            }
        }
    }

    cout << dp[n][m] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef USACO_FILE
    freopen((string(USACO_FILE)+".in").c_str(), "r", stdin);
    freopen((string(USACO_FILE)+".out").c_str(), "w", stdout);
#endif

    int t = 1; cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--) {
        solve(t);
    }
    return 0;
}