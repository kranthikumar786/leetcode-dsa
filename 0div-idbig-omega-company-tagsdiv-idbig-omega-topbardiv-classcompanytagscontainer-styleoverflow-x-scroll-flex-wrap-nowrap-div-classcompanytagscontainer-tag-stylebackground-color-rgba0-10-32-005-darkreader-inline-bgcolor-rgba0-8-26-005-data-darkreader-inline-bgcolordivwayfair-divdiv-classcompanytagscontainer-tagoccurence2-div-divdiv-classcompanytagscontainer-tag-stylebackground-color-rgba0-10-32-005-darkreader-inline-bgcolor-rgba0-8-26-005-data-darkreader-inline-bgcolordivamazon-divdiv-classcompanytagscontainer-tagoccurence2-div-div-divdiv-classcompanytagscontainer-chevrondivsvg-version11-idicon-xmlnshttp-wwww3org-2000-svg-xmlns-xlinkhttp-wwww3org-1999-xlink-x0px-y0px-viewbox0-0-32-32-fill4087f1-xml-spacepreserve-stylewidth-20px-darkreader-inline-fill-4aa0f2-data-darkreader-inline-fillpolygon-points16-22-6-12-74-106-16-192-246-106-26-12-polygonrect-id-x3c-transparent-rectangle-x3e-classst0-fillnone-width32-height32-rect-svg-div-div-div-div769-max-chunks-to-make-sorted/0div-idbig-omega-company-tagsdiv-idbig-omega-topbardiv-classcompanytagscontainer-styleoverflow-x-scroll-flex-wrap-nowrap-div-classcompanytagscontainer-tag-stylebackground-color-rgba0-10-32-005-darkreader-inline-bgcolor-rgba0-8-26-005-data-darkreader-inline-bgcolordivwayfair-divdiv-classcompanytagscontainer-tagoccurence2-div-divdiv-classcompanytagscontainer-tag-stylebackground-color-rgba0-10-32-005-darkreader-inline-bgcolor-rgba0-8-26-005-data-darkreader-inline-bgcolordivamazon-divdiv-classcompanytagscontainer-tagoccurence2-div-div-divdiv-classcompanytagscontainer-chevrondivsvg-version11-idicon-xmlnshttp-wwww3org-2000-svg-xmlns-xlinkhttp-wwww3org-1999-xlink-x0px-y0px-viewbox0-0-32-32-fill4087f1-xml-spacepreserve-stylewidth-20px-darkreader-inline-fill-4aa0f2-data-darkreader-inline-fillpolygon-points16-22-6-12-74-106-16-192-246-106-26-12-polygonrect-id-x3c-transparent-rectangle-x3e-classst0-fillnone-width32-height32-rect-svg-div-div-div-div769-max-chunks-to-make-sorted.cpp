class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
 int currentIndex = 0 , endingIndex = arr.size();
  int chunks = 0,maxElement = 0;
      while(currentIndex < endingIndex) {
         maxElement = max(maxElement,arr[currentIndex]);
         
          if(maxElement == currentIndex){
              chunks++;
          }
         currentIndex++;
      } 
       return chunks;
     }
};

/*
[1,2,0,3] 

  
[1,2] [0] , [3]
  1<2
*/




/*
Input 1: [1,0,2,4,3]
EO :  3 AO: 3
--------------
I 2: [0,1,2,3,4]

EO :  5 AO: 5
----------------


I 3: [4,3,2,1,0] || [4,3,2,0,1] || [4,2,3,0,1]

EO :  1 AO: 1

*/