/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto &a : x)
#define nl '\n'
#define ri(n) \
    int n;    \
    scanf("%d", &n);
#define rll(n) \
    ll n;      \
    scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
    ll inv_count = 0;

    ll i = left;
    ll j = mid;
    ll k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

ll _m_Sort(ll arr[], ll temp[], ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left)
    {

        mid = left + (right - left) / 2;

        inv_count = _m_Sort(arr, temp, left, mid);
        inv_count += _m_Sort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

ll c_swap(ll arr[], ll n)
{
    ll temp[n];
    return _m_Sort(arr, temp, 0, n - 1);
}

int main()
{

    fastIO
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll arr[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll swaps = c_swap(arr, n);

        ll max_allowed = n * (n - 1) / 2 - 1;

        //cout << swaps << " " << max_allowed << nl;
        if (swaps > max_allowed)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }
    return 0;
}
