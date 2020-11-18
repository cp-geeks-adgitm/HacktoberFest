class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        vector<int> freq;
        map<int,int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            freq.push_back(itr->second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int sum=0;
        while(sum<n/2)
        {
            sum+=freq[count];
            count++;
        }
        return count;
    }
};
