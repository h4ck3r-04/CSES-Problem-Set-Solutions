#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
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
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        print_vector(dist[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}