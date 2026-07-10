class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        int counter[101] = {0};

        for(int i = 0; i < nums.size(); ++i) {
            counter[nums[i]]++;
        }

        for(int i = 0; i < 101; ++i) {
            if(isPrime(counter[i])) {
                return true;
            }
        }

        return false;
    }
};
