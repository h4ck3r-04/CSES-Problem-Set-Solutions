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

void solve()
{
    int n;
    input(n);

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            set<int> used;
            for (int k = 0; k < j; ++k)
            {
                used.insert(grid[i][k]);
            }
            for (int k = 0; k < i; ++k)
            {
                used.insert(grid[k][j]);
            }
            int mex = 0;
            while (used.find(mex) != used.end())
            {
                ++mex;
            }
            grid[i][j] = mex;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        print_vector(grid[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}