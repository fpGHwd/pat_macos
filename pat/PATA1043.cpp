//
//  PATA1043.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <vector>

#define MAX_NUM_NODES 1000

using namespace std;

struct node{
    struct node*lchild,*rchild;
    int value;
};

static int N; // Number of preorder size == BST tree
static vector<int> preorder_seq;
static struct node *tree = NULL;

static void insert(struct node **root, int value){ // use recursion will decrease complexity
    struct node *p = new struct node;
    p->value = value;
    p->lchild = NULL;
    p->rchild = NULL;
    
    if(*root == NULL){
        *root = p;
        return;
    }
    
    struct node *w = *root; // value's parent node
    while((value < w->value && w->lchild != NULL) || (value >= w->value && w->rchild != NULL)){
        if(value < w->value)w = w->lchild;
        else w = w->rchild;
    }
    
    if(value < w->value){
        w->lchild = p;
    }else{
        w->rchild = p;
    }
    return;
}

static void mirror_preorder(vector<int> &seq, struct node *root){
    if(root == NULL){
        return;
    }else{
        seq.push_back(root->value);
        mirror_preorder(seq, root->rchild);
        mirror_preorder(seq, root->lchild);
    }
}

static void preorder(vector<int> &seq, struct node *root){
    if(root == NULL){
        return;
    }else{
        seq.push_back(root->value);
        preorder(seq, root->lchild);
        preorder(seq, root->rchild);
    }
}

static void postorder(vector<int> &seq, struct node *root){
    if(root == NULL)return;
    postorder(seq,root->lchild);
    postorder(seq, root->rchild);
    seq.push_back(root->value);
}

static void mirror_postorder(vector<int>&seq, struct node *root){
    if(root == NULL)return;
    mirror_postorder(seq, root->rchild);
    mirror_postorder(seq, root->lchild);
    seq.push_back(root->value);
}

int PATA1043(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    int node_value;
    for(int i = 0; i < N; i++){
        scanf("%d", &node_value);
        preorder_seq.push_back(node_value);
    }
    
    // write the root node to the insert
    for(vector<int>::iterator it = preorder_seq.begin(); it != preorder_seq.end(); it++){
        insert(&tree, *it);
    }
    
    vector<int> mir_pre, pre, post, mirror_post;
    preorder(pre, tree);
    mirror_preorder(mir_pre, tree);
    if(pre == preorder_seq){
        printf("YES\n");
        postorder(post, tree);
        for(vector<int>::iterator it = post.begin(); it!=post.end(); it++){
            if(it != post.begin())
                printf(" ");
            printf("%d", *it);
        }
    }else if(mir_pre == preorder_seq){
        printf("YES\n");
        mirror_postorder(mirror_post, tree);
        for(vector<int>::iterator it = mirror_post.begin(); it!=mirror_post.end(); it++){
            if(it != mirror_post.begin())
                printf(" ");
            printf("%d", *it);
        }
    }else{
        printf("NO");
    }
    
    return 0;
} // 20180228 1647 // AC
