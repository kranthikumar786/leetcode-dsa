class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> answer = new ArrayList<>(nums.length);
        int current = 0;
        for (int bit : nums) {
            current = (current * 2 + bit) % 5;
            answer.add(current == 0);
        }
        return answer;
    }
}




/**
    traverse and get number then divid and give true or false:


 */
