bool compare(vector<int>&A,vector<int>&B)
	{
		if(A[0]==B[0])
		{
			return A[1]>B[1];
		}
		return A[0]<B[0];
	}


	class Solution {
	
	public:
	
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
    
    sort(intervals.begin(),intervals.end(),compare);
    
    
    int count=1,start=intervals[0][0],end=intervals[0][1];
    
    for(int i=1;i<intervals.size();++i)
    {
        if(start<=intervals[i][0] and end>=intervals[i][1])
        {
            continue;
        }
        else
        { 
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            count++;
        }
    }
    return count;
}};

// Solved using counting and sorting LeetCode1288 in C++