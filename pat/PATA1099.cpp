//
//  PATA1099.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// use seperated info to make a bst, and get its character(level travesal sequence)
// no need to save value, just use node's index

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const int maxn = 110;
static struct node_pat1099{
    int data;
    int lchild, rchild;
}Node[maxn];
static int n, in[maxn], num;

static void inOrder(int root){
    if(root == -1)return;
    inOrder(Node[root].lchild);
    Node[root].data = in[num++]; // brilliant
    inOrder(Node[root].rchild);
}

static void BFS(int root){
    queue<int> q;
    q.push(root);
    num = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(num != 0)printf(" ");
        printf("%d", Node[u].data);
        num++;
        if(Node[u].lchild != -1)q.push(Node[u].lchild);
        if(Node[u].rchild != -1)q.push(Node[u].rchild);
    }
}

int PATA1099(void){
    int lchild,rchild;
    scanf("%d", &n);
    for(int i = 0; i< n; i++){
        scanf("%d%d", &lchild, &rchild);
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(int i = 0; i <n; i++){
        scanf("%d", &in[i]);
    }
    sort(in, in+n);
    inOrder(0);
    BFS(0);
    
    return 0;
}


//
//#define MAX_NODES 110
//
//static struct Node{
//    struct Node *lchild, *rchild;
//    int value;
//    int index;
//}BST;
//static vector<int> input_seq;
//
//static void insert(struct Node *root, int node, int l, int r, bool &flag){
//    if(root == NULL || flag == true)return;
//    if(root->index == node){
//        if(l != -1){
//            struct Node *p = new struct Node;
//            p->lchild = p->rchild = NULL;
//            p->index = l;
//            root->lchild = p; // forget to assign
//        }
//        if(r != -1){
//            struct Node *p = new struct Node;
//            p->lchild = p->rchild = NULL;
//            p->index = r;
//            root->rchild = p;
//        }
//        flag = true;
//    }
//    insert(root->lchild, node, l, r, flag);
//    insert(root->rchild, node, l, r, flag);
//}
//
//static void in_order_traversal(struct Node *t, vector<int> &v){
//    if(t == NULL)return;
//    in_order_traversal(t->lchild, v);
//    v.push_back(t->index);
//    in_order_traversal(t->rchild, v);
//}
//
//static void level_traversal(struct Node *t, vector<int> &v){
//    queue<struct Node*> q;
//    if(t == NULL)return;
//    q.push(t);
//    struct Node *work;
//    while(!q.empty()){
//        work = q.front();
//        v.push_back(work->index);
//        q.pop();
//        if(work->lchild != NULL)
//            q.push(work->lchild);
//        if(work->rchild != NULL)
//            q.push(work->rchild);
//    }
//}
//
//int PATA1099(void){
//    freopen("input.txt", "r", stdin);
//    int N;
//    scanf("%d", &N);
//    BST.index = 0;
//    int left, right;
//    for(int i = 0; i< N; i++){
//        scanf("%d%d", &left, &right);
//        bool flag = false;
//        insert(&BST, i, left, right, flag);
//    }
//
//    int index;
//    for(int i = 0; i< N; i++){
//        scanf("%d", &index);
//        input_seq.push_back(index);
//    }
//    sort(input_seq.begin(), input_seq.end());
//
//    vector<int> pre, level;
//    in_order_traversal(&BST, pre);
//    level_traversal(&BST, level);
//
//    int hashT[MAX_NODES];
//    for(int i = 0; i< N; i++){
//        hashT[level[i]] = i;
//    }
//
//    int ans[MAX_NODES] = {0}, temp;
//    for(int i = 0; i< N; i++){
//        temp = input_seq[i];
//        ans[hashT[pre[i]]] = temp;
//    }
//
//    for(int i = 0; i< N; i++){
//        if(i != 0)
//            printf(" ");
//        printf("%d", ans[i]);
//    }
//    return 0;
//} // 20180228 1946 AC the sample // not AC:  segment fault

