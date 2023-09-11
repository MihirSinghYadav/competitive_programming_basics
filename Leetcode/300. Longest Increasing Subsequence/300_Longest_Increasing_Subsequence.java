import java.util.Arrays;

class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int result = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            result = Math.max(result, dp[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
        int result = s.lengthOfLIS(nums);
        System.out.println(result);
    }
}