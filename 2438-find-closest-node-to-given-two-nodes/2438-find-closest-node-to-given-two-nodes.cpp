class Solution {
public:
    void bfs(vector <int> &edges,int node,vector <int> &dist)
    {
        queue <int> q;
        dist[node]=0;
        vector <int> vis(edges.size(),0);
        vis[node]=1; 
        q.push(node);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(edges[curr]==-1) continue;
            else{
             if(vis[edges[curr]]==0)
            {
                vis[edges[curr]]=1;
                dist[edges[curr]]=dist[curr]+1;
                q.push(edges[curr]);
            }
          }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector <int> dist1(edges.size(),-1); 
        vector <int> dist2(edges.size(),-1);
        bfs(edges,node1,dist1); int ans=-1; int mn=INT_MAX;
        bfs(edges,node2,dist2);
        for(int i=0;i<edges.size();i++)
        {
           if(dist1[i]!=-1 && dist2[i]!=-1)
           {
             int mx=max(dist1[i],dist2[i]);
             if(mx<mn || (mx==mn && i<ans))
             {
                ans=i;
                mn=mx;
             }
           }
        }
        return ans;
    }
};