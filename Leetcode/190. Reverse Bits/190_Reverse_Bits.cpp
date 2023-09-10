#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = (n >> i) & 1;
            result = result | (bit << (31 - i));
        }
        return result;
    }
};

int main()
{
    Solution sol;
    uint32_t n = 43261596;
    cout << sol.reverseBits(n) << endl;
    return 0;
}