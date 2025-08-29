class SeatManager {
    int next; // next "brand new" seat (never reserved)
    // min-heap for any seats who were reserved in the past
    // why ? --> suppose we reserve 1,2,3,4,5 , then free(2)
    // --> smallest index seat is 2, but 3 is still reserved
    // --> just sliding with next cannot guard against this
    std::priority_queue<int, std::vector<int>, std::greater<int>> freed;
    int max;
public:
    SeatManager(int n) : next(1),max(n) {}

    int reserve() {
        //if some seat was freed, we take top (of min heap)
        //because it is surely < next (next never decreases)
        if (!freed.empty()) {
            int s = freed.top(); 
            //pop it, since its not free anymore
            //(heapify in the bg)
            freed.pop();
            return s;
        }
        //still reserving "brand new" seats only
        return next++;
    }

    void unreserve(int seatNumber) {
        //add to freed min-heap
        //(heapify in the bg)
        freed.push(seatNumber);
    }
};

