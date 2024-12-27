class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
       int maxScore = 0 , n = values.size();
    /*for(int i = 0 ; i <  n-1 ; i++){
            for(int j = i +1 ; j< n ;j++){
                   int sum = values[i] + values[j] + (i-j);
                 if(sum > maxScore){
                    maxScore = sum;
                 }
            }
    }
    */
        if (n < 2) return values[0] + values[1] + 0 - 1; 
        vector<int> suffixMax(n);
        suffixMax[n - 1] = values[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], values[i] - i);
        }
        for (int i = 0; i < n - 1; i++) {
            maxScore = max(maxScore, values[i] + i + suffixMax[i + 1]);
        }
 return maxScore;
    }
};

/*

index and vaalues both are important for me the order which is input 
  so can't sort the input directly in given input : 
so if i can use something like preserve the index and value and get score then that would an optimal solution 

could be  something like index value based sorting instead of index based input sorting works ..? 
[1,2,3,4,5]
[5,4,3,2,1]

 two pointers ..?  no choice becuase on  what basis ..? 


[8] - > 0:
[1] - > 1 
[5] - > 2
[2] - > 3
[6] - > 4



let's identify max value fisrt :  max is at index 0 and value si 8 : 

 this won't work becuase : 
 [20, 2,1,20,20] :
           40 : 3-4 = 39 : 

  which index  value you will chose ..? 



max value but less distance : 



*/