class Solution {

    List<Integer> res;
    String num;
    boolean check(long num1, long num2, int pos){
        if(pos >= num.length()){
            return true;
        }
        if(num1 + num2 > Integer.MAX_VALUE){
            return false;
        }
        String nextNum = String.valueOf(num1 + num2);
        for(int i = 0; i < nextNum.length(); i++){
            if(pos >= num.length() || nextNum.charAt(i) != num.charAt(pos)){
                return false;
            }
            pos++;
        }
        int num3 = Integer.valueOf(nextNum);
        res.add(num3);
        return check(num2, num3, pos);
    }

    public List<Integer> splitIntoFibonacci(String num) {
        this.num = num;
        res = new ArrayList<>();
        int iBound = num.charAt(0) == '0' ? 0 : num.length() - 3;
        for(int i = 0; i <= iBound; i++){
            long num1 = Long.valueOf(num.substring(0, i + 1));
            if(num1 >= Integer.MAX_VALUE){
                break;
            }
            int jBound = num.charAt(i + 1) == '0' ? i + 1 : num.length() - 2;
            for(int j = i + 1; j <= jBound; j++){
                long num2 = Long.valueOf(num.substring(i + 1, j + 1));
                if(num2 >= Integer.MAX_VALUE){
                    break;
                }
                res.add((int)num1); res.add((int)num2);
                if(check(num1, num2, j + 1)){
                    return res;
                }
                res.clear();
            }
        }
        return res;
    }
}