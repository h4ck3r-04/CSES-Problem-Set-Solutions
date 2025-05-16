#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define is_even(x) ((x) % 2 == 0)
#define is_odd(x) ((x) % 2 != 0)
#define print_vector(v)   \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << endl
#define print_vector_ln(v) \
    for (auto &x : v)      \
        cout << x << endl; \
    cout << endl
#define input_vector(v, n)        \
    for (int i = 0; i < (n); ++i) \
        cin >> v[i];

using lli = long long int;

lli MOD = 1e9 + 7;

lli divide(int idx, vector<lli> *arr, lli sum1, lli sum2, lli N)
{
    if (idx == N)
    {
        return abs(sum1 - sum2);
    }
    lli choose = divide(idx + 1, arr, sum1 + (*arr)[idx], sum2, N);
    lli notChoose = divide(idx + 1, arr, sum1, sum2 + (*arr)[idx], N);
    return min(choose, notChoose);
}

void solve()
{
    lli n;
    input(n);
    vector<lli> v(n);
    input_vector(v, n);
    lli sum1 = 0;
    lli sum2 = 0;
    lli ans = divide(0, &v, sum1, sum2, v.size());
    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}