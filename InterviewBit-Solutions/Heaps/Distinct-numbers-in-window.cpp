vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int, int> m;
    vector<int> v;
    int count=0;
    for(int i=0;i<B;i++)
    {
        if(m[A[i]]==0)
        {
            count++;
        }
        m[A[i]]=m[A[i]]+1;
        
    }
    v.push_back(count);
    for(int i=B;i<A.size();i++)
    {
        if(m[A[i-B]]==1)
        {
            count--;
        }
        m[A[i-B]]=m[A[i-B]]-1;
        
        if(m[A[i]]==0)
        {
            count++;
        }
        m[A[i]]=m[A[i]]+1;
        v.push_back(count);
    }
        
        
    return v;
}