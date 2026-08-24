class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums=nums
        self.arr=nums
        

    def reset(self):
        """
        :rtype: List[int]
        """
        self.nums[:]=self.arr
        return self.nums
        

    def shuffle(self):
        """
        :rtype: List[int]
        """
        ans=self.arr[:]
        random.shuffle(ans)
        return ans
        
        
    """ def __init__(self, nums: List[int]):
        self.nums = nums
        self.arr = nums.copy()

    def reset(self) -> List[int]:
        self.nums[:] = self.arr
        return self.nums

    def shuffle(self) -> List[int]:
        # shuffle returns none, so copy and shuffle 
        
        # approach 1 
        ans = self.arr[:]
        random.shuffle(ans)
        return ans"""
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()