class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        if (n == 0)
            return 0;
        int max_area = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            max_area = Math.max(max_area, Math.min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        System.out.println(sol.maxArea(height));
    }
}
