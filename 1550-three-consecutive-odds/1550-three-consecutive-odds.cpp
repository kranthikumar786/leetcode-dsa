class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
     
        int n = arr.size();
        if(n <= 2) {return false;}
        for(int i = 2 ; i < n ; i++) {
            cout<<arr[i-2]%2<<"\n"; 
            if(arr[i-2] %2 && arr[i-1]%2 && arr[i]%2) {
                   return true;
             } 
            
        } 
        
        return false;
    }
};

/*
[2,6,4,1]

*/