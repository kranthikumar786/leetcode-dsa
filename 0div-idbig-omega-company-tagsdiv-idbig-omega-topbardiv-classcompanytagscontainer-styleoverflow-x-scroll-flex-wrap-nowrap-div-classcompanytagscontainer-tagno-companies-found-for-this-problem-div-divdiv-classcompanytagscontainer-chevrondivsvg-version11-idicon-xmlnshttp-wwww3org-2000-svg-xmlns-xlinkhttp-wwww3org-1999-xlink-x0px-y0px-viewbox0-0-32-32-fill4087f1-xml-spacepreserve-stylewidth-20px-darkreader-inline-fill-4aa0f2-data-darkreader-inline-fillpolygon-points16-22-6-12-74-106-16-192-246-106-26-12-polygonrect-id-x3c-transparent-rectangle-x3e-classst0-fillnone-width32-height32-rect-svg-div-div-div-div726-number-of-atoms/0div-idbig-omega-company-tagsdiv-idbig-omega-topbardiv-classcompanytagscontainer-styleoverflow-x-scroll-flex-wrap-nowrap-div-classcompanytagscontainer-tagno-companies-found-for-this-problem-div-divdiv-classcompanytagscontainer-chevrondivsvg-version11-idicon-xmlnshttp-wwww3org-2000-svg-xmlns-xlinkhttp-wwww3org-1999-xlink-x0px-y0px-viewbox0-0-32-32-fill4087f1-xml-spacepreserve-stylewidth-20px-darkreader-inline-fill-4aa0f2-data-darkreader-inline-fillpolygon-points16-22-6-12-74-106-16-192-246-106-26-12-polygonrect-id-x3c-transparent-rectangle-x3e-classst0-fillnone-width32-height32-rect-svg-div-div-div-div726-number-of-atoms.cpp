class Solution {
public:
    string countOfAtoms(string s) {
        
        stack<pair<string,int>>st;
        int n=s.length();
        int i=0;
        int num=0;
        while(i<n){
            
            if(isupper(s[i])){
                char ch=s[i];
                string str="";
                str+=s[i];
                i++;
                while(i<n && islower(s[i])){
                    str+=s[i];
                    i++;
                }
                num=0;
                while(i<n&&isdigit(s[i])){
                    num=num*10 + (s[i]-'0');
                    i++;
                }
                if(num==0)num++;
                st.push({str,num});

            }else if(s[i]=='('){
                string pp="";
                pp+=s[i];
                st.push({pp,-1});
                i++;
            }else{
                int cnt=0;
                i++;
                while( i<n&& isdigit(s[i])){
                    cnt =cnt*10 + (s[i]-'0');
                    i++;
                }
                
                if(cnt==0)cnt++;
                stack<pair<string,int>>s1;
                while(!st.empty()&& st.top().first!="("){
                    pair<string,int>p1=st.top();
                    st.pop();
                    s1.push({p1.first,(p1.second*cnt)});
                }
                st.pop();
                while(!s1.empty()){
                    pair<string,int>p1=s1.top();
                    s1.pop();
                    st.push(p1);
                }
                
                
                
            }
             
        }
        
        map<string,int>mp;
        while(!st.empty()){
            pair<string,int>p2=st.top();
            st.pop();
            mp[p2.first]+=p2.second;
        }
        string ans="";
        for(auto x:mp){
            ans+= x.first;
            int q=x.second;
            string r= to_string(q);
            if(q!=1){
            ans+=r;
            }
        }
        return ans;
        
    }
};
