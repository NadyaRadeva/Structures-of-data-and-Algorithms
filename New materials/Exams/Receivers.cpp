// https://www.hackerrank.com/contests/sda-practicum-test-2/challenges/reachable-employees/problem?isFullScreen=true

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long MIN_N = 0;
long long MAX_N = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    long long N, K, S;
    cin >> N;
    if(N < MIN_N || N > MAX_N) {
        return -1;
    } 
    
    cin >> K;
    if(K > N * (N - 1) / 2 || K < MIN_N) {
        return -1;
    }
    
    cin >> S;
    if(S < MIN_N || S > N) {
        return -1;
    }
    
    vector<vector<int>> graph(N);
    
    for(long long i =0; i < K; ++i) {
        long long A, B;
        cin >> A >> B;
        
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    vector<bool> visited(N, false);
    
    queue<long long> q;
    
    q.push(S);
    
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int X;
        cin >> X;

        if (visited[X]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
