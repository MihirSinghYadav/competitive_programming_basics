class Solution {
    public int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;
            result = result | (bit << (31 - i));
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 43261596;
        System.out.println(solution.reverseBits(n));
    }
}