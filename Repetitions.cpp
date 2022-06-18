//** Jai Mahakal **//**// हर हर महादेव**//
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ln "\n"
#define Ln "\n"
#define ll long long int
#define ull unsigned long long int
#define vll vector<ll>
#define eb emplace_back
#define pll pair<ll, ll>
#define vpll vector<pll>
#define fi first
#define se second
#define mod 1000000007
#define mp make_pair
#define sz(x) ((ll)(x).size())
#define ppcll __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define fo(m) for (auto &x : m)
#define for0e(e) for (ll i = 0; i < e; i++)
#define for1e(e) for (ll i = 1; i <= e; i++)
#define forse(i, s, e) for (ll i = s; i < e; i++)
#define rfor0s(i, s) for (ll i = s; i >= 0; i--)
#define rforse(i, s, e) for (ll i = s; i >= e; i--)
#define trace1(x) cerr << #x << ": " << x << ln
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << ln
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define precise(ans) cout << fixed << setprecision(15) << ans << ln
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    string s;
    cin >> s;
    ll ans = 1;
    ll temp = 1;
    for (ll i = 1; i < sz(s); i++)
    {
        if(s[i]!=s[i-1]){
            ans = max(temp, ans);
                temp = 1;
        }
        else if(s[i] ==s[i-1]){
            temp++;
        }
    }
     ans = max(temp, ans);
    cout << ans << Ln;
}

int main()
{
    fast_cin();
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    //  ll t;
    //  cin >> t;
    //  for(int it=1;it<=t;it++) {
    //	 cout << "Case #" << it+1 << ": ";
    //    solve();
    //  }

    return 0;
}
//** Har Har Mahadev **//
