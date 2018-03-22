//
//  ANOJ1001.cpp
//  pat
//
//  Created by 帝君 on 2018/3/11.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

struct node_anoj100{
    int v;
    struct node_anoj100 *lchild, *rchild;
}*tree;
static int N;
static void build(struct node_anoj100* &t, int v){
    auto p = new struct node_anoj100;
    p->v = v;
    p->lchild = p->rchild = NULL;
    if(t == NULL){
        t = p;
    }else{
        if(p->v > t->v){
            build(t->rchild, p->v); // 递归建立右子树
        }else{
            build(t->lchild, p->v); // 递归建立左子树
        }
    }
}

static int level_num = 0;
static void level(struct node_anoj100 *t){
    queue<struct node_anoj100*> q;
    q.push(t); // 将根节点添加到队列中
    struct node_anoj100 *w;
    while(!q.empty()){
        w = q.front();
        if(level_num != 0)printf(" ");
        printf("%d", w->v); // 打印取出结点的(存储的)值
        level_num++;
        q.pop();
        if(w->lchild){ // 如果存在左结点，则添加左结点
            q.push(w->lchild);
        }
        if(w->rchild){ // 如果存在右结点，则添加右结点
            q.push(w->rchild);
        }
    }
}

int ANOJ1001(){
    freopen("input.txt", "r", stdin); // 读取数据
    scanf("%d", &N);
    int temp;
    for(int i = 0; i< N; i++){
        scanf("%d", &temp);
        build(tree, temp); // 每获得一个结点值，插入到tree中，tree这里是一个全局指针
    }
    level(tree); // 层序遍历该树
    
    return 0;
}
