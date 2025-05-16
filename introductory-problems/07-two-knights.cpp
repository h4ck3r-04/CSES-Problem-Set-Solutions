#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

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
    lli k;
    input(k);
    for (int i = 1; i < k + 1; i++)
    {
        lli ways = (mod_pow(i, 2) * (mod_pow(i, 2) - 1)) / 2;
        lli attacks = 4 * (i - 1) * (i - 2);
        ways = ways - attacks;
        print(ways);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}