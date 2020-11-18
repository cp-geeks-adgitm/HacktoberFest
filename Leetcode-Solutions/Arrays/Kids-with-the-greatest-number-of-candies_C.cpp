class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int max=0;
        vector<bool> x;
        for(int i=0;i<candies.size();i++){
           if(candies[i]>max){
               max=candies[i];
           }
       }
        for(int i=0;i<candies.size();i++){
           if((candies[i]+extraCandies)>=max){
              x.push_back(true);
           }
            else{
                x.push_back(false);
            }
       }
        return x;

    }
};
