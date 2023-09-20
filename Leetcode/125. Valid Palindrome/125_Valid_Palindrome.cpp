#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            // Skip non-alphanumeric characters from the left
            while (!isalnum(s[left]) && left < right)
                left++;

            // Skip non-alphanumeric characters from the right
            while (!isalnum(s[right]) && right > left)
                right--;

            // Compare characters while ignoring case
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Example 1: Test with a palindrome string
    string s1 = "A man, a plan, a canal, Panama";
    bool result1 = solution.isPalindrome(s1);
    cout << "Is s1 a palindrome? " << boolalpha << result1 << endl; // Expected output: true

    // Example 2: Test with a non-palindrome string
    string s2 = "race a car";
    bool result2 = solution.isPalindrome(s2);
    cout << "Is s2 a palindrome? " << boolalpha << result2 << endl; // Expected output: false

    return 0;
}
