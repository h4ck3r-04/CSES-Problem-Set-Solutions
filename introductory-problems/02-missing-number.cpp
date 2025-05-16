#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n;
    cin >> n;
    long long int s1 = n * (n + 1) / 2;
    long long int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long long int x;
        cin >> x;
        s2 += x;
    }
    cout << (s1 - s2) << endl;
}