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

void solve()
{
    lli n;
    input(n);
    for (int i = 0; i < n; i++)
    {
        lli a, b;
        input(a);
        input(b);
        if ((2 * a - b) % 3 || (2 * a - b) < 0 || (2 * b - a) % 3 || (2 * b - a) < 0)
        {
            print("NO");
        }
        else
        {
            print("YES");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}