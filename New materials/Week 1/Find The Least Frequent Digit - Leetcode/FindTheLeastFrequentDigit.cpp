class Solution {
public:
    int getLeastFrequentDigit(int n) {

        int counters[10] = {0};

        while (n > 0) {
            counters[n % 10]++;
            n /= 10;
        }

        int digit = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < 10; i++) {
            if (counters[i] > 0 && counters[i] < minCount) {
                minCount = counters[i];
                digit = i;
            }
        }

        return digit;
    }
};
