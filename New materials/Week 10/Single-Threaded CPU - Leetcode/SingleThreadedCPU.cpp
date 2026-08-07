class Solution {
public:
    struct Task {
        int enqueueTime;
        int processingTime;
        int index;
    };

    struct Compare {
        bool operator()(const Task& a, const Task& b) const {

            if (a.processingTime == b.processingTime) {
                return a.index > b.index;
            }

            return a.processingTime > b.processingTime;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {

        vector<Task> allTasks;

        for (int i = 0; i < tasks.size(); i++) {
            allTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(allTasks.begin(), allTasks.end(), [](const Task& a, const Task& b) { return a.enqueueTime < b.enqueueTime;});

        priority_queue<Task, vector<Task>, Compare> pq;

        vector<int> answer;

        long long currentTime = 0;
        int i = 0;

        while (i < allTasks.size() || !pq.empty()) {

            if (pq.empty()) {
                currentTime = max(currentTime, (long long)allTasks[i].enqueueTime);
            }

            while (i < allTasks.size() &&
                   allTasks[i].enqueueTime <= currentTime) {

                pq.push(allTasks[i]);
                i++;
            }

            Task current = pq.top();
            pq.pop();

            answer.push_back(current.index);

            currentTime += current.processingTime;
        }

        return answer;
    }
};
