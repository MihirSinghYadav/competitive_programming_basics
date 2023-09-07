class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int first = 0, last = numbers.length - 1;
        int[] ans = new int[2];
        while (first < last) {
            int sum = numbers[first] + numbers[last];
            if (sum == target) {
                ans[0] = first + 1;
                ans[1] = last + 1;
                return ans;
            } else if (sum < target)
                first++;
            else if (sum > target)
                last--;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] numbers = { 2, 7, 11, 15 };
        Solution s = new Solution();
        int[] ans = s.twoSum(numbers, 9);
        System.out.println(ans[0] + " " + ans[1]);
    }
}