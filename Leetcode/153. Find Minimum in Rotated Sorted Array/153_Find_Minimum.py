from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        result = nums[0]
        left, right = 0, len(nums) - 1

        while left <= right:
            if nums[left] < nums[right]:
                result = min(result, nums[left])
                break
            mid = (left + right) // 2
            result = min(result, nums[mid])
            if nums[mid] >= nums[left]:
                left = mid + 1
            else:
                right = mid - 1
        return result


class Main:
    def main(self):
        solution = Solution()
        nums = [3, 4, 5, 1, 2]
        result = solution.findMin(nums)
        print(result)


if __name__ == "__main__":
    Main().main()
