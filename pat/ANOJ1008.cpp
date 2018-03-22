//
//  problem2.cpp
//  pat
//
//  Created by 帝君 on 2018/3/11.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

static int N;

static struct node1008{
    int value;
    struct node1008 *lchild, *rchild;
}*t1, *t2;

static void post_(vector<int> &v, struct node1008 *t){
    if(t == NULL)
        return;
    else{
        post_(v, t->lchild); // 后序遍历左子树
        post_(v, t->rchild); // 后序遍历右子树
        v.push_back(t->value); // 更新v
    }
}
static void level(vector<int> &v, struct node1008 *t){ // 求层序遍历的序列
    queue<struct node1008*> temp;
    if(t != NULL)
        temp.push(t);
    else
        return;
    struct node1008 *no;
    while(!temp.empty()){
        no = temp.front();
        temp.pop();
        v.push_back(no->value);
        if(no->lchild != NULL)
            temp.push(no->lchild);
        if(no->rchild!= NULL)
            temp.push(no->rchild);
    }
}
static void in_(vector<int> &v, struct node1008 *t){
    if(t == NULL){
        return;
    }else{
        in_(v, t->lchild); // 中序遍历左子树
        v.push_back(t->value); // 更新v
        in_(v, t->rchild); // 中序遍历右子树
    }
}

static void build_tree(struct node1008* &t, int v){ // v即为要插入的点，和p是一致的
    struct node1008* p = new struct node1008;
    p->value = v;
    p->lchild = p->rchild = NULL;
    if(t == NULL){
        t = p; // 此处t是引用类型
        return;
    }else{
        if(p->value > t->value) // 要插入的从没
            build_tree(t->rchild, v); // recurssion // 左子树递归建立树
        else if(p->value < t->value)
            build_tree(t->lchild, v); // 右子树递归建立树
    }
}

int ANOJ1008(){
    freopen("input.txt", "r", stdin); // 读取数据
    
    scanf("%d", &N);
    int temp;
    for(int i = 0; i< N; i++){
        scanf("%d", &temp);
        build_tree(t1 , temp); // 建立第一棵树
    }
    for(int i = 0; i< N; i++){
        scanf("%d", &temp);
        build_tree(t2, temp); // 建立第二棵树
    }
    
    vector<int> in1, in2, po1, po2, lev1;
    post_(po1, t1); // 求树1的后序遍历序列
    post_(po2, t2); // 求树2的后序遍历序列
    if(po1 == po2){ // 后序一样
        in_(in1, t1); // 求树1的中序遍历序列
        in_(in2, t2); // 求树2的中序遍历序列
        if(in1 == in2) // 中序一样
            printf("YES"); // 后序和中序的序列都一样时才能输出是一样的序列
        else
            printf("NO");
    }else
        printf("NO");
    printf("\n");
    for(int i = 0; i < po1.size(); i++){ // 打印树1的后序遍历序列
        if(i != 0)printf(" ");
        printf("%d", po1[i]);
    }
    printf("\n");
    level(lev1, t1); // 求序列1的层序遍历序列
    for(int i = 0; i < lev1.size(); i++){ // 打印序列1的层序遍历序列
        if(i!= 0)printf(" ");
        printf("%d", lev1[i]);
    }
    
    return 0;
} // AC @ 20180312 0921
