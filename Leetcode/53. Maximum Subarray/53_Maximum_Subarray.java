class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        int sum = 0;
        int max = Integer.MIN_VALUE;
        for (int num : nums) {
            sum += num;
            max = Math.max(sum, max);
            if (sum < 0)
                sum = 0;
        }
        return max;
    }

    public static void main(String[] args) {
        int[] nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        Solution s = new Solution();
        System.out.println(s.maxSubArray(nums));
    }
}