class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(),range.end());
        
        for(int i = 1; i < n; i++)
        {
            range[i][0] = max(range[i][0],range[i-1][1]);
            range[i][1] = max(range[i][1],range[i-1][1]);
        }
        
        vector<int> ans;
        
        for(auto it : queries)
        {
            int prev = 0,flag = 0;
            
            for(int i = 0; i < n; i++)
            {
                if(i != 0)
                {
                    if(range[i-1][1] == range[i][0])
                    {
                        range[i][0]++;
                    }
                }
                
                int diff = prev + range[i][1] - range[i][0] + 1;
                
                if(it <= diff)
                {
                    int x = it - prev - 1;
                    ans.push_back(x + range[i][0]);
                    flag = 1;
                    break;
                }
                prev = diff;
            }
            
            if(!flag)
            {
                ans.push_back(-1);
            }
            
        }
        
        return ans;
    } 
};