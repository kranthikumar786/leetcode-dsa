class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       sort(skill.begin(),skill.end());
       long long sum = 0;
        
        if(skill.size() == 2) 
        {return skill[0]*skill[1];} 
      
        int i = 0, j = skill.size()-1;
        
       long long expectedSum = skill[0] +skill[j];
         while ( i < j ) {
           long long sumIn = skill[i]+ skill[j];
             if(sumIn == expectedSum) {
                 sum += (skill[i]*skill[j]);
             } 
              if(sumIn != expectedSum) {return -1;}
         
             i++, j--;
         }
       return sum;
    }
};