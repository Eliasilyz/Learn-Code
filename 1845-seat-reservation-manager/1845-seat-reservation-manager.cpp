class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        st.clear();
        for(int i = 1; i <= n; i++)st.insert(i);
    }
    
    int reserve() {
        int temp = *st.begin();
        st.erase(st.begin());
        return temp;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */