class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         int oSize = original.size();
        
        if( m * n  != oSize) {return {};}
        
         vector<vector<int>>ansArray(m,vector<int>(n,0));
        for(int i = 0 ; i < oSize; i++) {
           ansArray[i/n][i%n] = original[i];   
        }
       return ansArray; 
    }
};