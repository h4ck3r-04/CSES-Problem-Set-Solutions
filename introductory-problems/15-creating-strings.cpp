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

using lli = long long int;

lli MOD = 1e9 + 7;

set<string> permutations(string s)
{
    set<string> p;
    sort(s.begin(), s.end());
    do
    {
        p.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    return p;
}

void solve()
{
    string s;
    input(s);
    set<string> p = permutations(s);
    print(p.size());
    print_vector_ln(p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}