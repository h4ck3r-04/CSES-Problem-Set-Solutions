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

bool is_valid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve()
{
    int n, m;
    input(n >> m);

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        input(grid[i]);
    }

    vector<char> chars = {'A', 'B', 'C', 'D'};
    vector<vector<char>> ans(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            set<char> forbidden;
            forbidden.insert(grid[i][j]);
            if (is_valid(i - 1, j, n, m))
                forbidden.insert(ans[i - 1][j]);
            if (is_valid(i, j - 1, n, m))
                forbidden.insert(ans[i][j - 1]);
            for (char c : chars)
            {
                if (forbidden.find(c) == forbidden.end())
                {
                    ans[i][j] = c;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((is_valid(i - 1, j, n, m) && ans[i][j] == ans[i - 1][j]) ||
                (is_valid(i, j - 1, n, m) && ans[i][j] == ans[i][j - 1]))
            {
                print("IMPOSSIBLE");
                return;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}