import collections


class Solution(object):
    def containsDuplicate(self, nums):
        # Create an empty set to store unique elements
        hashset = set()
        # Iterate through each element 'n' in the 'nums' list
        for n in nums:
            # Check if 'n' is already in the 'hashset' (duplicate found)
            if n in hashset:
                return True  # Return True if a duplicate is found
            # If 'n' is not in the 'hashset', add it to the 'hashset'
            hashset.add(n)
        # If no duplicates are found after looping through the entire list, return False
        return False


class Main:
    def execute(self):
        result = Solution().containsDuplicate([1, 2, 3, 1])
        print(result)


if __name__ == "__main__":
    Main().execute()
