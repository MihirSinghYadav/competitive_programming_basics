from typing import List


class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        value = 0
        for operation in operations:
            if operation[1] == "+":
                value += 1
            else:
                value -= 1
        return value


if __name__ == "__main__":
    # Create an instance of the Solution class
    solution = Solution()

    # Example 1: Test with operations
    operations1 = ["--X", "X++", "X++"]
    result1 = solution.finalValueAfterOperations(operations1)
    print("Final value after operations1:", result1)

    # Example 2: Test with different operations
    operations2 = ["++X", "X--", "X--", "++X", "++X", "++X", "++X", "++X", "++X"]
    result2 = solution.finalValueAfterOperations(operations2)
    print("Final value after operations2:", result2)
