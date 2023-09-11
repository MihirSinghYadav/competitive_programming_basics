from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * (n)
        dp[0] = 0
        result = 0
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
            result = max(result, dp[i])

        return result


class Main:
    def execute(self):
        solution = Solution()
        nums = [0, 1, 0, 3, 2, 3]
        print(solution.lengthOfLIS(nums))


Main().execute()
