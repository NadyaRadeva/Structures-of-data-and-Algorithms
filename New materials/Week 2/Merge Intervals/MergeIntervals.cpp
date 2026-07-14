class Solution {
public:
    int partition(vector<vector<int>>& intervals, int left, int right) {
        int pivot = intervals[(left + right) / 2][0];

        int beg = left;
        int end = right;

        while (true) {
            while (intervals[beg][0] < pivot) {
                beg++;
            }

            while (intervals[end][0] > pivot) {
                end--;
            }

            if (beg >= end) {
                return end;
            }

            swap(intervals[beg], intervals[end]);
            beg++;
            end--;
        }
    }

    void quickSort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) {
            return;
        }

        int pIndex = partition(intervals, left, right);

        quickSort(intervals, left, pIndex);
        quickSort(intervals, pIndex + 1, right);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        quickSort(intervals, 0, intervals.size() - 1);

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
