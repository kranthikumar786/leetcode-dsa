class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       int n=students.size();
        int count[]={0,0};
        for(auto a:students)
             count[a]++;
          int k=0;
        for(;k<n&&count[sandwiches[k]];++k)
               count[sandwiches[k]]--;
        return n-k;
    }
};