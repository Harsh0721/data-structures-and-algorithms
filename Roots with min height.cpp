
//problem link : https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3519/

class Solution {
public:
    
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& ADJ) 
    {
        if(n<2)
        {
            vector<int>ans;
            for(int i=0;i<n;i++)ans.push_back(i);
            return ans;
        }
        int i=0;
        
        vector<int>adj[n+1];
        
        vector<int>degree(n+1);
        
        for(i; i<ADJ.size(); i++)
        {
            int u = ADJ[i][0];
            int v = ADJ[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++; degree[v]++;
        }
        
        queue<int>q1;
        for(i=0;i<=n;i++)
        {
            if(degree[i] == 1)q1.push(i);
        }
        
        int cur = q1.size();
        
        
        
        while(n>2)
        {
            n -= cur;
            
            while(cur--)
            {
                int u = q1.front();
                q1.pop();
                
                for(i=0;i<adj[u].size();i++)
                {
                    int v = adj[u][i];
                    
                    degree[v]--;
                    if(degree[v] == 1)q1.push(v);
                }
                
            }
            
            cur = q1.size();
            
        }
        
        vector<int>ans;
            
        
        while(!q1.empty() )
        {
            int u = q1.front();
            ans.push_back( u );
            q1.pop();
        }
        return ans;
        
        
        
        
    }
};