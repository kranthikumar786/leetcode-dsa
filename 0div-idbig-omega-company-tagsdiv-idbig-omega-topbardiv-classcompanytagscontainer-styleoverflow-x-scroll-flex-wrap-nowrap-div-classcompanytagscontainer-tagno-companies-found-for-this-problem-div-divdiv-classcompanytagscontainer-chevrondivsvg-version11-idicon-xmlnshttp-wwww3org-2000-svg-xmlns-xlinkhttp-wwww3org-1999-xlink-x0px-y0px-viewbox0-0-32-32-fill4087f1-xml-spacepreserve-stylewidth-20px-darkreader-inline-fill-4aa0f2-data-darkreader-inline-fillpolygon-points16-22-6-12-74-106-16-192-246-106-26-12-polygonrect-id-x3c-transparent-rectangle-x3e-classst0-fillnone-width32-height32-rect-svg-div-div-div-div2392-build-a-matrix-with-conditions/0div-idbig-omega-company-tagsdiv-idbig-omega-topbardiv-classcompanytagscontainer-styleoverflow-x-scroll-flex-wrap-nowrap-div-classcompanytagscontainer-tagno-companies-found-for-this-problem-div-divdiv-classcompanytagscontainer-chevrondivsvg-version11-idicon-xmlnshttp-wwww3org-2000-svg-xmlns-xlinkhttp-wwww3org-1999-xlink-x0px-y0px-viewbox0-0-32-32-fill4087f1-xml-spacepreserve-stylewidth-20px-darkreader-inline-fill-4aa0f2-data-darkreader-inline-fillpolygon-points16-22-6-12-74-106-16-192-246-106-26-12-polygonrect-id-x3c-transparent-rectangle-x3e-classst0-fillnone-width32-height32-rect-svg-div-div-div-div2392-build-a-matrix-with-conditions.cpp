class Solution {
public:
    bool f(int k,vector<vector<int>>& r,vector<int>& coordinate){
        
        vector<int> adj[k+1];
        vector<int> inorder(k+1);
        for(auto v:r){
            adj[v[0]].push_back(v[1]);
            inorder[v[1]]++;
        }
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(inorder[i]==0)q.push(i);
        }
        
        int c=0;
        int count=0;
        while(!q.empty()){
            
            int src=q.front();
            q.pop();
            coordinate[src]=c;
            count++;
            for(auto child:adj[src])
            {
                inorder[child]--;
                if(inorder[child]==0)q.push(child);
            }
            
            c++;
        }
        if(count!=k)return false;
        return true;
        
        
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
         
        
         vector<int> xc(k+1);
         vector<int> yc(k+1);
         bool flag=f(k,r,xc);
         if(flag==false)return {};
         flag=f(k,c,yc);
         if(flag==false)return {};
         vector<vector<int>> answer(k,vector<int>(k,0));
        
         for(int i=1;i<=k;i++){
             
             answer[xc[i]][yc[i]]=i;
             
         }
        
        return answer;
    }
};