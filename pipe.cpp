#include "pipe.h"

Pipe::Pipe(int a) {
    if(a==1)
    {
        Pipe_Init1();
    }
    if(a==2)
    {
        Pipe_Init2();
    }
    if(a==3)
    {
        Pipe_Init3();
    }
}

void Pipe::Pipe_Init1() {
    long_m.clear();
    short_m.clear();
    int arr_long[4][2] = {{1800, 400},
                          {2100, 400},
                          {2400, 400},
                          {2700, 400}};
    int arr_short[3][2] = {{1500, 450},
                           {7100, 450},
                           {7650, 450}};
    for (int i = 0; i < 4; i++) {
        v.push_back(arr_long[i][0]);
        v.push_back(arr_long[i][1]);
        v2.push_back(v);
        v.clear();
    }
    long_m.insert(1, v2);
    v2.clear();
    for (int i = 0; i < 3; i++) {
        v.push_back(arr_short[i][0]);
        v.push_back(arr_short[i][1]);
        v2.push_back(v);
        v.clear();
    }
    short_m.insert(1, v2);
    v2.clear();
}

void Pipe::Pipe_Init2() {
    long_m.clear();
    short_m.clear();
    int arr_long[4][2] = {{1200, 400},
                          {1500, 400},
                          {1900, 400},
                          {6500, 400}};
    int arr_short[4][2] = {{900, 450},
                           {3850, 450},
                           {4550, 450},
                           {6850, 450}};
    for (int i = 0; i < 4; i++) {
        v.push_back(arr_long[i][0]);
        v.push_back(arr_long[i][1]);
        v2.push_back(v);
        v.clear();
    }
    long_m.insert(1, v2);
    v2.clear();
    for (int i = 0; i < 4; i++) {
        v.push_back(arr_short[i][0]);
        v.push_back(arr_short[i][1]);
        v2.push_back(v);
        v.clear();
    }
    short_m.insert(1, v2);
    v2.clear();
}

void Pipe::Pipe_Init3() {
    long_m.clear();
    short_m.clear();
    int arr_long[4][2] = {{1200, 400},
                          {1600, 400},
                          {4000, 400},
                          {4500, 400}};
    int arr_short[3][2] = {{1800, 450},
                           {4250, 450},
                           {7650, 450}};
    for (int i = 0; i < 4; i++) {
        v.push_back(arr_long[i][0]);
        v.push_back(arr_long[i][1]);
        v2.push_back(v);
        v.clear();
    }
    long_m.insert(1, v2);
    v2.clear();
    for (int i = 0; i < 3; i++) {
        v.push_back(arr_short[i][0]);
        v.push_back(arr_short[i][1]);
        v2.push_back(v);
        v.clear();
    }
    short_m.insert(1, v2);
    v2.clear();
}
