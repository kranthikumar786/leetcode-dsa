class Graph {
public:
    
    vector<vector<pair<int,int>>>adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        
        for(auto & e : edges) {
            adjList[e[0]].push_back(make_pair(e[1],e[2]));
        }
    }
    
    void addEdge(vector<int> edge) {  
        adjList[edge[0]].push_back(make_pair(edge[1],edge[2]));
    }
    int shortestPath(int node1, int node2) {
        int  n = adjList.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>costForNode(n,INT_MAX);
        costForNode[node1] = 0;
        pq.push({0,node1});
        
        while(!pq.empty()){
            int curCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();
            
            if (curCost > costForNode[currNode]) {
                 continue;
            }
            
            if(currNode == node2) {
                 return curCost;
            }
            
            for (auto & neightbor : adjList[currNode]) {
                int neightborNode = neightbor.first;
                int cost = neightbor.second;
                int newCost = curCost + cost ;
                
                if(newCost < costForNode[neightborNode]) {
                   costForNode[neightborNode] = newCost;
                   pq.push({newCost , neightborNode}); 
                }
            }
            
        }
      return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */