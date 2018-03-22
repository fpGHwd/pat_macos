//
//  anoj-problem4.cpp
//  pat
//
//  Created by 帝君 on 2018/3/11.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

static struct node_anoj1005{
    int v;
    struct node_anoj1005 *lchild, *rchild;
}*tree;

static const int max_n = 31;
static int inSeq[max_n], n;
vector<int> level;

static struct node_anoj1005* build(vector<int> &v, int inL, int inR){
    if(v.size() == 0){ // 如果v中没有元素，也可以为inL == inR
        return NULL;
    }else{
        auto root = new node_anoj1005;
        root->v = v[0];
        int k;
        for(k = inL; k <= inR; k++){ // 找到根结点和根结点在中序遍历序列的位置k
            if(inSeq[k] == v[0]){
                break;
            }
        }
        
        vector<int> v_l, v_r; // 左子树的层次遍历序列，右子树的层次遍历序列
        int left;
        for(int i = 1; i < v.size(); i++){ // from 1 to less than v.size(), CRITICAL // 遍历并检查原v中的元素是在左子树，还是右子树
            left = 0;
            for(int j = inL; j < k; j++){
                if(v[i] == inSeq[j]){ // 如果在中序序列的左部分元素中找到层序序列的元素，说明这个元素应该被放到左子树的层序序列中
                    left = 1;
                    break;
                }
            }
            if(left){
                v_l.push_back(v[i]); // 加入到左子树的层序遍历序列中
            }else{
                v_r.push_back(v[i]); // 加入到右子树的层序遍历序列中
            }
        }
        
        root->lchild = build(v_l, inL, k-1); // 递归建立左子树
        root->rchild = build(v_r, k+1, inR); // 递归建立右子树
        return root;
    }
}

static int num_pre = 0;
static void pre_order(struct node_anoj1005 *t){
    if(t == NULL){ // 到根结点(其实是根结点)返回
        return;
    }else{
        if(num_pre != 0)printf(" "); // 打印第一个元素的时候不打印空格
        printf("%d", t->v);
        num_pre++;
        pre_order(t->lchild); // 递归遍历左子树
        pre_order(t->rchild); // 递归遍历右子树
    }
}

static int num_post = 0;
static void post_order(struct node_anoj1005 *t){ // 后序遍历
    if(t == NULL){ // 到达叶子结点，返回
        return;
    }else{
        post_order(t->lchild); // 遍历左子树
        post_order(t->rchild); // 遍历右子树
        if(num_post != 0)printf(" "); // 打印第一个元素的时候不打印空格
        printf("%d", t->v);
        num_post++;
    }
}

int ANOJ1005(){
    freopen("input.txt", "r", stdin); // 读取数据
    scanf("%d", &n);
    int temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        level.push_back(temp); // 组成层序序列
    }
    for(int i = 0; i< n; i++){
        scanf("%d", &inSeq[i]); // 获得中序序列
    }
    tree = build(level, 0, n-1); // 建立这棵树
    pre_order(tree); // 先序遍历并打印
    printf("\n");
    post_order(tree); // 后续遍历并打印
    
    
    return 0;
}
