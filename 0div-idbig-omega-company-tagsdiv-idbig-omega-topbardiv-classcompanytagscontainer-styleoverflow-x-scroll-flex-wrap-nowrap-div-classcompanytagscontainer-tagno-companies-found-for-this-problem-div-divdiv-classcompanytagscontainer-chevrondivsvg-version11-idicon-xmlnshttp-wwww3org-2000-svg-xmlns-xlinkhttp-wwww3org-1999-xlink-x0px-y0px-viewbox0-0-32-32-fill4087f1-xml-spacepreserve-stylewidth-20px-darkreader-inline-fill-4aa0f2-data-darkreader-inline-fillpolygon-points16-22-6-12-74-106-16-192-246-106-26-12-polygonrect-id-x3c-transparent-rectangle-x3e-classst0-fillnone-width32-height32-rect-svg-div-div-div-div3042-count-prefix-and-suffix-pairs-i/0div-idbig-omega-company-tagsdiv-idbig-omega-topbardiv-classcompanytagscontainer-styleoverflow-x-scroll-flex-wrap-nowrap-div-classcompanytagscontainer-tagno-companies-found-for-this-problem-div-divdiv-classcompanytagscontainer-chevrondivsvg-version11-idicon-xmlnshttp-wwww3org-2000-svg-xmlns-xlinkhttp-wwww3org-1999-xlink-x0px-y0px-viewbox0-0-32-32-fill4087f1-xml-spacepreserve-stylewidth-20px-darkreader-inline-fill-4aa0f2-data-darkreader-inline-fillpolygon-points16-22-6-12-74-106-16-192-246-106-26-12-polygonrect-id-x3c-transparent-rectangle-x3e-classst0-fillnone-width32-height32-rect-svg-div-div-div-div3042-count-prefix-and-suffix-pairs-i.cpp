class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string x1 = words[i];
                string x2 = words[j];
                if(x1.size()<=x2.size()){
                    string m1 = x2.substr(0,x1.size());
                    int len = x2.size() - x1.size();
                    string m2 = x2.substr(len,x2.size());
                    if(m1 == x1 && m2 == x1){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};