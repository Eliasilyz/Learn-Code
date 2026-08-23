class Solution {
    public String reversePrefix(String word, char ch) {
        int index = -1;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return word;
        }
        StringBuilder sb = new StringBuilder();
        String s = sb.append(word.substring(0, index + 1)).reverse().toString();
        if (index < word.length() - 1) {
            s += word.substring(index + 1);
        }
        return s;
    }
}