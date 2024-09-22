     /*int ans = 0;
     if(n <=9){return n;}
     for(int i = 1; i <= n ; i++) {
           unordered_map<int,int>Fr;
            bool f = 0;
           int num  = i; 
           while (num ) {
            Fr[num%10]++;
             if(Fr[num%10] >= 2) {
                  f = 1 ; 
                  break;
             }
            num = num/10;
           }
    if(!f) {
        ans++;
    }
     }
    return ans; 
    */

int dp[11][2][1024];
class Solution {
public:
    int f(int position,bool isprefix,int mask,int n,string num){

        if(position >= n) return 1;
        if(dp[position][isprefix][mask] != -1) return dp[position][isprefix][mask];

        int start = (position == 0)? 1 : 0;
        int limit = isprefix ? (num[position] - '0') : 9;
        int ans = 0;
        for(int i = start; i <= limit; i++){
            if(mask&(1<<i)) continue;
            bool newprefix = isprefix ? (i == limit) : false;
            ans += f(position+1,newprefix,mask | (1<<i),n,num);
        }

        return dp[position][isprefix][mask] = ans;
    }

    int permute(int n){
        if(n == 1) return 9;
        int fac = 362880;
        int r = 9-n+1;

        int num = 1;
        for(int i=1; i <=r; i++){
            num *= i;
        }

        return 9*fac/num;
    }

    int countSpecialNumbers(int n) {
        string s = to_string(n);
        if(s.length() == 1) return n;
        int ans = 0;
        for(int i=1; i < s.length(); i++){
            ans += permute(i);
        }
        memset(dp,-1,sizeof(dp));
        ans += f(0,1,0,s.length(),s);
        return ans;
    }
};



/*

 since ans is fixed at certain nubmbers : 
  ex : n < = 10 : return n ;
    1 to 20 : 19 : 
    1 to 135 : 110 : 
   digit place and place ka place : 
      10 to 20  :  range bweteen :  1 : 
      20 to 30 : 21 22 23 24 25 26 27 28 29 30 : 1 : 
       every ten number of two digits is having  1 number as dupliace : 

   30 to 40 : 31 , 32 33 34 35 36 37 38 39 40 :  33 - > can't consider becuase of dupliacte dgits:
    40 to 50 : 
    50 to 60 : 
    60 to 70 : 
    70 to 80 : 
    80 to 90 : 
    90 to 100 : 
   
     pow(10,i): ans + = origin- sub : 


     100 - 9 : 91 : 


    10 to 100 :  91 :

 100 to 110 : 
 100 , 101, 102, 103, 104, 105,106,107 , 108, 109,
 
 110  111, 112, 113, 114, 114, 
 
 120  , 121 , 122

 130 , 131, 132,133, 134,135,136,137,138,139,
*/