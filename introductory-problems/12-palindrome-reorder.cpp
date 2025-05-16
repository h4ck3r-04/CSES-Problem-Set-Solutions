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

void solve()
{
    string s;
    input(s);
    lli n = s.length();
    int freq[26] = {};
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'A'] += 1;
    }

    int cnt = 0;
    for (int j = 0; j < 26; j++)
    {
        if (is_odd(freq[j]))
        {
            cnt += 1;
        }
    }

    if (cnt > 1)
    {
        print("NO SOLUTION");
        return;
    }

    string ans(n, ' ');
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (freq[s[i] - 'A'] % 2 == 1)
        {
            ans[n / 2] = s[i];
            freq[s[i] - 'A'] -= 1;
        }
        while (freq[s[i] - 'A'] > 0)
        {
            ans[left++] = ans[right--] = s[i];
            freq[s[i] - 'A'] -= 2;
        }
    }
    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}