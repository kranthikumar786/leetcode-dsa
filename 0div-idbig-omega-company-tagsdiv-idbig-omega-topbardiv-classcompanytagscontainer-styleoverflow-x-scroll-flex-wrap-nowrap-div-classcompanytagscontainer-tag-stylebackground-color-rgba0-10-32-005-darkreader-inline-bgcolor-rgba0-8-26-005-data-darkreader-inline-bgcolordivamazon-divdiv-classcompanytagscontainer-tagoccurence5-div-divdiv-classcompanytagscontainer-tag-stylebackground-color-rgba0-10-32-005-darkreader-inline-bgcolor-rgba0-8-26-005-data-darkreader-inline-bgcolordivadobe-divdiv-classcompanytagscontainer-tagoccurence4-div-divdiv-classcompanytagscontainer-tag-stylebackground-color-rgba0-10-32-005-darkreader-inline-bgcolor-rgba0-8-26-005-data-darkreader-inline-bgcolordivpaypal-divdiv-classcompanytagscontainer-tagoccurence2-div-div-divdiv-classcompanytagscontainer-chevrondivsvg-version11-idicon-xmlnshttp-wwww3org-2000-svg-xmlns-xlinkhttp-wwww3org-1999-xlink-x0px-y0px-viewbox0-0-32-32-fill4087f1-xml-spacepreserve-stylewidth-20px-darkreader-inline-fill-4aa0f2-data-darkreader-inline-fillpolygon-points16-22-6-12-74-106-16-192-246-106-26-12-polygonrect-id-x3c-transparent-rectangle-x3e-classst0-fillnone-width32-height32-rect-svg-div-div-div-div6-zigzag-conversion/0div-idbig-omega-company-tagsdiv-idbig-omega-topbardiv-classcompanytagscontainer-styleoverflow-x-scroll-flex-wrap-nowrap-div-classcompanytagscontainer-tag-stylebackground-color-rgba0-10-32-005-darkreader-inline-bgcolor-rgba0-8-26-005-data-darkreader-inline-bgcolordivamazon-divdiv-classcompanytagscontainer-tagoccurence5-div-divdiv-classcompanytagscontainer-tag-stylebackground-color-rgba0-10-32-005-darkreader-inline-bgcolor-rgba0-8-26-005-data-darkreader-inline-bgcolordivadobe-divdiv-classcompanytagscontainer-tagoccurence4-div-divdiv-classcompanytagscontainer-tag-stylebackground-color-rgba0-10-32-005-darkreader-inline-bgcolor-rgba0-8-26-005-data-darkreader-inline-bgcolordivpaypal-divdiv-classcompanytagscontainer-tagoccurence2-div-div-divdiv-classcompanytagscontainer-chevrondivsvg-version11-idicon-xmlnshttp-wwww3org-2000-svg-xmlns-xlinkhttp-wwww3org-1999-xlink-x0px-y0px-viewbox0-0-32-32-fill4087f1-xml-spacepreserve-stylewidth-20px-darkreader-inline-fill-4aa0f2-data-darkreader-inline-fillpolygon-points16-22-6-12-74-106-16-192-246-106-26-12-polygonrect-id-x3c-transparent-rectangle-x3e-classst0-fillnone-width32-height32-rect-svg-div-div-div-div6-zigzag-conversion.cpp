class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        vector<string> arr(min(numRows, n));
        if(numRows<2) return s;
        if(n<2) return s;
        int i=0, j=0;
        
        while(i<n) {
            while(j<numRows && i<n) {
                arr[j]+=s[i];
                i++;
                j++;
            }
            j=j-2;
            while(j>=0 && i<n) {
                arr[j]+=s[i];
                i++;
                j--;
            }
            j=j+2;
        }
        
        string res="";
        
        for(auto v : arr) {
            res=res+v;
        }
        return res;
    }
};