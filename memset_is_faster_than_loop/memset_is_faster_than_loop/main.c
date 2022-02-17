#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define ARR_SIZE 100000
#define EPOCH 10000

int main()
{
    clock_t start, end;
    uint8_t arr[ARR_SIZE];
    uint8_t arr2[ARR_SIZE];
    uint32_t epoch, i;

    printf("Epoch:%ld, array size:%ld\n", EPOCH, ARR_SIZE);

    end = 0;
    for (epoch = 0; epoch < EPOCH; epoch++)
    {
        start = clock();
        memset(arr, 127, sizeof(uint8_t) * ARR_SIZE);
        end += clock() - start;
    }
    printf("memset   :%.9lfs\n", (double)end / CLOCKS_PER_SEC);

    end = 0;
    for (epoch = 0; epoch < EPOCH; epoch++)
    {
        start = clock();
        for (i = 0; i < ARR_SIZE; i++) arr[i] = 127;
        end += clock() - start;
    }
    printf("loop set :%.9lfs\n", (double)end / CLOCKS_PER_SEC);

    end = 0;
    for (epoch = 0; epoch < EPOCH; epoch++)
    {
        start = clock();
        memcpy(arr, arr2, sizeof(uint8_t) * ARR_SIZE);
        end += clock() - start;
    }
    printf("memcpy   :%.9lfs\n", (double)end / CLOCKS_PER_SEC);

    end = 0;
    for (epoch = 0; epoch < EPOCH; epoch++)
    {
        start = clock();
        for (i = 0; i < ARR_SIZE; i++) arr[i] = arr2[i];
        end += clock() - start;
    }
    printf("loop copy:%.9lfs\n", (double)end / CLOCKS_PER_SEC);

    return 0;
}
