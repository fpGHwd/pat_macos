//
//  PATA1010.cpp
//  pat
//
//  Created by 帝君 on 2018/3/16.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

static long long C[256];
//static map<char, long long> C;
static char N1[20], N2[20];
static int T, R;

static long long to10(char s[], long long radix){
    long long ans = 0;
    int len = (int)strlen(s);
    for(int i = 0; i < len; i++){
        ans = ans * radix + C[s[i]]; // ans += ans * radix + C[s[i]]; -> ans = ans * radix + C[s[i]];
    }
    return ans;
}

static int cmp(char s[], long long radix, long long num){
    long long temp = to10(s, radix);
    if(temp < 0) return 1; // 溢出的情况
    if(temp < num)return -1;
    return (temp == num)?0:1; // here AC at 20180316 1445
}

static long long binary_search(char s[], long long left, long long right, long long num){
    long long mid;
    while(left <= right){
        mid = (left + right)/2;
        int flag = cmp(s, mid, num);
        if(flag == -1){
            left = mid + 1;
        }else if(flag == 0){
            return mid;
        }else if(flag == 1){
            right = mid -1;
        }
    }
    return -1;
}

static long long min_radix(char s[]){
    long long ans = -1, len = (int)strlen(s);
    for(int i = 0; i < len; i++) {
        if(C[s[i]] > ans) {
            ans = C[s[i]];
        }
    }
    return ans + 1;
}


int PATA1010(){
    freopen("input.txt", "r", stdin);
    for(char c = '0'; c <= '9'; c++) {
        C[c] = c - '0';
    }
    for(char c = 'a'; c <= 'z'; c++) {
        C[c] = c - 'a' + 10;
    }
    scanf("%s%s%d%d", N1, N2, &T,&R); // N1 -> &N1 by liuchuo
    if(T == 2){
        swap(N1, N2);
    }
    
    long long t = to10(N1, R);
    long long low = min_radix(N2);
    long long high = max(t, low) + 1;
    long long ans = binary_search(N2, low, high, t);
    if(ans == -1)printf("Impossible");
    else printf("%lld", ans);
    
    return 0;
}
