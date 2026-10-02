class Solution {
    public char findTheDifference(String s, String t) {
        // if(s.length() == 0) return t;
        // if(t.lentgh() == 0) return s;

        HashMap<Character,Integer>map = new HashMap<>();

        for(char c : s.toCharArray()){
            map.put(c,map.getOrDefault(c,0) + 1);
        }
        for(char c : t.toCharArray()){
            map.put(c,map.getOrDefault(c,0) - 1);
            if(map.get(c) < 0) return c;
        }
        return ' ';
    }
}