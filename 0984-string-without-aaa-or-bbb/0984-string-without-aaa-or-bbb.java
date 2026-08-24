class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder sb = new StringBuilder();
        while (a > 0 || b > 0) {
            if (sb.length() <= 1 || sb.charAt(sb.length() - 2) != sb.charAt(sb.length() - 1)) {
                if (a >= b) {
                    if (a - b > 1) {
                        sb.append("aa");
                        a -= 2;
                    } else {
                        sb.append("a");
                        a -= 1;
                    }
                } else {
                    if (b - a > 1) {
                        sb.append("bb");
                        b -= 2;
                    } else {
                        sb.append("b");
                        b -= 1;
                    }
                }
            } else {
                if (sb.charAt(sb.length() - 1) == 'a') {
                    sb.append("b");
                    b--;
                } else {
                    sb.append("a");
                    a--;
                }
            }
        }
        return sb.toString();
    }
}