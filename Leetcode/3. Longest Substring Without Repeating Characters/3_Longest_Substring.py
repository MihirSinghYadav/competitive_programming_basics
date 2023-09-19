class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Initialize an empty set to store unique characters in the current substring
        charSet = set()
        # Initialize two pointers: left (start of substring) and result (maximum substring length)
        left = 0
        result = 0

        # Loop through the characters of the input string from left to right
        for right in range(len(s)):
            # Check if the current character s[right] is already in the charSet (indicating a repeating character)
            while s[right] in charSet:
                # Remove the leftmost character from the charSet and move the left pointer to the right
                charSet.remove(s[left])
                left += 1

            # Add the current character s[right] to the charSet, extending the current substring
            charSet.add(s[right])

            # Update the result with the maximum of its current value and the length of the current substring
            result = max(result, right - left + 1)

        # Return the length of the longest substring without repeating characters
        return result


if __name__ == "__main__":
    # Create an instance of the Solution class
    solution = Solution()

    # Example 1: Test with a string
    s1 = "abcabcbb"
    result1 = solution.lengthOfLongestSubstring(s1)
    print("Length of the longest substring in s1:", result1)

    # Example 2: Test with another string
    s2 = "bbbbb"
    result2 = solution.lengthOfLongestSubstring(s2)
    print("Length of the longest substring in s2:", result2)
