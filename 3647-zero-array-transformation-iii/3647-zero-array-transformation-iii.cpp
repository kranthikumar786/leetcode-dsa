class Solution {
public:
    static bool cmp(vector<int> &A, vector<int> &B){
        if(A[0]<B[0])return 1;
        else if(A[0]==B[0] and A[1]>B[1])return 1;
        return 0;
    }
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), cmp);
        priority_queue<int> available;
        int count =0, n = nums.size(), ind=0;
        vector<int> freq(n+1, 0);
        for(int i=0;i<n;i++){
            count+=freq[i];
            while(ind<queries.size() and queries[ind][0]<=i){
                available.push(queries[ind++][1]);
            }
            while(count<nums[i] and !available.empty() and available.top()>=i){
                freq[available.top()+1]--;
                available.pop();
                count++;
            }
            if(count<nums[i])return -1;
        }
        return available.size();
    }
};