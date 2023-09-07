from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if target == nums[mid]:
                return mid

            elif nums[mid] >= nums[left]:
                if target >= nums[left] and target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if target > nums[mid] and target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1


class Main:
    def main(self):
        nums = [4, 5, 6, 7, 0, 1, 2]
        target = 0
        solution = Solution()
        result = solution.search(nums, target)
        print(result)


if __name__ == "__main__":
    Main().main()
