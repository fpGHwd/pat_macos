//
//  PATA1034.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

struct Node{
    string name;
    int w;
    Node(string _name):name(_name) {};
};

#define MAX_NUM 1000
static const int maxn = 2010;
static map<string, int> str_to_int; // map is hash
static map<int, string> int_to_str;
static vector<struct Node> Adj[1000]; // 可以做の
static int G[maxn][maxn] = {0}; // 少一个边权的记录
static int W[maxn] = {0};
static int N,K;

static int persons_num = 0;
static int change(string name){
    if(str_to_int.find(name) != str_to_int.end()){
        return str_to_int[name];
    }else{
        str_to_int[name] = persons_num;
        int_to_str[persons_num] = name;
        return persons_num++;
    }
}

static int visited[maxn] = {0};
static void DFS(int u, int &head, int &mbs, int &total){
    visited[u] = 1;
    mbs++;
    for(int v = 0; v<N; v++){
        if( G[u][v] > 0){
            if(W[v] > W[head])head = v;
            total += G[u][v]; // 要加可能绕圈的权
            G[u][v] = G[v][u] = 0; // 此处好像没有意义 //因为不可能绕圈，所以不会重复添加绕圈的权 // uncomment and AC
            if(visited[v] == 0) // 不能绕圈
                DFS(v, head, mbs,total);
        }
    }
}

// modify by map
static map<string, int> gangs; // from the output format this appearence

static int gangs_num = 0;
static int gangs_head[maxn] = {0}, gangs_members[maxn] = {0};// the relationship between node index and name on string, and the core is in the textbook of suanfabiji or classic textbook which is enough
static void DFStravel(){
    for(int i = 0; i < N; i++)
        if(visited[i] == 0){
            int head = i, mbs = 0, total_call_len = 0;
            DFS(i, head, mbs, total_call_len);
            if(total_call_len > K && mbs > 2){ // a gang is outside, so it's very natural // abstract is factor and so is vivid
                /*
                gangs_head[gangs_num] = head;
                gangs_members[gangs_num] = mbs;
                gangs_num++;
                 */
                gangs[int_to_str[head]] = mbs; // 此处应该放int_to_str[head]而不是int_to_str[i],另外对于map的用法的不清楚，其实完全没有对抽象的时空转换进行纯粹化，本质是没有足够的纯粹。其实map就是两个东西，一个可以过去一个可以过来。//所以对于不了解的东西，一定要去主动思考，而不是放在那里，其实都是比较容易的。
            }
        }
}

int PATA1034(){
    freopen("input.txt", "r", stdin);
    cin >> N >> K;
    string a, b;
    int len;
    for(int i = 0; i< N; i++){
        cin >> a >> b >> len;
        int id1 = change(a);
        int id2 = change(b);
        W[id1] += len;
        W[id2] += len;
        G[id1][id2] += len;
        G[id2][id1] += len;
    }
    DFStravel();
//    cout << gangs_num << endl;
    cout << gangs.size() << endl;
    for(map<string, int>::iterator it = gangs.begin(); it!= gangs.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    /*
    for(int i = 0; i< gangs_num; i++){
        cout << int_to_str[gangs_head[i]] << " " << gangs_members[i] << endl;
    }
     */
    
    return 0;
} // 20180302 1525 AC the sample // AC @ 20180317 1945
