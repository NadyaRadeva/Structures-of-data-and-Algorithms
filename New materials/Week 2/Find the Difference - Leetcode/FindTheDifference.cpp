class Solution {
public:
    int partition(vector<char>& arr, int left, int right) {
        char pivot = arr[(left + right) / 2];

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

    void quickSort(vector<char>& arr, int left, int right) {
        if (left >= right) {
            return;
        }

        int pIndex = partition(arr, left, right);

        quickSort(arr, left, pIndex);
        quickSort(arr, pIndex + 1, right);
    }

    char findTheDifference(string s, string t) {
        vector<char> arrS(s.begin(), s.end());
        vector<char> arrT(t.begin(), t.end());

        if (!arrS.empty()) {
            quickSort(arrS, 0, arrS.size() - 1);
        }

        quickSort(arrT, 0, arrT.size() - 1);

        int minSize = min(arrS.size(), arrT.size());

        for (int i = 0; i < minSize; i++) {
            if (arrS[i] != arrT[i]) {
                return arrT[i];
            }
        }

        return arrT.back();
    }
};
