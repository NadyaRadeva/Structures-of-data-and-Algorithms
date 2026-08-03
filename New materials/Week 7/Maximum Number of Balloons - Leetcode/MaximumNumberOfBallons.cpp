class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::unordered_map<char, int> freq;

        for(int i = 0; i < text.size(); ++i) {
            freq[text[i]]++;
        }

        return min({freq['b'], freq['a'], freq['l'] / 2, freq['o'] / 2, freq['n']}); 
    }
};
