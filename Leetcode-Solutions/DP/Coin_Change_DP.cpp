class Solution {
public:
    int coinChange(vector<int>& c, int amount) {
        int n=c.size();
        vector<int> v(amount+1,0);
        for(int i=1;i<=amount;i++){
            int temp=INT_MAX;
            for(int j=0;j<n;j++){
                if(i-c[j]>=0){
                    if(v[i-c[j]]==-1){continue;}
                    temp=min(temp,v[i-c[j]]);
                }
            }
            if(temp==INT_MAX){v[i]=-1;}
            else{v[i]=temp+1;}
        }
        return v[amount];
    }
};