#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

using lli = long long int;

void solve()
{
    lli n;
    input(n);
    for (int i = 0; i < n; i++)
    {
        lli X, Y;
        input(Y);
        input(X);
        if (Y > X)
        {
            lli ans = (Y - 1) * (Y - 1);
            lli add = 0;
            if (Y % 2 != 0)
            {
                add = X;
            }
            else
            {
                add = 2 * Y - X;
            }
            print(ans + add);
        }
        else
        {
            lli ans = (X - 1) * (X - 1);
            lli add = 0;
            if (X % 2 == 0)
            {
                add = Y;
            }
            else
            {
                add = 2 * X - Y;
            }
            print(ans + add);
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