#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> open; // Create a stack to store opening parentheses
        unordered_map<char, char> parentheses = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (const auto &c : s)
        {
            if (parentheses.find(c) != parentheses.end())
            {
                // If the current character is a closing parenthesis
                if (open.empty())
                    return false; // Stack is empty, so it's invalid
                if (open.top() != parentheses[c])
                    return false; // Mismatched opening parenthesis
                open.pop();       // Pop the matched opening parenthesis
            }
            else
            {
                open.push(c); // Push the current character onto the stack
            }
        }

        return open.empty(); // If the stack is empty, it's valid; otherwise, it's not valid
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Example 1: Test with a valid string
    string s1 = "()[]{}";
    bool result1 = solution.isValid(s1);
    cout << "Is s1 valid? " << result1 << endl; // Expected output: true

    // Example 2: Test with an invalid string
    string s2 = "(]";
    bool result2 = solution.isValid(s2);
    cout << "Is s2 valid? " << result2 << endl; // Expected output: false

    return 0;
}
