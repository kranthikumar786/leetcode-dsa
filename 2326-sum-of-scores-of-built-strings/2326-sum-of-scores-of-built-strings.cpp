class Solution {
public:
    vector<long long>zFun(string s) {
        long long  sLength = s.size();
         vector<long long >zCal(sLength,0);
        int prefixWindowLeftPtr = 0 ,prefixWindowRightPtr = 0;
   for(int currentPtr = 1; currentPtr < sLength ; currentPtr++) {

        if(currentPtr > prefixWindowRightPtr) {
           prefixWindowRightPtr = prefixWindowLeftPtr = currentPtr;
            while(prefixWindowRightPtr < sLength && s[prefixWindowRightPtr] == s[prefixWindowRightPtr-prefixWindowLeftPtr]){
                prefixWindowRightPtr++; 
            }   
            zCal[currentPtr] = prefixWindowRightPtr - prefixWindowLeftPtr;
            prefixWindowRightPtr--;
        } else{
             int index = currentPtr - prefixWindowLeftPtr;
              if(zCal[index] < prefixWindowRightPtr - currentPtr +1){
                  zCal[currentPtr] = zCal[index];
              } else{
                    prefixWindowLeftPtr = currentPtr;
                    while(prefixWindowRightPtr < sLength && s[prefixWindowRightPtr] == s[prefixWindowRightPtr-prefixWindowLeftPtr]){
                         prefixWindowRightPtr++; 
                     }   
                   zCal[currentPtr] = prefixWindowRightPtr - prefixWindowLeftPtr;
                   prefixWindowRightPtr--;
             }
        }
   }
        return zCal;
    }
    long long sumScores(string s) {
    vector<long long >zCal = zFun(s);
    long long sumOfScores = s.length();
      for(int num : zCal){
       cout<<num<<" ";
      sumOfScores += num;
      }
     return  sumOfScores ;
    }
};


     /*

       "abcdef" : 6 : 

       "a" : 1 

        "aaaaa" : 10: 

     */