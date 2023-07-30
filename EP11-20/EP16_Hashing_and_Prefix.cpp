#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int hashTable[N][26] = {0};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            hashTable[i + 1][s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hashTable[j][i] += hashTable[j - 1][i];
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int oddCount = 0;
            for (int i = 0; i < 26; i++)
            {
                int charCount = hashTable[r][i] - hashTable[l - 1][i];
                if (charCount % 2 != 0)
                {
                    oddCount++;
                }
            }
            if (oddCount > 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
}