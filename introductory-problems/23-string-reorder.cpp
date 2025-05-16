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
    string s;
    input(s);
    lli n = s.size();
    sort(s.begin(), s.end());

    set<char> str;
    lli fq[26] = {0};
    for (char c : s)
    {
        fq[c - 'A']++;
        str.insert(c);
    }

    auto it = max_element(fq, fq + 26);
    if (2 * *it - n > 1)
    {
        print(-1);
        return;
    }

    string ans;
    char prev = 'Z' + 1;
    while (2 * *it - n < 1)
    {
        char x = *str.begin();
        str.erase(x);
        ans += x;
        fq[x - 'A']--;
        if (fq[prev - 'A'])
            str.insert(prev);
        prev = x;
        it = max_element(fq, fq + 26);
        n--;
    }

    if (*it)
    {
        string aux;
        char x = (it - fq) + 'A';
        for (int i = 0; i < 26; i++)
            if (i != x - 'A')
                for (int j = 0; j < fq[i]; j++)
                    aux += (char)(i + 'A');
        ans += x;
        for (char c : aux)
        {
            ans += c;
            ans += x;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}