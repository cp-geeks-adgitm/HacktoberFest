class Solution {
    public int maxProduct(int[] nums) {
        int cmax = 1, omax = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                cmax = 1;
                omax = Math.max(0, omax);
            } else {
                cmax *= nums[i];
                omax = Math.max(cmax, omax);
            }
        }

        cmax = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                cmax = 1;
                omax = Math.max(0, omax);
            } else {
                cmax *= nums[i];
                omax = Math.max(cmax, omax);
            }
        }

        return omax;
    }
}