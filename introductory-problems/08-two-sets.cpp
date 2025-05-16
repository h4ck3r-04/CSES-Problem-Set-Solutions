#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x
#define is_odd(x) ((x) % 2 != 0)
#define is_even(x) ((x) % 2 == 0)
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
    lli total = n * (n + 1) / 2;
    if (total % 2 != 0)
    {
        print("NO");
        return;
    }
    print("YES");
    lli target = total / 2;
    vector<lli> set1, set2;
    for (int i = n; i >= 1; --i)
    {
        if (target >= i)
        {
            set1.push_back(i);
            target -= i;
        }
        else
        {
            set2.push_back(i);
        }
    }
    print(set1.size());
    print_vector(set1);
    print(set2.size());
    print_vector(set2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}