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

lli power(lli a, lli b)
{
    lli res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

lli findDigit(lli N)
{
    lli digits = 1;
    lli base = 9;
    while (N - digits * base > 0)
    {
        N -= digits * base;
        base *= 10;
        digits++;
    }
    lli index = N % digits;
    lli res = power(10, digits - 1) + (N - 1) / digits;
    if (index != 0)
        res = res / power(10, digits - index);
    return res % 10;
}

void solve()
{
    int q;
    input(q);
    while (q--)
    {
        lli k;
        input(k);
        print(findDigit(k));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}