#pragma once
#include "common.h"

int day1Ex1(void);
int day1Ex2(void);

typedef struct {
    char** arr;
    size_t lineCount;
}Profondeurs;

typedef struct {
    uint32_t* swap;
    uint32_t* a;
    uint32_t* b;
} Window;