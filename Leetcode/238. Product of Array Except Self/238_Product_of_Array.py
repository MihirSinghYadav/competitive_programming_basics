from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int])->List[int]:
        result = [1] * len(nums)
        for i in range(1,len(nums)):
            result[i] = result[i-1] * nums[i-1]
        postfix = 1
        for i in range(len(nums)-1, -1, -1):
            result[i] *= postfix
            postfix *= nums[i]
        return result

class Main:
    def main(self):
        nums = [1,2,3,4]
        result = Solution().productExceptSelf(nums)
        print(result)
        
if __name__ == '__main__':
    Main().main()

# if __name__ == "__main__":
#     # Example usage:
#     nums = [1, 2, 3, 4]
#     solution = Solution()
#     result = solution.productExceptSelf(nums)
#     print("Result:", result)
