class Solution {
    public String frequencySort(String s) {
        int n = s.length();
        HashMap<Character, Integer> freMap = new HashMap<>();
        HashMap<Character, Integer> charAtFirst = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            freMap.put(ch, freMap.getOrDefault(ch, 0) + 1);
            charAtFirst.putIfAbsent(ch, i);
        }

        List<Character> allchars = new ArrayList<>(freMap.keySet());
        allchars.sort((a, b) -> {
            int fre = Integer.compare(freMap.get(b), freMap.get(a)); // sort by descending frequency
            if (fre != 0) return fre;
            return Integer.compare(charAtFirst.get(a), charAtFirst.get(b)); // if same frequency, earlier occurrence
        });

        StringBuilder result = new StringBuilder();
        for (Character ch : allchars) {
            int count = freMap.get(ch);
            for (int i = 0; i < count; i++) {
                result.append(ch);
            }
        }

        return result.toString();
    }
}
