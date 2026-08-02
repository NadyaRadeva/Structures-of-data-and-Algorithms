// https://www.hackerrank.com/contests/sda-hw-9-2022/challenges/challenge-3771/problem

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int MIN_N = 1;
int MAX_N = 100000;
long long MIN_M = 1;
long long MAX_M = 1000000000;
long long MIN_Ai = 1;
long long MAX_Ai = 1000000000;

using namespace std;
int main() {
    int N;
    long long M;
    
    std::cin >> N;
    if(N < MIN_N || N > MAX_N) {
        return 0;
    }
    
    std::cin >> M;
    if(M < MIN_M || M > MAX_M) {
        return 0;
    }
    
    vector<long long> a(N);
    
    unordered_map<long long, long long> left;
    unordered_map<long long, long long> right;
    
    for(int i = 0; i < N; ++i) {
        std::cin >> a[i];
        right[a[i]]++;
    }
    
    long long answer = 0;
    
    for(int i = 0; i < N; ++i) {
        right[a[i]]--;
        
        if(M == 1) {
            answer += left[a[i]] * right[a[i]];
        }
        else if(a[i] % M == 0) {
            long long leftValue = a[i] / M;
            long long rightValue = a[i] * M;
            
            answer += left[leftValue] * right[rightValue];
        }
        
        left[a[i]]++;
    }
    
    std:: cout << answer << std::endl;
    
    return 0;
}
