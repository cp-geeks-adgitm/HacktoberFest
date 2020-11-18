class Solution {
    public int nthUglyNumber(int n) {
        if (n <= 0){
            return 0;
        } 
        List<Integer> uglyNums = new ArrayList<Integer>();
        uglyNums.add(1);

        int i2 = 0;
        int i3= 0;
        int i5= 0;

        while (uglyNums.size() < n) {
            int y2 = uglyNums.get(i2) * 2;
            int y3 = uglyNums.get(i3) * 3;
            int y5 = uglyNums.get(i5) * 5;

            int min = Math.min(y2, Math.min(y3, y5));
            uglyNums.add(min);

            if (min == y2) 
             i2++;
            if (min == y3) 
              i3++;
            if (min == y5) 
             i5++;
        }

        return uglyNums.get(uglyNums.size() - 1);
    }
}