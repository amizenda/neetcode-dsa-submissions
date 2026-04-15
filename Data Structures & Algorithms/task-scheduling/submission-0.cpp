class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int f : count) {
            if (f > 0) pq.push(f);
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp; 
            int cycle = n + 1;
            int taskCount = 0;

            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    if (pq.top() > 1) {
                        temp.push_back(pq.top() - 1);
                    }
                    pq.pop();
                    taskCount++;
                }
                
                time++; 
                
                if (pq.empty() && temp.empty()) break;
            }

            for (int f : temp) {
                pq.push(f);
            }
        }

        return time;
    }
};