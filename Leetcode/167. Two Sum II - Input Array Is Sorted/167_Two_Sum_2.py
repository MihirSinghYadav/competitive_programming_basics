from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        first, last = 0, len(numbers) - 1
        while first < last:
            sum = numbers[first] + numbers[last]
            if sum == target:
                return [first + 1, last + 1]
            elif sum < target:
                first += 1
            else:
                last -= 1
        return [-1, -1]


class Main:
    def main(self):
        s = Solution()
        numbers = [2, 7, 11, 15]
        target = 9
        print(s.twoSum(numbers, target))


if __name__ == "__main__":
    Main().main()
