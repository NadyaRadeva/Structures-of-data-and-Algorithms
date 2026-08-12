// https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from;
    int to;
    long long weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    vector<Edge> edges(m);
    
    for(int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    
    const long long NEG_INF = LLONG_MIN / 4;
    
    vector<long long> dist(n + 1, NEG_INF);
    
    dist[s] = 0;
    
    for(int i = 1; i <= n; ++i) {
        bool changed = false;
        
        for(const Edge& edge: edges) {
            if(dist[edge.from] == NEG_INF) {
                continue;
            }
            
            long long newDistance = dist[edge.from] + edge.weight;
            
            if(newDistance > dist[edge.to]) {
                dist[edge.to] = newDistance;
                changed = true;
            }
        }
        
        if(!changed) {
            break;
        }
        
    }
    
    if(dist[t] == NEG_INF) {
        cout << -1 << '\n';
    }
    else {
        cout << dist[t] << '\n';
    }
    
    return 0;
}
