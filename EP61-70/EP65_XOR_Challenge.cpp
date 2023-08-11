#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/
// XOR Challenge
int main()
{
    int c;
    cin >> c;
    int bitCount = (int)log2(c) + 1;
    int a = 0, b = 0;
    vector<int> setBits;
    for (int i = 0; i < bitCount; i++)
    {
        if (c & (1 << i))
        {
            setBits.push_back(i);
        }
        else
        {
            a |= (1 << i);
            b |= (1 << i);
        }
    }
    long long answer = -1;
    int s = 1 << setBits.size();
    for (int mask = 0; mask < s; mask++)
    {
        int a2 = a, b2 = b;
        for (int j = 0; j < setBits.size(); j++)
        {
            if (mask & (1 << j))
            {
                a2 |= (1 << setBits[j]);
            }
            else
            {
                b2 |= (1 << setBits[j]);
            }
        }
        answer = max(answer, (long long)a2 * b2);
    }
    cout << answer << endl;
}