#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<int, int> p32;

typedef pair<ll, ll> p64;

typedef pair<double, double> pdd;

typedef vector<ll> v64;

typedef vector<int> v32;

typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)

#define rforn(i, s) for (ll i = s; i >= 0; i--)

#define rforsn(i, s, e) \
    for (ll i = s; i >= e; i--)

#define ln "\n"

#define all(x) (x).begin(), (x).end()

#define se second

#define mp make_pair

#define pb push_back

#define dbg(x) cout << #x << " = " << x << ln

#define py cout << "YES\n";

#define INF 2e18

ll MOD = 10e9 + 7;

#define fi first

#define sz(x) ((ll)(x).size())

#define pn cout << "NO\n";

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

//---------- Ayush Rudani ----------//

/*

????   ???? ???  ??     ??
??????????????????????????
??????????????????????????
??????????????????????????
   ???

 */

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
            return nullptr;
        auto slow = head, fast = head->next->next;
        while (fast != nullptr and fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    v32 arr(n);
    forsn(i, 1, n + 1) cin >> arr[i];

    v32 suff(n + 1, 0);
    v32 pre(n + 1, 0);

    forsn(i, 2, n + 1)
    {
        int isp = (arr[i] - arr[i + 1]);
        suff[i] = (isp > 0) ? suff[i] + isp : suff[i - 1];
    }

    rforsn(i, n + 1, 1)
    {
        int isp = (arr[i] - arr[i - 1]);
        pre[i] = (isp > 0) ? pre[i] + isp : pre[i - 1];
    }

    for (int k = 0; k < m; k++)
    {
        ll s, e, ans = 0;
        cin >> s >> e;
        if (s < e)
        {
            for (int i = s; i < e; i++)
            {
                if (arr[i] - arr[i + 1] > 0)
                    ans += (arr[i] - arr[i + 1]);
            }
        }
        if (s > e)
        {
            for (int i = s; i > e; i--)
            {
                if (arr[i] - arr[i - 1] > 0)
                    ans += (arr[i] - arr[i - 1]);
            }
        }
        cout << ans << endl;
    }
}

class Solution3
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> ans;
        int m = rounds.size();

        if (rounds[0] <= rounds[m - 1])
        {
            for (int i = rounds[0]; i <= rounds[m - 1]; i++)
                ans.push_back(i);
            return ans;
        }
        else
        {
            for (int i = 1; i <= rounds[m - 1]; i++)
                ans.push_back(i);
            for (int i = rounds[0]; i <= n; i++)
                ans.push_back(i);
        }
        return ans;
    }
};

class Solution5
{
public:
    void addIPs(vector<string> &ans, string s, int octets, string ip)
    {
        if (!octets)
        {
            if (s.empty())
                ans.push_back(ip);
            return;
        }
        if (!ip.empty())
            ip += ".";
        for (int i = 1; i <= (int)s.size() - octets + 1; i++)
        {
            if (stoi(s.substr(0, i)) > 255 || (i > 1 && s.substr(0, i)[0] == '0'))
                return;
            addIPs(ans, s.substr(i),
                   octets - 1, ip + s.substr(0, i));
        }
    }
    vector<string> genIp(string &s)
    {
        vector<string> ans;
        addIPs(ans, s, 4, "");
        if (ans.empty())
            ans.push_back("-1");
        return ans;
    }
};

class Solution2
{
public:
    void dfs(unordered_map<int, vector<int>> &m, vector<bool> &vis, int curr)
    {
        vis[curr] = true;
        for (auto it : m[curr])
            if (!vis[it])
                dfs(m, vis, it);
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        int count = 0;
        vector<bool> vis(V, false);
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < adj[0].size(); i++)
        {
            for (int j = 0; j < adj[0].size(); j++)
                if (adj[i][j] == 1)
                    m[i].push_back(j);
        }

        for (auto it : m)
        {
            if (!vis[it.first])
            {
                dfs(m, vis, it.first);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    fast_cin();
    // sieve();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
