// There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

// An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

// Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

 

// Example 1:

// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
// Example 2:

// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4


class Solution {
    class Balloon{
        int start;
        int end;
        Balloon(int start, int end){
            this.start = start;
            this.end = end;
        }
        public String toString(){
            return "start="+this.start+" end="+this.end+"\n";
        }
    }

    
    public int findMinArrowShots(int[][] points) {
        if(points.length==0)
            return 0;
        //create a list of Balloons
        List<Balloon> BalloonList = new ArrayList<>();
        for(int[] point : points){
            BalloonList.add(new Balloon(point[0], point[1]));
        }

        BalloonList.sort(new Comparator<Balloon>(){
            public int compare(Balloon a, Balloon b){
                if(a.start!=b.start){
                    if(a.start<b.start)
                        return -1;
                    else if(a.start > b.start)
                        return 1;
                    else
                        return 0;
                }
                else{
                    if(a.end<b.end)
                        return -1;
                    else if(a.end > b.end)
                        return 1;
                    else
                        return 0;
                }
            }
        });

        int minEnd = Integer.MAX_VALUE;
        int count =0;
        for(Balloon Balloon : BalloonList){
            if(Balloon.start > minEnd){
                count++;
                minEnd = Balloon.end;
            }
            else{
                minEnd = Math.min(minEnd, Balloon.end);
            }
        }
        return count+1;
    }
}