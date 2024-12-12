class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>PQ(gifts.begin(),gifts.end());
        
        /*[100,64,25,9,4] : 
     10 , 64 , 25, 9 ,4 
     10 , 8 , 25 , 9 ,4 :
     10 , 8 , 5 , 9 , 4 : 
     3, 8,5,9,4 
*/
        long long sum = 0 ;
         while (k--) {
            int gift =PQ.top();
            PQ.pop();
            PQ.push(sqrt(gift));
         }  
         int n = PQ.size();
        while(n--){
            sum += PQ.top();
            PQ.pop();
        }
    return sum;
    }
};