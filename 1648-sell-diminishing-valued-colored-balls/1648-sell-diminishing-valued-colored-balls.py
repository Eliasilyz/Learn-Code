class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        count = Counter(inventory)
        arr = [[k,count[k]] for k in count]
        arr.sort(reverse=True)
        l = len(arr)
        ans = 0
        for i in range(l):
            v,c = arr[i]
            all_ = v * c if i == l-1 else (v - arr[i+1][0])*c
            vv = (0 if i == l-1 else arr[i+1][0]) + 1
            sum_ = (v + vv) * (v - vv + 1) // 2 * c
            if all_ <= orders:
                ans = (ans + sum_) % 1000000007
                orders -= all_
                if i != l-1: arr[i+1][1] += c
            else:
                cc = orders//c
                left = orders%c
                vv = v-cc+1
                part_sum = (v+vv) * (v-vv+1)//2
                ans = (ans + c*part_sum + left*(vv-1)) % 1000000007
                break
        return ans
            