#include "day1.h"

#define BUFFERLEN 6




static Profondeurs initProfondeursStrArr(char* filename);
static uint32_t* initProfondeursArr(char* profondeursStr[], const size_t lenght);


int day1Ex1(void)
{
    Profondeurs initProfondeurs = initProfondeursStrArr("day1/day1.txt");

    int32_t* profondeurs = initProfondeursArr(initProfondeurs.arr, initProfondeurs.lineCount);

    uint32_t previousProfondeur = 0;
    size_t increased = 0;
    for (size_t i = 0; i < initProfondeurs.lineCount; i++)
    {
        profondeurs[i] = atoi(initProfondeurs.arr[i]);

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
        free(initProfondeurs.arr[i]);
    }
    printf("total increased : %zu\n", increased);


    free(initProfondeurs.arr);
    free(profondeurs);

    return 0;
}

int day1Ex2(void)
{
    Window window = { 0 };

    Profondeurs initProfondeurs = initProfondeursStrArr(u8"day1/day1.txt");

    int32_t* profondeurs = initProfondeursArr(initProfondeurs.arr, initProfondeurs.lineCount);



    return 0;
}

static Profondeurs initProfondeursStrArr(char* filename)
{
    FILE* fp;
    char buffer[BUFFERLEN] = { 0 };
    size_t lineCount = 0;
    Profondeurs result = { 0 };

    fp = fopen(filename, "r");
    if (fp == NULL)
        return result;

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
        return result;
    }

    char** profondeursStr = calloc(lineCount, sizeof(char*));
    size_t i = 0;
    char** p = profondeursStr;
    while (fgets(buffer, BUFFERLEN, fp))
    {
        *p = malloc(BUFFERLEN);
        if (*p == NULL)
        {
            printf("Erreur d'allocation de mémoire.\n");
            return result;
        }
        memset(*p, 0, sizeof(BUFFERLEN));
        strcpy(*p, buffer);
        p++;
    }
    fclose(fp);
    
    result.arr = profondeursStr;
    result.lineCount = lineCount;

    return result;
}

static uint32_t* initProfondeursArr(char* profondeursStr[], const size_t lenght)
{
    int32_t* profondeurs = calloc(lenght, sizeof(int32_t));
    if (profondeurs == NULL)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return (uint32_t*)-1;
    }

    for (size_t i = 0; i < lenght; i++)
    {
        profondeurs[i] = atoi(profondeursStr[i]);
    }

    return profondeurs;
}

