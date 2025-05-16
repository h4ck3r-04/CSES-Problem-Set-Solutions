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
    if (n == 1)
    {
        print(1);
        return;
    }
    if (n == 2 || n == 3)
    {
        print("NO SOLUTION");
        return;
    }
    for (lli i = 1; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }
    for (lli i = 0; i < n + 1; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
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