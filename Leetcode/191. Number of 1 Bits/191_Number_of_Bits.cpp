#include <iostream>
#include <cstdint>
#include <cstdio>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n)
        {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;
    return 0;
}