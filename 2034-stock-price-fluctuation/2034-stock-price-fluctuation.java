class StockPrice {
    
    private int latestTimeStamp;
    private Map<Integer, Integer> priceMap;
    private TreeMap<Integer, Set<Integer>> valToTime;

    public StockPrice() {
        priceMap = new HashMap<>();
        latestTimeStamp = 0;
        valToTime = new TreeMap<>();
    }
    
    public void update(int timestamp, int price) {
        if(timestamp > latestTimeStamp) {
            latestTimeStamp = timestamp;
        }
        int val = priceMap.getOrDefault(timestamp, -1);
        priceMap.put(timestamp, price);
        
        Set<Integer> currentTimes = valToTime.getOrDefault(price, new HashSet<>());
        currentTimes.add(timestamp);
        valToTime.put(price, currentTimes);
        
        if(val != -1 && val != price) {
            Set<Integer> prevTimes = valToTime.getOrDefault(val, new HashSet<>());
            if(prevTimes.contains(timestamp)) {
                prevTimes.remove(timestamp);
            }
            if(prevTimes.size() == 0) {
                valToTime.remove(val);
            } else {
                valToTime.put(val, prevTimes);
            }
        }
    }
    
    public int current() {
        return priceMap.get(latestTimeStamp);
    }
    
    public int maximum() {
        return valToTime.lastKey();  // Last key is the maximum value (We can observe this value at multiple timestamps)
    }
    
    public int minimum() {
        return valToTime.firstKey(); // First key is the minimum value (We can observe this value at multiple timestamps)
    }
}