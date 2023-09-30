from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Create a defaultdict to store anagrams grouped by their character count
        result = defaultdict(list)

        for s in strs:
            # Initialize a count list for each character from 'a' to 'z'
            count = [0] * 26

            # Count the occurrences of each character in the current string
            for c in s:
                count[ord(c) - ord("a")] += 1

            # Convert the count list to a tuple and use it as a key to group anagrams
            result[tuple(count)].append(s)

        # Return the values (lists of anagrams) from the defaultdict
        return result.values()


def main():
    # Example usage of the Solution class
    solution = Solution()
    input_strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    grouped_anagrams = solution.groupAnagrams(input_strs)
    print(list(grouped_anagrams))  # Convert the result to a list and print it


if __name__ == "__main__":
    main()
