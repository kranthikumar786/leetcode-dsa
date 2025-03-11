
 class Solution {
 public:
     int numberOfSubstrings(string s) {
    unordered_map<int,int>Um;
    int n = s.length();
    int ans = 0;
    int left = 0;
     for(int right = 0; s[right] ; right++) {
         Um[s[right]]++;
         while(Um['a'] > 0 && Um['b'] > 0 && Um['c'] > 0) {
            ans += (n-right);
            Um[s[left]]--;
            left++;  
         }
     }
     return ans; 
     }
     };



// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//        unordered_set<char>st;
//        int n = s.length();
//        int ans = 0;
//        for(int i = 0 ; i+2 < n ; i++ ) {
//            st.insert('a');
//            st.insert('b');
//            st.insert('c');
//            bool f = 0;
//           for(int j = i ; j < n ;j++) {
//              cout<<j<<" ";
//              st.erase(s[j]);
//              if(!st.empty()){
//                 cout<<ans<<" ::::";
//                 ans += 1;
//                cout<<n-j<<" ";
//                 ans += (n-j);
//                  f = 1;
//                 break;
//              }
//             if(f){break;}       
//           }
//        }
//       return ans;   


        
        /*
         genratre all substring wiht  min lenght == 3 , then check for it  : 
         
         O(n^3) 
         --------------------
        
          "abc"(remianing length wil be part of my answer) : 
           abcd
           abcde  n-1 : 
           
           
            abcabc
           abc(lenght will be cnt will be added to my answer:)
           abc
           abca :
           abcab : 
           abcabc : 

           b ca : 
             c a b : 
             a b c : 

           found then right side noof char directly add into answer: 
    
             every j loop : 
                 unorder_Set : found remove the  elemtn : if !set.empty() : then get the remaing length: 
          tc : O(n^2) :
          sc  :O(3) = (1) : 
         tc : 
          during genrating time : 
        
         O(n^2)
        */
//     }
// };