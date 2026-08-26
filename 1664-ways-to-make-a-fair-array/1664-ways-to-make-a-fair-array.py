class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        even_sum, odd_sum, total = 0, 0, 0
    
        for i in range(len(nums)):
            if i%2 == 0:
                even_sum += nums[i]
            else:
                odd_sum += nums[i]


        for i in range(len(nums)-1,-1,-1):
            # print(nums[i])
            if i%2 == 0:
                even_sum -= nums[i]
                if even_sum == odd_sum:
                    total += 1
                odd_sum += nums[i]
            else:
                odd_sum -= nums[i]
                if even_sum == odd_sum:
                    total += 1
                even_sum += nums[i]

        return total
        