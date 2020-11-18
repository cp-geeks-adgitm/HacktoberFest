class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            ans = Math.max(ans, prices[i] - min);
            min = Math.min(prices[i], min);
        }
        return ans;
    }
}