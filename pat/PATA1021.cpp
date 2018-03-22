//
//  PATA1021.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//#define MAX_N 10010
//
//
//
//static vector<vector <int> > adj; // vector<vector<int>> v; is useless
//static int visited[MAX_N] = {0}, N;
//
//static int max_root[MAX_N], end_[MAX_N]; // 我觉得这个很好啊
//static void DFS(int source,int v, int depth, int &max){
//    visited[v] = 1; // 防止回头
//    if(max < depth){
//        max = depth;
//        end_[source] = v;
//    }
//
//    for(auto it = adj[v].begin(); it != adj[v].end(); it++){
//        if(visited[*it] == 0){
//            DFS(source, *it, depth + 1, max);
//        }
//    }
//}
//
//static int travelDFS(int v){
//    int depth = 1, max = depth;
//    fill(visited, visited + MAX_N, 0);
//    DFS(v,v, depth, max);
//    max_root[v] = max;
//    return max;
//}
//
//static bool isRoot[MAX_N];
//static int father[MAX_N];
//static void init_father(int n){
//    for(int i = 1; i <= n; i++){
//        isRoot[i] = false;
//        father[i] = i;
//    }
//}
//
//static int findFather(int x){
//    if(x == father[x])return x;
//    else{
//        int root = findFather(father[x]);
//        father[x] = root;
//        return root;
//    }
//}
//
//static void Union(int a, int b){
//    int af = findFather(a);
//    int bf = findFather(b);
//    if(af != bf)father[b] = af;
//}
//
//int PATA1021(){
//    freopen("input.txt", "r", stdin);
//
//    scanf("%d", &N);
//    init_father(N);
//    adj.resize(N+1);
//
//    int a, b;
//    for(int i = 1; i < N; i++){ // N-1
//        scanf("%d%d", &a,&b);
//        adj[a].push_back(b);
//        adj[b].push_back(a);
//        Union(a,b);
//    }
//
//    int unite_cnt = 0;
//    for(int i = 1; i<= N; i++){
//        if(father[i] == i){
//            unite_cnt++;
//            isRoot[i] = 1;
//        }
//    }
//
//    if(unite_cnt > 1){
//        printf("Error: %d components", unite_cnt);
//        return 0;
//    }
//
//    for(int i = 1; i <= N; i++){
//        travelDFS(i);
//    }
//
//    int max = max_root[1]; // get max_root[i]'s max value
//    for(int i = 2; i<= N; i++){
//        if(max_root[i] > max){
//            max = max_root[i];
//        }
//    }
//
//    int cnt = 0;
//    for(auto i = 1; i <= N; i++){
//        if(max_root[i] == max){
//            if(cnt!= 0)printf("\n");
//            printf("%d", i);
//            cnt++;
//        }
//    }
//    return 0;
//} // not AC in last two cases


#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
static int n, maxheight = 0;
static vector<vector <int> > v;
static bool visit[10010];
static set<int> s;
static vector<int> temp;
static void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
int PATA1021() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {
                for(int j = 0; j < temp.size(); j++) {
                    s.insert(temp[j]);
                    if(j == 0) s1 = temp[j];
                }
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}

