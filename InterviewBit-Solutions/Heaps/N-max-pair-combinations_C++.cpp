vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int>>> q;
    set<pair<int,int>> s;
    vector<int> v;
    int i=n-1,j=n-1;
    q.push({A[i]+B[j],{i,j}});
    s.insert({i, j});
    int count=1;

    while(count<=n)
    {
        pair<int,pair<int,int>> p;
        p=q.top();
        v.push_back(p.first);
        q.pop();
        
        pair<int,int> p1={p.second.first-1, p.second.second};
        if(s.find(p1)==s.end())
        {
             q.push({A[p1.first]+B[p1.second],{p1}});
             s.insert(p1);
        }
        pair<int,int> p2={p.second.first, p.second.second-1};
        if(s.find(p2)==s.end())
        {
             q.push({A[p2.first]+B[p2.second],{p2}});
             s.insert(p2);
        }
        
        count++;
    }
    //reverse(v.begin(),v.end());
    return v;
    
}