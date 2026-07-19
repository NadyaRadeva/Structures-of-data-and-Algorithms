#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool findTeams(const vector<long long>& skills, int k, long long maxSum) {
    long long currentSum = 0;
    int teams = 1;

    for (size_t i = 0; i < skills.size(); i++) {
        if (currentSum + skills[i] > maxSum) {
            teams++;
            currentSum = skills[i];
            if (teams > k) {
                return false;
            }
        } 
        else {
            currentSum += skills[i];
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> skills(n);
    long long totalSum = 0;
    long long maxSkill = 0;

    for (int i = 0; i < n; i++) {
        cin >> skills[i];
        totalSum += skills[i];
        maxSkill = max(maxSkill, skills[i]);
    }

    long long left = maxSkill;
    long long right = totalSum;
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (findTeams(skills, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
