class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        StringBuilder result = new StringBuilder();

        if ((numerator < 0) ^ (denominator < 0)) {
            result.append("-");
        }

        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);

        result.append(num / den);
        long remainder = num % den;

        if (remainder == 0) {
            return result.toString();
        }

        result.append(".");
        Map<Long, Integer> map = new HashMap<>();

        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                int startIndex = map.get(remainder);
                result.insert(startIndex, "(");
                result.append(")");
                break;
            }

            map.put(remainder, result.length());
            remainder *= 10;
            result.append(remainder / den);
            remainder %= den;
        }

        return result.toString();
    }
}

/**
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        double div = 0;
        div = (double)numerator/denominator;
       String s = String.valueOf(div);
       StringBuilder str = new StringBuilder();
        boolean f = false;
       for(int i = 0 ; i < s.length();i++) {
              str.append(s.charAt(i));
              if(s.charAt(i) == '.') {
                HashSet<Character> ch = new HashSet<>();
                 i++;
                 int k = i;
                 while( i < s.length()) {
                       if(ch.contains(s.charAt(i))) {
                            f = true;
                            break;
                       }
                       ch.add(s.charAt(i));
                     i++;  
                 }
                 str.append('(');
                 str.append(s.substring(k,i));
                 str.append(')');
                 break;
              }  
              if(f){
                break;
              } 
       }
    return str.toString();
    }
}
 */