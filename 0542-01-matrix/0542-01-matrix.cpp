class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
       
        if(m==0)
            return {};
        
        
        int n=mat[0].size();
        
         vector<vector<int>> vec(m,vector<int>(n,-1));
        
          vector<int> dirx={0,0,-1,1};
          vector<int> diry={-1,1,0,0};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vec[i][j]=0;
                    q.push({i,j});
                }
                    
            }
        }
        
        
        while(!q.empty())
        {
            
            pair<int,int> p=q.front();
            q.pop();
            
            int x=p.first;
            int y=p.second;
            
                
              for(int i=0;i<4;i++)
              {
                  
        if(x+dirx[i]>=0 && x+dirx[i]<m && y+diry[i]>=0 && y+diry[i]<n && mat[x+dirx[i]][y+diry[i]]==1 && vec[x+dirx[i]][y+diry[i]]==-1)
        {
            
            vec[x+dirx[i]][y+diry[i]]=vec[x][y]+1;
            q.push({x+dirx[i],y+diry[i]});
        }
                  
                  
              }
            
            
            
        }
        
        
        return vec;
    }
};