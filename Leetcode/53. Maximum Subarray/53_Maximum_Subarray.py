from typing import List


class Solution:
    def masSubArray(self, nums: List[int]) -> List[int]:
        result = nums[0]
        total = 0
        for n in nums:
            total += n
            result = max(result, total)
            if total < 0:
                total = 0
        return result


class Main:
    def main(self):
        nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        solution = Solution()
        result = solution.masSubArray(nums)
        print(result)


if __name__ == "__main__":
    Main().main()
