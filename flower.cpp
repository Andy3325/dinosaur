#include "flower.h"
#include<iostream>

Flower::Flower(int a) {
    if(a==2)
    {
        Flower_Init2();
    }
    if(a==3)
    {
        Flower_Init3();
    }
}

void Flower::Flower_Init2() {
    m.clear();
    int arr[1][2] = {{2250, 320}};
    for (int i = 0; i < 1; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(1);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
}

void Flower::Flower_Init3() {
    m.clear();
    int arr[1][2] = {{2700, 320}};
    for (int i = 0; i < 1; i++) {
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        v.push_back(1);
        v2.push_back(v);
        v.clear();
    }
    m.insert(1, v2);
}

