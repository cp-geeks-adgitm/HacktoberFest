class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> x;
        int i;
        if(n==1){
            x.push_back(0);
            return x;
        }
        if(n%2==0){
             i=1;
        }
        else{
            i=0;
            x.push_back(i);
            i++;
        }
        while(i<=n/2){
            x.push_back(i);
            x.push_back(-i);
            i++;
        }
        return x;
    }
};
