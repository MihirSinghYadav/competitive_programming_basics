class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] result = new int[len];
        result[0] = 1;
        for (int i = 1; i < len; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int postfix = 1;
        for (int i = len - 1; i > -1; i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = { 1, 2, 3, 4 };
        int[] result = s.productExceptSelf(nums);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}