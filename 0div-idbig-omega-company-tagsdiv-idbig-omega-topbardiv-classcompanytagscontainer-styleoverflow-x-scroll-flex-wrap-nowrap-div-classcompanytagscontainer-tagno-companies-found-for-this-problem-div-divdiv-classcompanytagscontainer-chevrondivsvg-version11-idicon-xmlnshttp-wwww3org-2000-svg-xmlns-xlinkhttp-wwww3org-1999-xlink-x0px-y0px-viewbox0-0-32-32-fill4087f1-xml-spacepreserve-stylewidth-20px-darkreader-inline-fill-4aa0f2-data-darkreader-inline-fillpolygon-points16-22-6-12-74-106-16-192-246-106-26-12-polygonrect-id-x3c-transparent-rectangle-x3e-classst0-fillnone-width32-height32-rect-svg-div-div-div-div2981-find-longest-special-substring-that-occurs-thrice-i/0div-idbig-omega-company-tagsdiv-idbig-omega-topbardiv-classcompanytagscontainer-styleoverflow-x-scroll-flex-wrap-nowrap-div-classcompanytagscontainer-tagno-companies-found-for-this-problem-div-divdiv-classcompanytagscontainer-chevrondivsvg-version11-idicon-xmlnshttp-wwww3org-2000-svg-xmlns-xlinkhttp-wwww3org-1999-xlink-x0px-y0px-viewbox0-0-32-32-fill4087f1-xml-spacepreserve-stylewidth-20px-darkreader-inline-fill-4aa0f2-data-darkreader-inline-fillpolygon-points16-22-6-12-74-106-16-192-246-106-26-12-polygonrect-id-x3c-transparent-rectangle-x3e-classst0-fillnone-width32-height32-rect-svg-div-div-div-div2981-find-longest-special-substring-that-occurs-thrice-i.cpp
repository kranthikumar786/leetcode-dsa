        /*
        
            if(occurance >= 3) {
              longestLeth : 
            } 
        
        
            aaaa : 
             a = > a , a , a :  > =3  length = 1 : 
             longlestLength =  max(length,longlestLength) : 
             aa - > aa  , aa  >= 3 : length = 2 :  
             longlestLength =  max(length,longlestLength) :
        
        
           
             take substring and check for it how time it is occuring : 
             if thorslod  > =3 : take substring length : an dupdates with max : 
             
             example 3 fails here  : so this is not correct 
           if a  , then next char is different then a : then move substring starting point  to next char : 
             i = i+1 ;
             
        
        
         return (occurance >= 3 ? longestLength : -1);
        */
        
        class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int low=0,high=n-1;
        while(low<high){
            int mid = (low+high)/2;
            if(check(s,mid)) low = mid+1;
            else high = mid;
        }
        return low-1;
    }
    bool check(string s,int len){
        int count = 1;
        vector<int> occ(26,0);
        char prev = ',';
        for(int i=0;i<s.size();i++){
            if(s[i]==prev){
                count++;
            }
            else{
                count = 1;
                prev = s[i];
            }
            if(count>=len && ++occ[s[i]-'a']>=3){
                return true;
            }
        }
        return false;
    }
};
        