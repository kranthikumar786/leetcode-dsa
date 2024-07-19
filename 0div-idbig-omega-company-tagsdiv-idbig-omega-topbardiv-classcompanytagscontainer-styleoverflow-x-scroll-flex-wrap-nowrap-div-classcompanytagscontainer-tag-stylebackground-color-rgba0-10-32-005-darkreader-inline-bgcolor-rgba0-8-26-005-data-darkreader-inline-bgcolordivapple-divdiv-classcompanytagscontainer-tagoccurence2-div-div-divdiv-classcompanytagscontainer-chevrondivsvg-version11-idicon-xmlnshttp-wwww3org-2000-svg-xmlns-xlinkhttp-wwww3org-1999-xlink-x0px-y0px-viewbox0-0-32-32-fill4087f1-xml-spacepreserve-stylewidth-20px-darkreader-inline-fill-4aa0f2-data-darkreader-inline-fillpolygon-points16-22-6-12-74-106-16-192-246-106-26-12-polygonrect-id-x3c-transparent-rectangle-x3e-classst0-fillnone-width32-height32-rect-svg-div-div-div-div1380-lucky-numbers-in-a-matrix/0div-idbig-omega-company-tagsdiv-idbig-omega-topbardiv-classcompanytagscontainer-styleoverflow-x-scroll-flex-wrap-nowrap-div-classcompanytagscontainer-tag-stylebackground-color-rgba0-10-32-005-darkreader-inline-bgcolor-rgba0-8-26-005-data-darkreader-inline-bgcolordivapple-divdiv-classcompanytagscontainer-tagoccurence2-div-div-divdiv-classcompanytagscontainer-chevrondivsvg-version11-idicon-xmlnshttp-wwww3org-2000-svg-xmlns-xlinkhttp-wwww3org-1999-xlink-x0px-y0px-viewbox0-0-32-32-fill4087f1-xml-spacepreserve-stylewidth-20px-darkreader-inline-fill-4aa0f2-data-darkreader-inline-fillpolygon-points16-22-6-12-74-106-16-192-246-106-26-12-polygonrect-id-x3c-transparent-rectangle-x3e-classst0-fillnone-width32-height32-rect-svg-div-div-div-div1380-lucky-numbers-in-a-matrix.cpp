class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<pair<int,int>> row_min;
        vector<int> res;
        for(int i=0;i<matrix.size();i++){
            int k=0;
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]<matrix[i][k])
                    k = j;
            }
            int maxi = 0;
            for(int j=0;j<matrix.size();j++){
                maxi = max(maxi,matrix[j][k]);
            }
            if(matrix[i][k] == maxi)
                res.push_back(maxi);
        }
        return res;
    }
};