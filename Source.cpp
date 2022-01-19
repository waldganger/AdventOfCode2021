#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define BUFFERLEN 6

int main(void)
{
    FILE *fp;
    char buffer[BUFFERLEN] = {0};
    size_t lineCount = 0;

    fp = fopen("day1/day1.txt", "r");
    if (fp == NULL)
        return 1;

    while (fgets(buffer, BUFFERLEN, fp))
    {
        // printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
        lineCount++;
    }
    fclose(fp);
    puts("\n");
    printf("Number of lines : %zu\n", lineCount);

    char *profondeursStr[lineCount];
    size_t i = 0;

    fp = fopen("day1/day1.txt", "r");
    if (fp == NULL)
        return 1;

    while (fgets(buffer, BUFFERLEN, fp))
    {
        // printf("%s", buffer);
        profondeursStr[i] = malloc(BUFFERLEN);
        memset(profondeursStr[i], 0, sizeof(BUFFERLEN));

        strcpy(profondeursStr[i], buffer);
        i++;
    }

    int32_t profondeurs[lineCount];

    uint32_t previousProfondeur = 0;
    size_t increased = 0;
    for (size_t i = 0; i < lineCount; i++)
    {
        profondeurs[i] = atoi(profondeursStr[i]);

        if (i == 0)
        {
            printf("%" PRId32 " (N/A - no previous measurement)\n", profondeurs[i]);
            previousProfondeur = profondeurs[i];
        }
        else
        {
            if (profondeurs[i] > previousProfondeur)
            {
                printf("%" PRId32 " (increased)\n", profondeurs[i]);
                increased++;
            }
            else
            {
                printf("%" PRId32 " (decreased)\n", profondeurs[i]);
            }
        }
        previousProfondeur = profondeurs[i];
        free(profondeursStr[i]);
    }
    fclose(fp);
    printf("total increased : %zu\n", increased);

    return 0;
}