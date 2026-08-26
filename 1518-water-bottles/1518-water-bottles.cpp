class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles > 0){
            int temp = numBottles%numExchange;
            int temp2 = numBottles/numExchange;
            if(temp2 == 0)return ans + numBottles;
            ans += (numBottles - temp);
            numBottles = temp + temp2;
        }
        return ans;
    }
};