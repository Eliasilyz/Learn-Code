use std::collections::*;

impl Solution {
pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
  let n = nums.len();
  let mut count = 0;
  let mut btreemap = BTreeMap::new();
  for i in 1..n {
    *btreemap.entry(nums[i]).or_insert(0) += 1;
  }

  let mut max = nums[0];
  for i in 1..n-1 {
      let v = nums[i];

      let entry = btreemap.entry(v).or_insert(0);
      if *entry == 1 {
        btreemap.remove(&v);
      } else {
        *entry -= 1;
      }
      let min = btreemap.iter().next().unwrap();

      if max < v && v < *min.0 {
        count += 2;
      } else if nums[i-1] < v && v < nums[i+1] {
        count += 1;
      }
      max = max.max(v);
  }
  
  count
}
}