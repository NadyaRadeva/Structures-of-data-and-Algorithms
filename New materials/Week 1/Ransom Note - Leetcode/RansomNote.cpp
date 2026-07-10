class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[256] = {0};

        for(int i = 0; i < magazine.size(); ++i) {
            counter[magazine[i] - 'a']++;
        }

        for(int i = 0; i < ransomNote.size(); ++i) {
            counter[ransomNote[i] - 'a']--;

            if(counter[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
