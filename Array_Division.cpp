/**********************************𝓙𝓪𝓲 𝓜𝓪𝓱𝓪𝓴𝓪𝓵*******************************

░░░░░██╗░█████╗░██╗  ███╗░░░███╗░█████╗░██╗░░██╗░█████╗░██╗░░██╗░█████╗░██╗░░░░░
░░░░░██║██╔══██╗██║  ████╗░████║██╔══██╗██║░░██║██╔══██╗██║░██╔╝██╔══██╗██║░░░░░
░░░░░██║███████║██║  ██╔████╔██║███████║███████║███████║█████═╝░███████║██║░░░░░
██╗░░██║██╔══██║██║  ██║╚██╔╝██║██╔══██║██╔══██║██╔══██║██╔═██╗░██╔══██║██║░░░░░
╚█████╔╝██║░░██║██║  ██║░╚═╝░██║██║░░██║██║░░██║██║░░██║██║░╚██╗██║░░██║███████╗
░╚════╝░╚═╝░░╚═╝╚═╝  ╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝
**********************************हर हर महादेव**********************************/

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
// template<typename T>
// using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fi first
#define se second
#define ln '\n'
#define Ln '\n'
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define mp make_pair
#define eb emplace_back
#define int long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vs vector<string>
#define mpll map<ll, ll>
#define sz(x) ((ll)(x).size())
#define set_bits __builtin_popcountll
#define umpll unordered_map<ll, ll>
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define fo(m) for (auto &x : m)
#define f0(e) for (ll i = 0; i < e; i++)
#define f1(e) for (ll i = 1; i < e; i++)
#define f0E(e) for (ll i = 0; i <= e; i++)
#define f1E(e) for (ll i = 1; i <= e; i++)
#define fse(i, s, e) for (ll i = s; i < e; i++)
#define fsE(i, s, e) for (ll i = s; i <= e; i++)
#define rfes(i, e, s) for (ll i = e; i > s; i--)
#define rfeS(i, e, s) for (ll i = e; i >= s; i--)
#define yes cout << "YES" << Ln;
#define no cout << "NO" << Ln;
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define precise(ans) cout << fixed << setprecision(15) << ans << ln
#define queue_dec priority_queue<ll>
#define queue_inc priority_queue<ll, vll, greater<ll>>
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Constants
constexpr ll INF = 4e18;
constexpr ld pi = 3.141592653589793238;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1000000007;

// Debugger
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

// Utility functions
template <typename T>
void out(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void out(T &&t, Args &&...args)
{
    cout << t << " ";
    out(forward<Args>(args)...);
}
// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void preSolve()
{
}
/**********************************************************/
//********************START FROM HERE********************//
/********************************************************/
bool checker(vll &v, ll target, ll k)
{
    ll sum = 0;
    ll counter = 1;
    f0(v.size())
    {
        if (sum + v[i] > target)
        {
            counter++;
            sum = v[i];
        }
        else
        {
            sum += v[i];
        }
    }
    return counter <= k;
}

void solve()
{
    // FFFFTTTTTT
    ll n, k;
    cin >> n >> k;
    vll v(n, 0);
    cin >> v;

    ll sum = accumulate(all(v), 0*1LL);
    ll mx = *max_element(all(v));
  
    // cout << mx << " " << sum << endl;
    ll low = mx, high = sum;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        // cout << low << " " << mid << " " << high << endl;
        if (checker(v, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    // return ans;
    cout << ans << ln;
}

int32_t main()
{
    fast_cin();
    cout << setprecision(15) << fixed;
    cerr << fixed << setprecision(10);
    preSolve();
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    //  ll t;
    //  cin >> t;
    //  for(int it=1;it<=t;it++) {
    //	 cout << "Case #" << it << ": ";
    //    solve();
    //  }

    return 0;
}

/*
██╗░░██╗░█████╗░██████╗░  ██╗░░██╗░█████╗░██████╗░  ███╗░░░███╗░█████╗░██╗░░██╗░█████╗░██████╗░███████╗██╗░░░██╗
██║░░██║██╔══██╗██╔══██╗  ██║░░██║██╔══██╗██╔══██╗  ████╗░████║██╔══██╗██║░░██║██╔══██╗██╔══██╗██╔════╝██║░░░██║
███████║███████║██████╔╝  ███████║███████║██████╔╝  ██╔████╔██║███████║███████║███████║██║░░██║█████╗░░╚██╗░██╔╝
██╔══██║██╔══██║██╔══██╗  ██╔══██║██╔══██║██╔══██╗  ██║╚██╔╝██║██╔══██║██╔══██║██╔══██║██║░░██║██╔══╝░░░╚████╔╝░
██║░░██║██║░░██║██║░░██║  ██║░░██║██║░░██║██║░░██║  ██║░╚═╝░██║██║░░██║██║░░██║██║░░██║██████╔╝███████╗░░╚██╔╝░░
╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝  ╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝  ╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚══════╝░░░╚═╝░░░
*/