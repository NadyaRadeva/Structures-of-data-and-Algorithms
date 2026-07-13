class Solution {
public:
    int partition(vector<int>& freq, int left, int right) {
        int pivot = freq[(left + right) / 2];

        int beg = left;
        int end = right;

        while (true) {
            while (freq[beg] > pivot) {
                beg++;
            }

            while (freq[end] < pivot) {
                end--;
            }

            if (beg >= end) {
                return end;
            }

            swap(freq[beg], freq[end]);
            beg++;
            end--;
        }
    }

    void quickSort(vector<int>& freq, vector<char>& chars, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivotFreq = freq[(left + right) / 2];

        int beg = left;
        int end = right;

        while (beg <= end) {

            while (freq[beg] > pivotFreq) {
                beg++;
            }

            while (freq[end] < pivotFreq) {
                end--;
            }

            if (beg <= end) {
                swap(freq[beg], freq[end]);
                swap(chars[beg], chars[end]);

                beg++;
                end--;
            }
        }

        if (left < end)
            quickSort(freq, chars, left, end);

        if (beg < right)
            quickSort(freq, chars, beg, right);
    }


    string frequencySort(string s) {
        int frequencies[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            frequencies[s[i]]++;
        }

        vector<int> freq;
        vector<char> chars;

        for (int i = 0; i < 256; i++) {
            if (frequencies[i] > 0) {
                chars.push_back((char)i);
                freq.push_back(frequencies[i]);
            }
        }

        quickSort(freq, chars, 0, freq.size() - 1);

        string res = "";

        for (int i = 0; i < freq.size(); i++) {
            for (int j = 0; j < freq[i]; j++) {
                res += chars[i];
            }
        }

        return res;
    }
};
