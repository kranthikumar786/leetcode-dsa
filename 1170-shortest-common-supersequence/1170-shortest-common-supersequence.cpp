
class Solution {
  public : 
 string shortestCommonSupersequence(string str1, string str2) {
    int m = str1.size() ; 
    int n = str2.size();
     vector<vector<int>>DP(m+1,vector<int>(n+1,0));
      for(int i = 1 ; i <= m ; i++) {
         for(int j = 1; j <= n ; j++) {
              if(str1[i-1] == str2[j-1]){
                DP[i][j] = 1 + DP[i-1][j-1];
              } else{
               DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
              }
         }
      }
    string results = "";
    int i = m , j = n ;
     while( i > 0 && j > 0) {
         if(str1[i-1] == str2[j-1]){
             results += str1[i-1]; 
             i--;j--;}
          else if(DP[i-1][j] >= DP[i][j-1]){
             results += str1[i-1];
             i--;
          } else{
            results += str2[j-1];
          j--;
          }    
     }
     while( i > 0 ) {
        results += str1[i-1];
        i--;
     }  
     while(j > 0){
         results += str2[j-1];
         j--;
     }
      reverse(results.begin(),results.end());
   return results;   
 }  
};






// class Solution {
// public:
//     vector<vector<string>>dp;
//   string rec(int i, int j , string &s1, string &s2){
// //     if( i == s1.length()  && j == s2.length()) {
// //       return "";
// //    }
// //    if(i != s1.length() && j == s2.length()) {
// //       return s1.substr(i,s1.length()); 
// //    }
// //    if(i == s1.length() && j != s2.length()) { 
// //       return s1.substr(j,s2.length()); 
// //    }

//   if(i == s1.length()){return s2.substr(j);}
//   if(j == s2.length()){return s1.substr(i);}

//   if(!dp[i][j].empty()){
//      return dp[i][j];
//   } 
//    if(s1[i] == s2[j]){
//       //  c a b : ac
//       //c1 = (c1 + s1[i]) + rec(i+1, j+1,s1,s2); 
//         return  dp[i][j] = s1[i] + rec(i+1, j+1,s1,s2);
//       }
//     //else {
//           string co2 = "",co1 = "";
//             co1 =  s1[i] + rec(i+1,j,s1,s2);   // : a
//             co2 =  s2[j] + rec(i,j+1,s1,s2);    //   : cabac : 
            
//     //}
//   return  dp[i][j] = (co2.length() > co1.length() ? co1 : co2);
//   }
//     string shortestCommonSupersequence(string str1, string str2) {
//       int m = str1.size();
//       int n = str2.size();
//       dp.resize(m,vector<string>(n, ""));
//        return rec (0,0,str1,str2);
//   /* 
//   str1 = "a b a c", 
//             i
//   str2 = "c a b"
//           j
//       a != b : 
//    if( i== endi && j == endj) {
//       return "";
//    }
//    if(i! = end && j == endj) {
//       return string[endj-1 - j]; 
//    }
//    if(i == end && j != endi) { 
//       return string[endi-1 - i]; 
//    }
//      if(s1[i] == s2[j]){
//                    c a b : ac
//       //c1 = (c1 + s1[i]) + rec(i+1, j+1,s1,s2); 
//         retrun (s1 [i] + rec(i+1, j+1,s1,s2));
//       }
//     else{
//           string co2 = "" , col1 = " ";
//            co2 = col2 + s2[j] + rec(i,j+1,s1,s2);    : cabac : 
//             co1 = col1 + S1[i] + rec(i+1, j, s1 ,s2)  : a
//     }   
//   return co2.lenght() > co1.length() ? co2 : co1;

//    shorst common subsequnce end with : remaing string of either str1, or str2 : 
//      here str1 reaming string added : 

// */
//     }
// };