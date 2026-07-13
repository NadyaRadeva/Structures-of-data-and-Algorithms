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
        if (left >= right) {
            return;
        }

        int pIndex = partition(arr, left, right);

        quickSort(arr, left, pIndex);
        quickSort(arr, pIndex + 1, right);
    }

    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size()) {
            return -1;
        }

        quickSort(nums, 0, nums.size() - 1);

        return nums[nums.size() - k];
    }
};
