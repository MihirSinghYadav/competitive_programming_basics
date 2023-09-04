class Solution {
    public int maxProfit(int[] prices) {
        int left = 0, right = 1;
        int max_profit = 0;
        while (right < prices.length) {
            if (prices[left] < prices[right]) {
                max_profit = Math.max(max_profit, prices[right] - prices[left]);
            } else {
                left = right;
            }
            right++;
        }
        return max_profit;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] prices = { 7, 1, 5, 3, 6, 4 };
        System.out.println(s.maxProfit(prices));
    }
}