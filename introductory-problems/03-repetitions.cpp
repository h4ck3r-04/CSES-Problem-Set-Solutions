#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define print(x) cout << x << endl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    long long int maxSize = 1, currSize = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            currSize += 1;
            maxSize = max(maxSize, currSize);
        }
        else
        {
            currSize = 1;
        }
    }
    print(maxSize);
    return 0;
}