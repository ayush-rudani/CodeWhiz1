#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define ln "\n"

void solve(int it)
{
    int r, c;
    cin >> r >> c;
    bool ok = true;
    bool anyOne = false;

    vector<vector<char>> arr(r, vector<char>(c));
    vector<vector<char>> ans(r, vector<char>(c));

    forn(i, r) forn(j, c) cin >> arr[i][j];
    forn(i, r)
    {
        forn(j, c)
        {
            ans[i][j] = arr[i][j];
            if (arr[i][j] == '^')
                anyOne = true;
            if (arr[i][j] == '#')
            {
                for (int i=-1; i>=1 and i!=0; i++)
                {
                    for(int j=-1; j<=1 and j!=0)
                        
                }

            }
        }
    }


    // dbg((r == 1 || c == 1));
    if (anyOne and (r == 1 || c == 1))
        ok = false;
    else if ((r == 1 || c == 1) and (!anyOne))
        ok = true;

    if (ok == false)
    {
        cout << "Case #" << it << ": "
             << "Impossible" << ln;
    }
    else
    {
        cout << "Case #" << it << ": "
             << "Possible" << ln;
        if (anyOne)
        {
            forn(i, r)
            {
                forn(j, c) cout << '^';
                cout << ln;
            }
        }
        else if (!anyOne)
        {
            forn(i, r)
            {
                forn(j, c) cout << '.';
                cout << ln;
            }
        }
    }
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


    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve(it);
    }

    return 0;
}