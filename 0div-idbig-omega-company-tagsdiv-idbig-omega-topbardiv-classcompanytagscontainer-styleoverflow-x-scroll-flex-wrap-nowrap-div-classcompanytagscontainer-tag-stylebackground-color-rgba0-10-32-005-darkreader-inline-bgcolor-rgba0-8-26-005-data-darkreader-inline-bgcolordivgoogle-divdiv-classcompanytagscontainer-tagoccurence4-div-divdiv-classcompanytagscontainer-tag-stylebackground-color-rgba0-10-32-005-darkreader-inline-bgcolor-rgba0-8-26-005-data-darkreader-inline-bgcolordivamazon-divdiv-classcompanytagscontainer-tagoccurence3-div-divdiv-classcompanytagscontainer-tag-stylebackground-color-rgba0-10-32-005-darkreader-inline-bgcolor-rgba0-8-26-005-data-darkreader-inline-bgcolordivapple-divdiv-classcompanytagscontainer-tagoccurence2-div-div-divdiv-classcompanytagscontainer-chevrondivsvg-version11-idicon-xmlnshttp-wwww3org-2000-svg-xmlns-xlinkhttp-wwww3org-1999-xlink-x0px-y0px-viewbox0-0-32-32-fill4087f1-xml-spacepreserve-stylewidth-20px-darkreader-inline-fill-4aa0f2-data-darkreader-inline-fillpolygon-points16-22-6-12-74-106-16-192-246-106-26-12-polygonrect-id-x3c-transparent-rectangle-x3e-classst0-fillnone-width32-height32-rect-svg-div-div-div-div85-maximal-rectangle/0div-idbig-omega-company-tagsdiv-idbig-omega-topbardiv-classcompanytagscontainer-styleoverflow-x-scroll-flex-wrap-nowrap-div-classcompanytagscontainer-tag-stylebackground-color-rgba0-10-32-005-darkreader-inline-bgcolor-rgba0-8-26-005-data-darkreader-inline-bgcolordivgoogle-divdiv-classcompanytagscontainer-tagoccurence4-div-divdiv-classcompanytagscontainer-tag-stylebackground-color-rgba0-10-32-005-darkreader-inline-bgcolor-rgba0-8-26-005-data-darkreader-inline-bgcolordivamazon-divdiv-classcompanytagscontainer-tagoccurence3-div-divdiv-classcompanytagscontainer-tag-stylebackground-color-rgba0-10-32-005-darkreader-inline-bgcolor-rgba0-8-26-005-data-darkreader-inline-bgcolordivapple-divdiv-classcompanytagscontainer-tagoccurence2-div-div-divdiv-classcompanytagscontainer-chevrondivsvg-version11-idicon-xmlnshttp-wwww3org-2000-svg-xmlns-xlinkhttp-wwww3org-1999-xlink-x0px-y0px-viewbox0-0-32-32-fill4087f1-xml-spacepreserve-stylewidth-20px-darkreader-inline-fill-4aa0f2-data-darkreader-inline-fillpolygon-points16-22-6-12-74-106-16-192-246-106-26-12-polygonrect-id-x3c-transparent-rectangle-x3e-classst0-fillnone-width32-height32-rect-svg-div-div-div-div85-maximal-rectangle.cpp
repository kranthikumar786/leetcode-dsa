class Solution {
public:
    int Histgram(vector<int>v)
    {
       int largest=0;
       stack<int>st;
        int n=v.size();
       for(int i=0;i<=n;i++)
       {
           int curHeight=i==n?0:v[i];
           
           while(st.size()>0 && curHeight<v[st.top()])
           {
               int top=st.top();st.pop();
               int width=st.empty()?i:i-st.top()-1;
                int curarea=v[top]*width;
               largest=max(largest,curarea);
           }
           st.push(i);
       }
      return largest;  
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
         int rows=matrix.size();
         int cols=matrix[0].size();
        vector<int>Currow(cols,0);
        int largest=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                 if(matrix[i][j]=='1')
                    Currow[j]+=1;
                  else
                  {Currow[j]=0;}
                
            }
           int curans=Histgram(Currow);
           largest=max(largest,curans); 
        }
        return largest;
    }
};