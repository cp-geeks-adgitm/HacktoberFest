class Solution {
public:
    string longestPalindrome(string s) 
    {
        int low,high,si=1,st=0,len=s.length(),i;
        for(i=1;i<len;i++)
        {   
        //odd palinrome
            low=i-1;
            high=i;
            while(low>=0&&high<len&& s[low]==s[high])
            {
                if(high-low+1>si)
                {
                    st=low;
                    si=high-low+1;
                }
                low--;
                high++;
            } 
        //even pailndrome
            low=i-1;
            high=i+1;
            while(low>=0&&high<len&& s[low]==s[high])
            {
                if(high-low+1>si)
                {
                    st=low;
                    si=high-low+1;
                }
                low--;
                high++;
            }
        }
        return (s.substr(st,si));
    }
};