#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int PEOPLE_MIN = 1;
const int PEOPLE_MAX = 1000000;
const long long INTELECT_MIN = -1000000000;
const long long INTELECT_MAX = 1000000000;

vector<long long> simulateCrossing(const vector<long long>& people) {
    vector<long long> stack;

    for (size_t i = 0; i < people.size(); ++i) {
        long long p = people[i];

        bool alive = true;

        while (!stack.empty() && stack.back() > 0 && p < 0) {
            long long top = stack.back();
            if (abs(top) > abs(p)) {
                alive = false;
                break;
            } 
            else if (abs(top) == abs(p)) {
                stack.pop_back();
                alive = false;
                break;
            } 
            else {
                stack.pop_back();
            }
        }

        if (alive) {
            stack.push_back(p);
        }
    }

    return stack;
}

int main() {
    int n;
    cin >> n;
    if(n < PEOPLE_MIN || n > PEOPLE_MAX) {
        return 0;
    }
    
    vector<long long> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
        if(people[i] < INTELECT_MIN || people[i] > INTELECT_MAX) {
            return 0;
        }
    }

    vector<long long> result = simulateCrossing(people);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    
    cout << endl;
}
