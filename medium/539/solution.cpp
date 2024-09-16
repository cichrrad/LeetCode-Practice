class Solution {
public:
    int toMinutes(std::string t){
        return (std::stoi(t.substr(0,2))*60 + std::stoi(t.substr(3,2)));
    }
    int findMinDifference(vector<string>& timePoints) {
        
        int minDelta = 1440; //max possible diff + 1
 
	//pre-sort -> find min delta
	std::vector<int> inMinutes(timePoints.size());
        for(int i = 0; i < timePoints.size();i++){
            inMinutes[i]=toMinutes(timePoints[i]);
        }
        std::sort(inMinutes.begin(),inMinutes.end());
        
        for(int i = 1; i < timePoints.size();i++){
            int delta = inMinutes[i]-inMinutes[i-1];
            if (delta > 720){
                delta = 1440 - delta;
            }
            minDelta = std::min(minDelta,delta);
            if (!minDelta){
                break;
            }
        }
        //edge case for first and last element
        int delta = inMinutes[inMinutes.size()-1]-inMinutes[0];
        if (delta > 720){
            delta = 1440 - delta;
        }
        minDelta = std::min(minDelta,delta);
        return minDelta;
        
    }
};
