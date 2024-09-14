class Solution {
public:
    bool findSafeWalk(vector<vector<int>>&g,int h) {
        int r=g.size();
        if(r==0)return false;
        int c=g[0].size();
        if(c==0)return false;
        
        int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},h-g[0][0]});
        
        vector<vector<int>>v(r,vector<int>(c,-1));
        v[0][0]=h-g[0][0];
        
        while(!q.empty()) {
            auto[f,ch]=q.front();
            q.pop();
            
            int x=f.first;
            int y=f.second;
            
            if(x==r-1&&y==c-1&&ch>0)return true;
            
            for(int i=0;i<4;++i) {
                int nx=x+d[i][0];
                int ny=y+d[i][1];
                
                if(nx>=0&&ny>=0&&nx<r&&ny<c) {
                    int nh=ch-g[nx][ny];
                    if(nh>0&&nh>v[nx][ny]) {
                        v[nx][ny]=nh;
                        q.push({{nx,ny},nh});
                    }
                }
            }
        }
        
        return false;
    }
};
