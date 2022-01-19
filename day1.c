#include "day1.h"

#define BUFFERLEN 6

int day1Ex1(void)
{
    FILE* fp;
    char buffer[BUFFERLEN] = { 0 };
    size_t lineCount = 0;

    fp = fopen("day1/day1.txt", "r");
    if (fp == NULL)
        return 1;

    while (fgets(buffer, BUFFERLEN, fp))
    {
        memset(buffer, 0, sizeof(buffer));
        lineCount++;
    }
    fclose(fp);
    puts("\n");
    printf("Number of lines : %zu\n", lineCount);

    fp = fopen("day1/day1.txt", "r");
    if (fp == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char** profondeursStr = calloc(lineCount, sizeof(char*));
    size_t i = 0;
    char** p = profondeursStr;
    while (fgets(buffer, BUFFERLEN, fp))
    {
        //profondeursStr[i] = malloc(BUFFERLEN);
        //memset(profondeursStr[i], 0, sizeof(BUFFERLEN));

        //strcpy(profondeursStr[i], buffer);
        //i++;
        *p = malloc(BUFFERLEN);
        if (*p == NULL)
        {
            printf("Erreur d'allocation de mémoire.\n");
            return 1;
        }
        memset(*p, 0, sizeof(BUFFERLEN));
        strcpy(*p, buffer);
        p++;
    }

    int32_t* profondeurs = calloc(lineCount, sizeof(int32_t));

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


    free(profondeursStr);
    free(profondeurs);

    return 0;
}

int day1Ex2(void)
{
    return 0;
}