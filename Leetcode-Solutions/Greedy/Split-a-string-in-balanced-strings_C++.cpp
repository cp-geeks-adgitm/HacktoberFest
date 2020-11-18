class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0,count1=0,sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R')
                count++;
            else
                count--;
            if(s[i]=='L')
                count1++;
            else
                count1--;
            if(count==0&&count1==0){
                sum++;
            }
        }
        return sum;
    }
};
