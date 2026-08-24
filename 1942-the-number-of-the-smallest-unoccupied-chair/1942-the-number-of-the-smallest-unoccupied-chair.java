class Solution {
    public int smallestChair(int[][] times, int targetFriend) {
        PriorityQueue<Integer> empty = new PriorityQueue<>();
        int[][] ts = new int[times.length][3];
        for (int i = 0; i < times.length; i++) {
            empty.offer(i);
            ts[i] = new int[]{i, times[i][0], times[i][1]};
        }
        Arrays.sort(ts, (a, b) -> a[1] - b[1]);
        PriorityQueue<int[]> used = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        for (int i = 0; i < ts.length; i++) {
            int people = ts[i][0], start = ts[i][1], end = ts[i][2];
            while (!used.isEmpty() && used.peek()[1] <= start) {
                int chair = used.poll()[0];
                empty.offer(chair);
            }
            int chair = empty.poll();
            if (people == targetFriend)
                return chair;
            used.offer(new int[]{chair, end});
        }
        return -1;
    }
}