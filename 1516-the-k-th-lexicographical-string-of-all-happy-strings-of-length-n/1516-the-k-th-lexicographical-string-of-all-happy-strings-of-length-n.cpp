class Solution {
public:
 int count = 0;
 string ans = "";
void rec(int index,string comb,int n,string input,int k){
             if(comb.length() == n){
                 cout<<comb<<"\n";
                  count++;
                   if(count == k){
                    ans = comb;
                   }
                   return ;
             }
       for(int i = 0; i < 3 ;i++) {
             if(!comb.empty() && comb.back() == input[i]) continue;
             comb += input[i]; 
             rec(i,comb,n,input,k);
             comb.pop_back();
       }
}
    string getHappyString(int n, int k) {
        rec(-1,"",n,"abc",k);
        return ans;
    }
};