/*Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
 

Note:

1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.
Last Submission
Last Saved Code*/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res = DBL_MAX, qsum = 0, n = quality.size();
        vector<pair<double, int>> workers;
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            workers.push_back({double(wage[i]) / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        for (auto worker : workers) {
            qsum += worker.second;
            pq.push(worker.second);
            if (pq.size() > K) {
                qsum -= pq.top(); pq.pop();
            }
            if (pq.size() == K) {
                res = min(res, qsum * worker.first);
            }
        }
        return res;
    }
};
