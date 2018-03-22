//
//  AVL.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node{
    int v, height;
    struct node *lchild, *rchild;
};

static node *newNode(int v){
    node *n = new node;
    n->v = v;
    n->height = 1; // initiate height = 1
    n->lchild = n->rchild = NULL;
    return n;
}

static int getHeight(node *root){
    if(root == NULL)return 0;
    return root->height; // not very useful
}

// get balance factor
static int getBalanceFactor(node *root){
    int h = getHeight(root->lchild) - getHeight(root->rchild);
//    if(h < 0)h = -h; // should not redeem it as a positive integer when h is not equal to 1
    return h;
}

static void updateHeight(node *root){ // use pointer then can update
    root->height = max(getHeight(root->lchild), getHeight(root->rchild));
}

//static node* search(node *root, int value){
//    if(root== NULL)return NULL;
//    if(root->v == value){
//        return root;
//    }
//    node* ret = NULL;
//    ret = search(root->lchild, value);
//    if(ret != NULL){
//        return ret;
//    }
//    return search(root->rchild, value);
//}

static void L(node *&root){
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root); // first update A
    updateHeight(temp); // then update B
    root = temp;
}

static void R(node *&root){
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
} // textbook code is not clear // all thing when say that it's not good is really say the structure isn't well

static void insert(node *&root, int value){ // node *root -> node *&root
    if(root == NULL){
        root = newNode(value);
        return;
    }
    if(value < root->v){
        insert(root->lchild, value);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild, value);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->lchild) == -1){
                L(root);
            }else if(getBalanceFactor(root->lchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

static node *Create(int data[], int n, node *&root){ // data[] is nodes[]
//    node *root = NULL;
    for(int i = 0; i< n; i++){
        insert(root, data[i]);
    }
    return root;
}

int AVL(void){
    int data[20] = {6,5,2,7,4,8,3,0,9,1}, len = 10;
    node *root = NULL;
    Create(data, len, root);
    return 0;
} 
