class Solution {
public:
   set<string>s;
   string Comb(int n , string ans) {
       if(ans.length() == n){
             if(s.find(ans) == s.end()){
                  return ans;
             }
           return "";
       }
       for(char c = '0' ; c < '2' ; c++) {
           ans += c ;
           string finalc = Comb(n,ans); 
            if(finalc.length() > 0) {
                 return finalc;
            }
           ans.pop_back();  
       }
       return "";
   }
    string findDifferentBinaryString(vector<string>& nums) {
     int n = nums.size();
     for(int i = 0 ; i < n ; i++) {
           string s1 = nums[i];
            s.insert(s1);
     }
     return Comb(nums.size(),"");   
    }
};