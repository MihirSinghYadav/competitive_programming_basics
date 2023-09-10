from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for i in range(amount + 1):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i], 1 + dp[i - c])

        return dp[amount] if dp[amount] != amount + 1 else -1

class Main:
    def main(self):
        coins = [1, 2, 5]
        amount = 11

        solution = Solution()
        print(solution.coinChange(coins, amount))
    
if __name__ == "__main__":
    Main().main()