class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
 // store: (gain, p, t)
        vector<tuple<double,int,int>> heap;
        
        for (auto &cls : classes) {
            int p = cls[0], t = cls[1];
            double gain = (double)(t - p) / ((long long)t * ((long long)t + 1));
            heap.push_back({gain, p, t});
        }

        auto cmp = [](auto &a, auto &b) {
            return get<0>(a) < get<0>(b);  // larger gain comes first
        };
        make_heap(heap.begin(), heap.end(), cmp);

        // distribute extra students
        while (extraStudents--) {
            pop_heap(heap.begin(), heap.end(), cmp);
            auto [gain, p, t] = heap.back();
            heap.pop_back();

            p++; t++;
            double newGain = (double)(t - p) / ((long long)t * ((long long)t + 1));
            heap.push_back({newGain, p, t});
            push_heap(heap.begin(), heap.end(), cmp);
        }

        // compute average
        double sum = 0.0;
        for (auto &[gain, p, t] : heap) {
            sum += (double)p / t;
        }
        return sum / classes.size();
    }
};
