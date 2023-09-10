from typing import List


class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            bit = (n >> i) & 1
            result = result | (bit << (31 - i))
        return result


class Main:
    def main(self):
        solution = Solution()
        n = 43261596
        result = solution.reverseBits(n)
        print(result)


if __name__ == "__main__":
    main = Main()
    main.main()
