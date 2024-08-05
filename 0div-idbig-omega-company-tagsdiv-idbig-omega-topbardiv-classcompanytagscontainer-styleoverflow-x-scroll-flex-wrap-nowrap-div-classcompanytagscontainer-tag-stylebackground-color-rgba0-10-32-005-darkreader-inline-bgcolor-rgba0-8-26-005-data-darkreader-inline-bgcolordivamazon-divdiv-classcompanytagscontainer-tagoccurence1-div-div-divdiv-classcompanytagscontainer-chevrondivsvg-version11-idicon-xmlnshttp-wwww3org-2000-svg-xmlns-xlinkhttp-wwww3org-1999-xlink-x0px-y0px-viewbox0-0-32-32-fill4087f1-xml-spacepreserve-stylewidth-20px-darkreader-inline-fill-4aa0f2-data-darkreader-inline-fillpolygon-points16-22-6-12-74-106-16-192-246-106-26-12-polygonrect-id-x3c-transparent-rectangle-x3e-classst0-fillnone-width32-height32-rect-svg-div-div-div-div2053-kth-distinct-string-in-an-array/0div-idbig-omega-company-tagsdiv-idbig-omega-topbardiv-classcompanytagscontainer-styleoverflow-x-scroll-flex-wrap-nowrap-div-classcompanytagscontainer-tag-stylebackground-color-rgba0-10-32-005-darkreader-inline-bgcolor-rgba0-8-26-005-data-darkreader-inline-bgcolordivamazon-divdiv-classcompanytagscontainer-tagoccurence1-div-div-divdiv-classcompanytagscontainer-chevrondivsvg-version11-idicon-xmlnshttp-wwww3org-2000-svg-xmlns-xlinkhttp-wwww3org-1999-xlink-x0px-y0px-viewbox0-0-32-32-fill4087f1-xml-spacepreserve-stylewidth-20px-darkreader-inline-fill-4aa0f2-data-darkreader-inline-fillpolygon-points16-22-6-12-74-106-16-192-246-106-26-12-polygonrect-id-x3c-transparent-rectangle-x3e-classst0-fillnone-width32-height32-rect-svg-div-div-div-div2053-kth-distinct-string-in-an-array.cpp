class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> sum;
        for (const auto& x : arr) {
            sum[x]++;
        }
        
        string ans = "";
        int count = 0;
        for (const auto& x : arr) {
            if (sum[x] == 1) {
                ans = x;
                count++;
            }
            
            if (count == k) {
                return ans;
            }
        }
        return "";
    
    }
};