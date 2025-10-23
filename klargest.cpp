#include <vector>
#include <queue>

using namespace std;

int kth_largest(vector<int> values, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int val : values) {
        minHeap.push(val);
        
        if (minHeap.size() > static_cast<size_t>(k)) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}