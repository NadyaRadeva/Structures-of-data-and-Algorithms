class Solution {
public:
    int partition(vector<vector<int>>& arr, int left, int right, int k) {
        int pivot = arr[(left + right) / 2][k];

        int beg = left;
        int end = right;

        while(true) {
            while (arr[beg][k] > pivot) {
                beg++;
            }

            while (arr[end][k] < pivot) {
                end--;
            }

            if (beg >= end) {
                return end;
            }

            swap(arr[beg], arr[end]);
            beg++;
            end--;
        }
    }

    void quickSort(vector<vector<int>>& arr, int left, int right, int k) {
        if (left >= right) {
            return;
        }

        int pIndex = partition(arr, left, right, k);

        quickSort(arr, left, pIndex, k);
        quickSort(arr, pIndex + 1, right, k);
    }

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        if (!score.empty()) {
            quickSort(score, 0, score.size() - 1, k);
        }

        return score;
    }
};
