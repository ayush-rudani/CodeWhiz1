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
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define INF 2e18
#define fast_cin()                    \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                    \
cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

//---------- Ayush Rudani ----------//

map<string, char> aph = {{"1", 'a'},
{"2", 'b'},
{"3", 'c'},
{"4", 'd'},
{"5", 'e'},
{"6", 'f'},
{"7", 'g'},
{"8", 'h'},
{"9", 'i'},
{"10", 'j'},
{"11", 'k'},
{"12", 'l'},
{"13", 'm'},
{"14", 'n'},
{"15", 'o'},
{"16", 'p'},
{"17", 'q'},
{"18", 'r'},
{"19", 's'},
{"20", 't'},
{"21", 'u'},
{"22", 'v'},
{"23", 'w'},
{"24", 'x'},
{"25", 'y'},
{"26", 'z'}};

void solve()
{
    ll n;
    cin >> n;
    string c;
    cin >> c;

    string res = "";

    rforn(i, n - 1)
    {
        if (c[i] == '0')
        {
            string ch = "";
            ch += c[i - 2];
            ch += c[i - 1];

            // reverse(all(ch));
            // dbg(ch);
            res += aph[ch];
            i -= 2;
        }
        else
        {
            string ch = "";
            ch += c[i];
            res += aph[ch];
        }
    }
    reverse(all(res));

    cout << res << ln;
}


int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}