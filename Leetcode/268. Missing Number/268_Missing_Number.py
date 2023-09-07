from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return n * (n + 1) // 2 - sum(nums)


class Solution2:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        res = n
        for i in range(n):
            res ^= i ^ nums[i]
        return res


class Main:
    def execute(self):
        solution = Solution()
        nums = [3, 0, 1]
        print(solution.missingNumber(nums))

        solution2 = Solution2()
        print(solution2.missingNumber(nums))


main = Main()
main.execute()
