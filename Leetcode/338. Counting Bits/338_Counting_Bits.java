class Solution {
    public int[] countBits(int n) {
        int result[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            result[i] = 1 + result[i & (i - 1)];
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 5;
        int result[] = solution.countBits(n);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
