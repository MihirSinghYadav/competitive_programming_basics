class Solution {
    public int findMin(int[] nums) {
        int result = nums[0];
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            if (nums[left] < nums[right]) {
                result = Math.min(result, nums[left]);
                break;
            }
            int mid = (left + right) / 2;
            result = Math.min(result, nums[mid]);
            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = { 3, 4, 5, 1, 2 };
        Solution s = new Solution();
        int result = s.findMin(nums);
        System.out.println(result);
    }
}
