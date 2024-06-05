class Solution {
public:
 
vector<string> commonChars(vector<string>& A) {
    int n = A.size();
    if (!n) return vector<string>();
    
    unordered_map<char, int>m;
    for (int i = 0; i < A[0].length(); i++)
        m[A[0][i]]++;
    
    int count, d;
    vector<string>ans;
    
    for (auto it = m.begin(); it != m.end(); it++) {
        d = it->second;
        for (int i = 1; i < n; i++) {
            string s = A[i]; count  = 0;
            for (int k = 0; k < s.length(); k++) {
                if (s[k] == it->first)
                    count++;
            }
            d = min(d, count);
        }
        
        if (d > 0) {
            char c = it->first;
            string str(1, c);
            while (d--)
                ans.push_back(str);
        }
    }
    
    return ans;
}
};