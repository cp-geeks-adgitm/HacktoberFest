class Solution {
    public int largestRectangleArea(int[] heights) {

        if (heights.length == 1)
            return heights[0];

        int n = heights.length;
        int[] nsl = new int[n];
        int[] nsr = new int[n];

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] > heights[i])
                nsr[stack.pop()] = i;

            nsl[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        while (!stack.isEmpty())
            nsr[stack.pop()] = n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int exl = nsr[i] - nsl[i] - 1;
            ans = Math.max(ans, exl * heights[i]);
        }

        return ans;
    }

}
