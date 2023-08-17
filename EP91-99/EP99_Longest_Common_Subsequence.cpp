#include <iostream>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/
int dp[1005][1005];
int lcs(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // remove 1 char from s1
    int ans = lcs(i - 1, j, s1, s2);
    // remove 1 char from s2
    ans = max(ans, lcs(i, j - 1, s1, s2));
    // remove 1 char from both s1 and s2
    ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}
// Time Complexity: O(n*m)

int longestCommonSubsequence(string text1, string text2)
{
    memset(dp, -1, sizeof(dp));
    return lcs(text1.size() - 1, text2.size(), text1, text2);
}

int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1, text2) << endl;
}
/*
Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

*/