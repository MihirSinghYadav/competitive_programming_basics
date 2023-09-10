class Solution {
    public int climbStairs(int n) {
        if (n == 1)
            return 1;
        int[] dp = new int[46];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }

    public static void main(String[] args) {
        Solution test = new Solution();
        System.out.println(test.climbStairs(10));
    }
}
