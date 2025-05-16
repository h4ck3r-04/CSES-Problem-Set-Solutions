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

void ways_count(vector<string> &board, lli row, vector<bool> &occupiedCol,
                vector<bool> &occupiedPrimary, vector<bool> &occupiedSecondary, lli &ans)
{
    if (row == 8)
    {
        ans += 1;
        return;
    }
    for (int col = 0; col < 8; col++)
    {
        if (board[row][col] == '*' || occupiedCol[col] || occupiedPrimary[row - col + 8] || occupiedSecondary[row + col])
        {
            continue;
        }
        occupiedCol[col] = occupiedPrimary[row - col + 8] = occupiedSecondary[row + col] = true;
        ways_count(board, row + 1, occupiedCol, occupiedPrimary, occupiedSecondary, ans);
        occupiedCol[col] = occupiedPrimary[row - col + 8] = occupiedSecondary[row + col] = false;
    }
}

void solve()
{
    vector<string> board(8);
    input_vector(board, 8);
    vector<bool> occupied_col(8, false), occupied_primary(17, false), occupied_secondary(17, false);
    lli ans = 0;
    ways_count(board, 0, occupied_col, occupied_primary, occupied_secondary, ans);
    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}