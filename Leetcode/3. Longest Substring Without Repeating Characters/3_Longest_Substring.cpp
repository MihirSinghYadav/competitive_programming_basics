#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string &s)
    {
        // Create an unordered_set to store unique characters in the current substring
        unordered_set<char> chars;

        // Initialize variables to keep track of maximum substring size and two pointers (i and j)
        int maxSize = 0;
        int i = 0, j = 0;

        // Loop through the characters of the input string
        while (j < s.size())
        {
            // Check if the current character s[j] is already in the chars set (indicating a repeating character)
            while (chars.find(s[j]) != chars.end())
            {
                // Remove the leftmost character from the chars set and move the left pointer (i) to the right
                chars.erase(s[i]);
                i++;
            }

            // Update maxSize with the maximum of its current value and the length of the current substring
            maxSize = max(maxSize, j - i + 1);

            // Add the current character s[j] to the chars set, extending the current substring
            chars.insert(s[j]);
            j++;
        }

        // Return the length of the longest substring without repeating characters
        return maxSize;
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Example 1: Test with a string
    string s1 = "abcabcbb";
    int result1 = solution.lengthOfLongestSubstring(s1);
    cout << "Length of the longest substring in s1: " << result1 << endl;

    // Example 2: Test with another string
    string s2 = "bbbbb";
    int result2 = solution.lengthOfLongestSubstring(s2);
    cout << "Length of the longest substring in s2: " << result2 << endl;

    return 0;
}
