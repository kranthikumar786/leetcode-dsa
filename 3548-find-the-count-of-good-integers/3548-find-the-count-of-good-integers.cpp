class Solution {
    #define ll long long
public:
    ll factorial(int num){
        ll result=1;
        for(int i=1;i<=num;i++) result*=i;
        return result;
    }

    void generatePalindromes(string& num, int index, vector<string>& palindromes, int divisor){
        if(index>=(num.length()+1)/2){
            if(stoll(num)% divisor==0) palindromes.push_back(num);
            return;
        }
        if(index!=0){
            num[index]='0';
            num[num.size()-1-index]='0';
            generatePalindromes(num, index+1, palindromes,divisor);
        }
        for(char digit='1';digit<='9';digit++){
            num[index]=digit;
            num[num.size()-1-index]=digit;
            generatePalindromes(num,index+1,palindromes,divisor);
        }
    }
    long long countGoodIntegers(int n, int k) {
        vector<string> palindromes;
        string base(n,'0');
        generatePalindromes(base, 0, palindromes, k);

        set<string> frequencyPatterns;
        for(auto& number: palindromes){
            vector<int> freq(10,0);
            for(char digit: number) freq[digit-'0']++;

            string pattern;
            for(int f: freq) pattern+=(char)('a'+f);
            frequencyPatterns.insert(pattern);
        }
        ll totalPermutations= factorial(n);
        ll totalCount=0;
        for(auto& pattern: frequencyPatterns){
            ll permutations= totalPermutations;
            for(char f: pattern){
                permutations/=factorial(f-'a');
            }
            if(pattern[0]!='a'){
                int zeroCount=pattern[0]-'a'-1;
                ll leadingZeroPerms= factorial(n-1);
                for(int j=1;j<pattern.size();j++){
                    leadingZeroPerms/=factorial(pattern[j]-'a');
                }
                leadingZeroPerms/=factorial(zeroCount);
                permutations-=leadingZeroPerms;
            }
            totalCount+=permutations;
        }
        return totalCount;
    }
};