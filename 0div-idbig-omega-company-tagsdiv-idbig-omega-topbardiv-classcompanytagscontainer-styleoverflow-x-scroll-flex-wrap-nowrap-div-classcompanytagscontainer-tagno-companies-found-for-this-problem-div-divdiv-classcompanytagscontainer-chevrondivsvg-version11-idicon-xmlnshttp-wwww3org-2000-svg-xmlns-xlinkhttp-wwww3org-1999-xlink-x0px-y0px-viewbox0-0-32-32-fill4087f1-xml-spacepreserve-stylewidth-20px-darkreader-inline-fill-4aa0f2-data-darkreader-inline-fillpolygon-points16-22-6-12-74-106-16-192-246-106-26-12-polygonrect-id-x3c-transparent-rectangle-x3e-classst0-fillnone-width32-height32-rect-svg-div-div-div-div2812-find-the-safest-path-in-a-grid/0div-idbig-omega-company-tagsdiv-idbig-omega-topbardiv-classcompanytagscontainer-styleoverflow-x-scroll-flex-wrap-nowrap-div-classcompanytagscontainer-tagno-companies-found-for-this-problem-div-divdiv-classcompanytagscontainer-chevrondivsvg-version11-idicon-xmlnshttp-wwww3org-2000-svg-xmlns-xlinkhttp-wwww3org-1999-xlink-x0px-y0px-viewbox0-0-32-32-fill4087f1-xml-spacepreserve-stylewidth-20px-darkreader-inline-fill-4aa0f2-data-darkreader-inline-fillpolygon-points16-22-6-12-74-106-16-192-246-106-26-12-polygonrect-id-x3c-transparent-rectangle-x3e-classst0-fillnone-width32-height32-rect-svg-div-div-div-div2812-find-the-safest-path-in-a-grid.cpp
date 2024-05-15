class dsu_class{
    public:
    vector<int> parent;
    vector<int> rank;
    dsu_class(int n){
        parent.resize(n*n);
        rank.resize(n*n,0);
        for(int i=0;i<n*n;++i) parent[i]=i;
    }
    
    int find_parent(int x){
        if(x==parent[x]) return x;
        return parent[x]=find_parent(parent[x]); // path compression
    }
    
    void Union(int x,int y){
        
        int x_parent=find_parent(x);
        int y_parent=find_parent(y);
        
       if(x_parent==y_parent) return; // already parent;

       if( rank[x_parent] == rank[y_parent] ){  // rank compression
           parent[y_parent]=x_parent;
           rank[x_parent]++;
       } 
       else if ( rank[x_parent] < rank[y_parent])
           parent[x_parent]=y_parent;
       else
           parent[y_parent]=x_parent;
        
    }    
};

class Solution {
public:
    
    const int x[4]={0,-1,0,1};
    const int y[4]={-1,0,1,0};
    
    int n;
    int max_distance;
    vector<vector<int>> distance;

     void get_min_distance_from_thiefs(vector<vector<int>>& grid){
          
        distance.resize(n,vector<int> (n,-1));
        queue<pair<int,int>> q;
    
        for(int i=0;i<n;++i){
           for(int j=0;j<n;++j){
               if(grid[i][j]==1){
                   distance[i][j]=0;           
                   q.push({i,j});
               }
           }
        }
       
        int d=1;
        
        while(!q.empty()){
            
            int size=q.size();
            
            while(size-- > 0 ){
                
                pair<int,int> p=q.front(); q.pop();
                
                int row=p.first;
                int col=p.second;
                
                for(int k=0;k<4;++k){
                    
                    int next_row = row + x[k];
                    int next_col = col + y[k];
                    
                    if(next_row <0 || next_col<0 || next_row>=n || next_col>=n ) continue;
                    if(distance[next_row][next_col]!=-1) continue;
                    
                    distance[next_row][next_col]=d; // visited
                    q.push({next_row,next_col});
    
                }
            }
            d++;
        }
        
        max_distance=d-1;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid){
        
        n=grid[0].size();
        get_min_distance_from_thiefs(grid);
        
        unordered_map<int,vector<pair<int,int>>> map;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                map[distance[i][j]].push_back({i,j});  
            }
        }
    
        vector<vector<bool>> active(n,vector<bool> (n,false));
        
        dsu_class dsu(n);
        
        while(max_distance-- > 0){
            
            vector<pair<int,int>> vect(map[max_distance].begin(),map[max_distance].end());
            
            for(auto& p:vect){
                
                int row=p.first;
                int col=p.second;
                
                active[row][col]=true;
                
                for(int k=0;k<4;++k){

                    int next_row = row + x[k];
                    int next_col = col + y[k];
                    
                    if(next_row <0 || next_col<0 || next_row>=n || next_col>=n || !active[next_row][next_col]) continue;
                    dsu.Union(row*n+ col,next_row*n + next_col);
					
                }
            }
            
          if(dsu.find_parent(0) == dsu.find_parent(n*n-1)) return max_distance;
        
        }
       
        return 0;              
    }
};