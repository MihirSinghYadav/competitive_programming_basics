#include <iostream>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = a ^ b;
        int carry = (unsigned int)(a & b) << 1;
        if (carry != 0)
        {
            return getSum(sum, carry);
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.getSum(1, 2) << endl;
    cout << sol.getSum(-2, 3) << endl;
    cout << sol.getSum(-1, 1) << endl;
    cout << sol.getSum(-1, -1) << endl;
    cout << sol.getSum(0, 0) << endl;
    cout << sol.getSum(0, 1) << endl;
}