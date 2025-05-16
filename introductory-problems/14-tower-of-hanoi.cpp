#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

using lli = long long int;

lli MOD = 1e9 + 7;

void toh(lli n, lli from_rod, lli to_rod, lli aux_rod)
{
    if (n == 0)
        return;
    toh(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << " " << to_rod << endl;
    toh(n - 1, aux_rod, to_rod, from_rod);
}

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
    print(mod_pow(2, n) - 1);
    toh(n, 1, 3, 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}