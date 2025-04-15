class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int,int>>>adjList(n+1);
      for(auto edge : times) {
          adjList[edge[0]].push_back({edge[1],edge[2]});
         // adjList[edge[1]].push_back({edge[0],edge[2]});
      }
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
       vector<int>weighted(n+1,INT_MAX);
       
       //int weighted[n+1] = INT_MAX;
       weighted[k] = 0;
       minHeap.push({0,k});
         while(!minHeap.empty()) {
              pair<int,int>node = minHeap.top();
              minHeap.pop();
                int ParentNode = node.second;
                int parentWeight = node.first;
              for(auto Cnode : adjList[ParentNode]) {
                    int minWeight = parentWeight + Cnode.second ;
                   if( minWeight < weighted[Cnode.first]) {
                      weighted[Cnode.first] =minWeight;
                      minHeap.push({minWeight,Cnode.first});                
                   } 
              }
         }
         int minTime = 0;
        for(int i = 1 ; i <= n ;i++) {
             if(weighted[i] == INT_MAX){
                return -1;
             }
           //  minTime+= ;
            minTime = max(weighted[i],minTime); 
        }
       return minTime;  
    }
};