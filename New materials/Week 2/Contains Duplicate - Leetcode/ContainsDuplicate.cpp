class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[(left + right) / 2];

        int i = left;
        int j = right;

        while (true) {
            while (nums[i] < pivot) {
                i++;
            }

            while (nums[j] > pivot) {
                j--;
            }

            if (i >= j) {
                return j;
            }

            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int pIndex = partition(nums, left, right);

        quickSort(nums, left, pIndex);
        quickSort(nums, pIndex + 1, right);
    }

    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }

        quickSort(nums, 0, nums.size() - 1);

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
