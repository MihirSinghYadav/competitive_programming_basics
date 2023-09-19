from collections import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # One Line Solution:
        # return Counter(s) == Counter(t)
        # return sorted(s) == sorted(t)

        # Create dictionaries to count the occurrences of characters in both strings
        countS, countT = {}, {}

        # Populate the countS and countT dictionaries
        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)

        # Compare the character counts in countS and countT
        for c in countS:
            # If the character count in countS is different from countT (or not found in countT), return False
            if countS[c] != countT.get(c, 0):
                return False

        # If all characters have the same counts in both strings, return True (anagram)
        return True


def main():
    # Create an instance of the Solution class
    solution = Solution()

    # Example 1: Test with anagram strings
    s1 = "anagram"
    t1 = "nagaram"
    result1 = solution.isAnagram(s1, t1)
    print("Are s1 and t1 anagrams?", result1)  # Expected output: True

    # Example 2: Test with non-anagram strings
    s2 = "rat"
    t2 = "car"
    result2 = solution.isAnagram(s2, t2)
    print("Are s2 and t2 anagrams?", result2)  # Expected output: False


if __name__ == "__main__":
    main()
