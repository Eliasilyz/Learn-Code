class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int mid = 0; mid <= num; mid++){
            int t = mid, r =0;
            while(t > 0){
                r = r * 10 + t%10;
                t/=10;
            }
            if(r + mid == num)return true;
        }
        return false;
    }
};