#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n, k, el;
    map<int, int> mp;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        mp[el]++;
    }
    if ((n == 0) or (k == 0) or (2 * k < n))
        return "NO";
    for (auto el : mp)
        if (el.second > 2)
            return "NO";
    return "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif


    int t;
    cin >> t;
    for (int it = 1; it <= t; it++)
        cout << "Case #" << it << ": " << solve() << endl;

    return 0;
    }