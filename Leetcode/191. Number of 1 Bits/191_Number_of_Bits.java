class Solution {
    public int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 11;
        int result = solution.hammingWeight(n);
        System.out.println(result);
    }
}