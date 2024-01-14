const int N = 26;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(N), v2(N);
        for(char x : word1) ++v1[x - 'a'];
        for(char x : word2) ++v2[x - 'a'];
        
        for(int i=0 ; i<N ; ++i) if( (!v1[i] && v2[i]) || (v1[i] && !v2[i]) ) return false;
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for(int i=0 ; i<N ; ++i)
            if(v1[i] != v2[i]) return false;
        
        return true;
    }
};