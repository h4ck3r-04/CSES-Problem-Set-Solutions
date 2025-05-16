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
#define see(x) cin >> x
#define put(x) cout << x << endl
#define rep(i, a, b) for (lli i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()

using lli = long long int;

lli MOD = 1e9 + 7;

string s;
bool vis[7][7];

bool check(lli i, lli j)
{
    lli c = 0;
    if (vis[i][j])
        return 0;
    if (i - 1 >= 0 && !vis[i - 1][j])
        c++;
    if (i + 1 < 7 && !vis[i + 1][j])
        c++;
    if (j - 1 >= 0 && !vis[i][j - 1])
        c++;
    if (j + 1 < 7 && !vis[i][j + 1])
        c++;
    if (i == 6 && j == 0 && c > 0)
        return 0;
    return c < 2;
}

bool trap(lli i, lli j)
{
    lli x = 0, y = 0;
    if (i - 1 >= 0 && !vis[i - 1][j])
        y++;
    if (i + 1 < 7 && !vis[i + 1][j])
        y++;
    if (j - 1 >= 0 && !vis[i][j - 1])
        x++;
    if (j + 1 < 7 && !vis[i][j + 1])
        x++;
    return (x == 0 && y == 2) || (x == 2 && y == 0);
}

lli c = 0;

void rec(lli mv, lli i, lli j)
{
    if (vis[i][j])
        return;
    vis[i][j] = 1;

    lli f = 0;
    if (i == 6 && j == 0)
    {
        if (mv == 48)
            c++;
        else
        {
            vis[i][j] = 0;
            f += 1;
        }
    }
    if (i - 1 >= 0 && j - 1 >= 0)
        f += check(i - 1, j - 1);
    if (i - 1 >= 0 && j + 1 < 7)
        f += check(i - 1, j + 1);
    if (i + 1 < 7 && j + 1 < 7)
        f += check(i + 1, j + 1);
    if (i + 1 < 7 && j - 1 >= 0)
        f += check(i + 1, j - 1);
    f += trap(i, j);

    if (f != 0)
    {
        vis[i][j] = 0;
        return;
    }

    if (mv < 48)
    {
        if (s[mv] == '?')
        {
            if (i - 1 >= 0)
                rec(mv + 1, i - 1, j);
            if (i + 1 < 7)
                rec(mv + 1, i + 1, j);
            if (j - 1 >= 0)
                rec(mv + 1, i, j - 1);
            if (j + 1 < 7)
                rec(mv + 1, i, j + 1);
        }
        else
        {
            if (s[mv] == 'L' && j - 1 >= 0)
                rec(mv + 1, i, j - 1);
            else if (s[mv] == 'R' && j + 1 < 7)
                rec(mv + 1, i, j + 1);
            else if (s[mv] == 'U' && i - 1 >= 0)
                rec(mv + 1, i - 1, j);
            else if (s[mv] == 'D' && i + 1 < 7)
                rec(mv + 1, i + 1, j);
        }
    }

    vis[i][j] = 0;
}

void solve()
{
    see(s);
    rec(0, 0, 0);
    put(c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}