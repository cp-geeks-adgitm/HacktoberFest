class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,n=t.length(),m=s.length();
        for(;i<n;i++){
            if(t[i]==s[j]){
                j++;
            }
        }
        return j==m;
    }
};