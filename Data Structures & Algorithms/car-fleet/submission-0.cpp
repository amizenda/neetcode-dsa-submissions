class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> fleetStack;
        vector<pair<int, double>> car;
        if(n == 0) return 0;    
        
        for(int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            car.push_back({position[i], time});
        }

        sort(car.begin(), car.end(), greater<pair<int, double>>());

        for(int i = 0; i < n; i++) {
            double currentTime = car[i].second;
            
            if(fleetStack.empty() || currentTime > fleetStack.top()) {
                fleetStack.push(currentTime);
            }
        }

        return fleetStack.size();
    }
};
