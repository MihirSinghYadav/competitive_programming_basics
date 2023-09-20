class Solution:
    def isPalindrome1(self, s: str) -> bool:
        newString = ""
        for c in s:
            if c.isalnum():
                newString += c.lower()
        return newString == newString[::-1]

    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1

        while l < r:
            while l < r and not self.alphaNum(s[l]):
                l += 1
            while r > l and not self.alphaNum(s[r]):
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l, r = l + 1, r - 1
        return True

    def is_alpha_num(self, c):
        return (
            ord("A") <= ord(c) <= ord("Z")
            or ord("a") <= ord(c) <= ord("z")
            or ord("0") <= ord(c) <= ord("9")
        )


def main():
    # Create an instance of the Solution class
    solution = Solution()

    # Example 1: Test with a palindrome string
    s1 = "A man, a plan, a canal, Panama"
    result1 = solution.isPalindrome(s1)
    print("Is s1 a palindrome?", result1)  # Expected output: True

    # Example 2: Test with a non-palindrome string
    s2 = "race a car"
    result2 = solution.isPalindrome(s2)
    print("Is s2 a palindrome?", result2)  # Expected output: False


if __name__ == "__main__":
    main()
