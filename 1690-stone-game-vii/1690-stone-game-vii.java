class Solution {
    public int stoneGameVII(int[] stones) {
        int sum =0;
        for(int e: stones) sum+=e;
        return help(stones,new Integer[stones.length][stones.length],sum,0,stones.length-1);
    }
    public int help(int[] st, Integer[][] a ,int sum,int s,int e){
       if(s>e) return 0;
      // if(al==1) return a[i];
        if(a[s][e]!=null) return a[s][e];
        return a[s][e]=Math.max(sum-st[s]-help(st,a,sum-st[s],s+1,e),sum-st[e]-help(st,a,sum-st[e],s,e-1));
                                       
    }
}
