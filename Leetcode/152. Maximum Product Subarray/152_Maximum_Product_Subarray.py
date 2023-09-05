from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> List[int]:
        result = nums[0]
        current_max, current_min = 1, 1

        for n in nums:
            temp = n * current_max
            current_max = max(temp, n * current_min, n)
            current_min = min(temp, n * current_min, n)
            result = max(result, current_max)
        return result


class Main:
    def main(self):
        nums = [2, 3, -2, 4]
        solution = Solution()
        result = solution.maxProduct(nums)
        print(result)


if __name__ == "__main__":
    Main().main()
