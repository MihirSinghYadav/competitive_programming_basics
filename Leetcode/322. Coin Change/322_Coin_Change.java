import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount < 0 || coins.length == 0 || coins == null) {
            return 0;
        }

        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;

        for (int i = 0; i <= amount; i++) {
            for (int c = 0; c < coins.length; c++) {
                if (i - coins[c] >= 0)
                    dp[i] = Math.min(dp[i], dp[i - coins[c]] + 1);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] coins = { 1, 2, 5 };
        int amount = 11;
        int result = s.coinChange(coins, amount);
        System.out.println(result);
    }
}
