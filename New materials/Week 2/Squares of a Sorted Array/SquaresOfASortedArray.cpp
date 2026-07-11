class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[(left + right) / 2];

        int beg = left;
        int end = right;

        while (true) {
            while (arr[beg] < pivot) {
                beg++;
            }

            while (arr[end] > pivot) {
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

    void quickSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;

        int pIndex = partition(arr, left, right);

        quickSort(arr, left, pIndex);
        quickSort(arr, pIndex + 1, right);
    }

    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }

        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};
