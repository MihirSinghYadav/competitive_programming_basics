from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 1
        max_profit = 0
        while r < len(prices):
            if prices[l] < prices[r]:
                max_profit = max(max_profit, prices[r] - prices[l])
            else:
                l = r
            r += 1
        return max_profit


class Main:
    def main(self):
        result = Solution().maxProfit([7, 1, 5, 6, 3, 4])
        print("Max Profit : ", result)


if __name__ == "__main__":
    Main().main()
