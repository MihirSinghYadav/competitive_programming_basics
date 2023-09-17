#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int value = 0;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i][1] == '+')
                value++;
            else
                value--;
        }
        return value;
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Example 1: Test with operations
    vector<string> operations1 = {"--X", "X++", "X++"};
    int result1 = solution.finalValueAfterOperations(operations1);
    cout << "Final value after operations1: " << result1 << endl;

    // Example 2: Test with different operations
    vector<string> operations2 = {"++X", "X++", "X--"};
    int result2 = solution.finalValueAfterOperations(operations2);
    cout << "Final value after operations2: " << result2 << endl;

    return 0;
}