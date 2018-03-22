//
//  test.cpp
//  pat
//
//  Created by 帝君 on 2018/3/8.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

#include <functional>
#include <queue>
#include <vector>
#include <iostream>

#ifndef TEMPLATE_DEMO_HXX
#define TEMPLATE_DEMO_HXX

template<typename T> class B{ // template<typename T> A{} -> template<typename T> class A{};
public:
    T g(T a, T &b);
    B(); // constructor need no type specifier: only in no out
private:
     void C(T *a); // C(T *a) -> void C(T *a); C++ requires a type specifier for all declarations
};

#endif


template <class T> void swap(T &a, T &b){ // type-irrelative code, or deem type as a argument assigned when call this function.
    
}

template<class T, class T1> class A{
public:
    T a;
    T b;
    T hy(T c, T &d);
    void h();
private:
    T c;
    T p;
    T pm(T *c, T ***d);
}; // inner type deemed as a argument and assigned when identify a variable

template<class T1, class T2> void A<T1,T2>::h(){}; // must corresponding with A // class == typename

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int test() {
    std::priority_queue<int> q;
    
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);
    
    //print_queue(q);
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);
    
    //print_queue(q2);
    
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
    
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);
    
    //print_queue(q3);
    
    int array[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    printf("%d", *(array[2]+2));
    
    return 0;
}
