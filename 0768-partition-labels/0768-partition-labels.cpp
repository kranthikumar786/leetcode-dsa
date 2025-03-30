class Solution {
public:
    vector<int> partitionLabels(string s) {
    
      vector<int>lastOccurance(26,0);
       int  n = s.length();
      for(int i = 0 ; i < n ;i++) {
           lastOccurance[s[i]-'a'] = i; 
      }
      int partitionStart = 0 , partitionEnd = 0 ; 
           vector<int>ans;
        for(int i = 0 ; i < n ;i++) {
             partitionEnd = max(partitionEnd,lastOccurance[s[i]-'a']);
            if(i == partitionEnd ) {
                ans.push_back(i-partitionStart+1);
                partitionStart = i +1;
            }
        }
       return ans; 
    /*
     a b a b c b a c a d e   f  e  g  d  e  h  i   j   h   k   l   i  j
     0 1 2 3 4 5 6 7 8 9 10  11 12 13 14 15 16 17  18  19  20  21 22  23 


    */
    //   unordered_map<char,int>um;
    //     int  n = s.length();
    //     if( n == 1){return {1};}
    //     vector<int>ans;
    //   um[s[0]] = 0;
    //    int lastIndex = 0;
    //    while(!um.empty()) { 
    //          char curChar = um.begin().first;
    //          int curCharIndex = um.begin().second;
    //          int firstIndex = curCharIndex;  
    //        for(int i = 1 ; i < n ; i++) {
    //              if(curChar == s[i] &&  i > lastIndex) {
    //                  lastIndex = i;
    //              } 
    //        }  

    //    }
    
      /*
       how can i get max partion of given string :
        
          goup all leters into one group : 


       ababcbacadefegdehijhklij

       a  found a , then i have to check for next a where is ending : 
          meanwhile what ever char i do vist i have to keep track for those as well :
     ababcbaca  :  defegdehijhklij
     set<char>{a,b,c} : 
                  a is not found : 
                  b is not found : 
                  c is not found : 

                  all  unique chars :   
             ending length :  9 :   ans.push_back(9) : 

              defegde : hijhklij
                here one more catch is e first done so avoid doing agian : 
              unorder_map<char>{d->index,e->index,f->index} : 
              d
                where d found lastindex  = :
                  remove the processes  char from set d :

             e
                   if e == s[i]  && i > lastIndex : 
                    lastIndex = i;
                    else if(um.find(s[i]) == um.end()) {
                          um[s[i]] = i;
                    } 
                ans.push_back(startingindex = lastInde+1) :                
               hijhklij
              unorder_map<char,int>UM : 
                h : 
                 while(!UM.empty()) {
                lastIndex = i;
               for index 1 - > n :

                    if(currchar == s[i] && i > lastIndex) {
                           lastIndex  = i;
                    } else{
                           UM[s[i]] = index;
                    } 

              UM.erase(s[i]);     
                }    
      */   
    }
};