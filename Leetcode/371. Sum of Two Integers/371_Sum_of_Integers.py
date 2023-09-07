from typing import List


class Solution:
    def getSum(self, a: int, b: int) -> int:
        # Define an inner function 'add' to perform bitwise addition
        def add(a, b):
            if not a or not b:
                return a or b
            return add(a ^ b, (a & b) << 1)

        # Handle cases where either 'a' or 'b' is negative
        if a * b < 0:
            # If 'a' is positive, swap 'a' and 'b' to handle negative 'a'
            if a > 0:
                return self.getSum(b, a)

            # Check if two's complement of 'a' plus 1 equals 'b' (overflow condition)
            if add(~a, 1) == b:
                return 0

            # If two's complement of 'a' plus 1 is less than 'b', calculate the result
            if add(~a, 1) < b:
                return add(~add(add(~a, 1), add(~b, 1)), 1)

        # If 'a' and 'b' are both positive or both negative, perform regular addition
        return add(a, b)


class Main:
    def execute(self):
        solution = Solution()
        a = 1
        b = 2
        output = solution.getSum(a, b)
        print(output)


if __name__ == "__main__":
    main = Main()
    main.execute()
