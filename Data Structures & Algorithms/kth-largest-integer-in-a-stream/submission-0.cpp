class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int sizeK;
public:
    KthLargest(int k, vector<int>& nums) {
        sizeK = k;
        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > sizeK) {
            minHeap.pop();
        } 

        return minHeap.top();
    }
};
