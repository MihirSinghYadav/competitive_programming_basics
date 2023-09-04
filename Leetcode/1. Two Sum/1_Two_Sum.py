from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Create an empty dictionary 'maps' to store elements from the 'nums' list as keys
        # and their corresponding indices as values.
        maps = {}

        # Iterate through each element and its index in the 'nums' list.
        for index, num in enumerate(nums):
            # Calculate the difference between the 'target' value and the current element.
            diff = target - num

            # Check if the 'diff' value is already present in the 'maps' dictionary.
            if diff in maps:
                # If 'diff' is found, return a list containing the indices of the two elements.
                # 'maps[diff]' retrieves the index of the element that complements 'diff',
                # and 'index' is the index of the current element.
                return [maps[diff], index]

            # If 'diff' is not found, add the current element and its index to the 'maps' dictionary.
            maps[num] = index

        # If no pair of elements that add up to the 'target' is found, return an empty list.
        return []


class Main:
    def main(self):
        result = Solution().twoSum([2, 7, 11, 15], 9)
        print(result)


if __name__ == "__main__":
    Main().main()
