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

vector<string> graycode(int n)
{
    vector<string> result;

    for (int i = 0; i < (1 << n); i++)
    {
        int gray = i ^ (i >> 1);
        string code = "";
        for (int j = n - 1; j >= 0; j--)
        {
            code += (gray & (1 << j)) ? '1' : '0';
        }
        result.push_back(code);
    }
    return result;
}

void solve()
{
    lli n;
    input(n);
    print_vector(graycode(n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}