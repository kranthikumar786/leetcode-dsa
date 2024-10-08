class Solution {
public:
 int minSwaps(string s) {
        int cnt = 0, res = 0, l =0, r = s.size()-1;
        for(;l<r;l++){
            if(cnt==0 && s[l] == ']'){
                while(s[r] != '[') r--;
                swap(s[l], s[r]);
                res++;
            }
            s[l] == '[' ? cnt++ : cnt--;
        }
        return res;
    }
};