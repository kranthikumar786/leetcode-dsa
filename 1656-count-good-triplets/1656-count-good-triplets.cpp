class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int ans = 0 ; 
    if(arr.size() < 3) {return 0;}
     int n = arr.size();
    for(int i = 0 ; i < n ; i++) {
           for(int j = i +1; j < n ;j++) {
                 for(int k = j + 1; k < n ;k++) {
                       if(abs(arr[i]-arr[j]) <= a && abs(arr[i]-arr[k]) <= c && abs(arr[j]-arr[k]) <= b) {
                      ans++;
                 }
                 }
           }
    }
   return ans; 
        /*
         follow Up Questions: 
           1) possible to have input sorted ..? no : 
           2)  3 <= input size < 10^4   
           3) 1 <= input[i] <= 10^2 : 
           4) base case:  input size < 3 : return 0 
           5) co-relation b/w inputs : 
                 5a) a,b,c any order like a<=b<=c not always : 
                 5b ) a,b and c with input arry ..? like all values are bigger then a ,b,c
                          before perfrming || and after also ..? so  cotrubtion becomes zeros: 

               can a or b or c == 0 : if zeros means : 
                       same number - same number ideally here same index : 
                         using same index is allowed ..? 
                         all place  have to use i < j < k  : 

                               again i!= j!= k : 
                                      i > j > k is alowed to take ..? 
                                      or any order aprat from i!=j , j!= k , i!= k : 
                                      i < j < k : 
            6) ans can be large or int range..? int range: 
  
        */   


    }
};