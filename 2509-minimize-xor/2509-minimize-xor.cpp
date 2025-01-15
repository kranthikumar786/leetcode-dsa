class Solution {
public:
    int minimizeXor(int num1, int num2) {        
        int setBits = 0;
        for(int i = 0 ; i < 32 ; i++) {
             setBits += ((num2>>i)&1);
        }
         int result = 0;
        for (int i = 31; i >= 0 && setBits > 0; i--) {
            if (num1 & (1 << i)) { 
                result |= (1 << i);
                setBits--;
            }
        }

        for (int i = 0; i < 32 && setBits > 0; i++) {
            if (!(result & (1 << i))) { 
                result |= (1 << i); 
                setBits--;
            }
        }

        return result;


        

    }
};

/*
   x = find set bits count in num2 : 
      x^num1  min :  


        int setBits = 0;
        for(int i = 0 ; i < 32 ; i++) {
             setBits += ((num2>>i)&1);
        } 
        cout<<setBits<<" ";
        int X = 0;
       for(int i = 1 ; i <= max(num1,num2); i++) {
             int  count = 0 ;
             for(int j = 0 ; j < 32 ; j++){
             count += ((i>>j)&1);
             }
          if(count == setBits){
              X = i;
             break;
         }
   }

 */