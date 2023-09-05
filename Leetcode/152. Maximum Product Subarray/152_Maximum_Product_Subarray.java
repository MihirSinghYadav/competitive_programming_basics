class Solution {
    public int maxProduct(int[] nums) {
        int result = nums[0];
        int current_max = 1, current_min = 1;
        for (int n : nums) {
            int temp = n * current_max;
            current_max = Math.max(temp, Math.max(n * current_min, n));
            current_min = Math.min(temp, Math.min(n * current_min, n));
            result = Math.max(current_max, result);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = { 2, 3, -2, 4 };
        Solution s = new Solution();
        int result = s.maxProduct(nums);
        System.out.println(result);
    }
}
