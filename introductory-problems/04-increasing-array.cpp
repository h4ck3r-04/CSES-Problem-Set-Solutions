#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl;
#define input(x) cin >> x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n;
    input(n);
    long long int moves = 0;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        input(v[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] > v[i])
        {
            moves += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    print(moves);
    return 0;
}