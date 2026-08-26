class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        List<Integer> ans = new ArrayList<>();
        Set<Integer> set1 = new HashSet<>(), set2 = new HashSet<>(), set3 = new HashSet<>();
        for(int num : nums1) set1.add(num);
        
        for(int num : nums2) set2.add(num);
        
        for(int num : nums3) set3.add(num);
        
        for(int num : nums1)
        {
            if(set2.contains(num) || set3.contains(num)) 
            {
                if(!ans.contains(num)) ans.add(num);
            }
        }
        
        for(int num : nums2)
        {
            if(set3.contains(num) && !ans.contains(num)) ans.add(num);
        }
        
        return ans;
    }
}