class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[(left + right) / 2];

        int beg = left;
        int end = right;

        while(true) {
            while(arr[beg] < pivot) {
                beg++;
            }

            while(arr[end] > pivot) {
                end--;
            }

            if(beg >= end) {
                return end;
            }

            swap(arr[beg], arr[end]);
            beg++;
            end--;
        }
    }

    void quickSort(vector<int>& arr, int left, int right) {
        if(left >= right) {
            return;
        }

        int pIndex = partition(arr, left, right);

        quickSort(arr, left, pIndex);
        quickSort(arr, pIndex + 1, right);
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (!nums1.empty())
            quickSort(nums1, 0, nums1.size() - 1);

        if (!nums2.empty())
            quickSort(nums2, 0, nums2.size() - 1);

        vector<int> intersection;

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                intersection.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return intersection;
    }
};
