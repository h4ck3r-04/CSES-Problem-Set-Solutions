#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define is_even(x) ((x) % 2 == 0)
#define is_odd(x) ((x) % 2 != 0)
#define print_vector(v)   \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << endl

using lli = long long int;

lli MOD = 1e9 + 7;

lli mod_pow(lli base, lli exponent)
{
    lli result = 1;
    base %= MOD;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

void solve()
{
    lli n;
    input(n);
    print(mod_pow(2, n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}