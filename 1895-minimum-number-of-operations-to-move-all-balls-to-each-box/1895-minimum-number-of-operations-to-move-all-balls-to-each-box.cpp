class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;
        for (int i = 0; i < n; i++) {
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return answer;
    }
};       
             

             // "1 1 0"
              // 2 0 0   "only one move" don't add ith index value on left side
              
              /* 1 1 0 :   since it is middle  come from left to middle and from right to middle  : 
                 0 2 0 :  "only one move" :
  
               1 1 0 :  leftPtr all :  currentptr : rightPtrall :   

    
                 */
/*
                  for(int i = 0 ; i < n ; i++) {
              int leftPtr = i - 1 ; int rightPtr = i+1 ;
             int ballsL = 0 ,ballsR = 0, ansL = 0 , ansR = 0;
              while(leftPtr >= 0) {
                 ballsL += boxes[leftPtr]- '0';
               ansL += ballsL; 
               leftPtr--;
              }
              cout<<ansL<<" ";
              while(rightPtr < n) {
                 ballsR += boxes[rightPtr]- '0';
                 ansR += ballsR; 
                 rightPtr++;
              }   
              cout<<ansR<<"\n";
             ans.push_back(ansL+ansR);
        }
        return ans;
*/
        /*
          0 1 2 
         "1 1 0"
          i-j = 1 
          0 2 0 


          ith = >(1 1 0): 
           To fill left side come from right side while chekcing condition of s[j]:


         

        directl can't apply  no of subarray logic becuase if  more zeros then ans goes wrong : 


     0 1 2 3 4 5 
    "0 0 1 0 1 1"
  5  "0 0 1 0 2 0" :  1 
  4   "0 0 1 2 0 0"   : 2 
  3   "0 0 3 0 0 0" : 2
  2   "0 3 0  0 0 0" : 3 
  1   "3 0  0  0 0 0"  : 3  

5 1 4 2 3 2 2 3 1 3 
5 1 4 2 3 2 2 3 
5 1 4 2 3 2 
5 1 4 2 


"001011" : 

after reaching half way : chose the different way to move since now all balls are on left side now : 


A : [11,8,5,3,1,0]

E : [11,8,5,4,3,4]
        */

