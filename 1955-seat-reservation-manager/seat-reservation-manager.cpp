class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int seat_book;
    SeatManager(int n) {
        seat_book=1;
    }
    
    int reserve() {
        if(!pq.empty()){
            int a=pq.top();
            pq.pop();
            return a;
        }
        int s=seat_book;
        seat_book++;
        return s;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */