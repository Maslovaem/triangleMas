#include <stdio.h>
#include <assert.h>

void printTriangleMas(const int *mas, int rows);
void get_mas(int nElements, int* mas, FILE *fp);
void count_nElements_rows(int *nElements, int *rows, FILE *fp);

int main(void)
{
    int rows = 0;
    int nElements = 0;

    FILE *fp = NULL;
    fp = fopen("mas.txt", "r");
    assert(fp != NULL);

    count_nElements_rows(&nElements, &rows, fp);

    int mas[nElements] = {};

    get_mas(nElements, mas, fp);
    printTriangleMas(mas, rows);

    fclose(fp);

    return 0;
}

void printTriangleMas(const int *mas, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%2d ", *(mas + (i * (i+1) )/2 + j) );
        }
        printf("\n");
    }
}

void get_mas(int nElements, int* mas, FILE *fp)
{
    assert(mas != NULL);
    assert(fp != NULL);

    fseek(fp, 0L, SEEK_SET);

    for(int i = 0; i < nElements; i++)
    {
        fscanf(fp, "%d", &mas[i]);
    }

}

void count_nElements_rows(int *nElements, int *rows, FILE *fp)
{
    assert(nElements != NULL);
    assert(rows != NULL);
    assert(fp != NULL);

    int temp = 0;

    while (fscanf(fp, "%d", &temp) != EOF)
    {
        (*nElements)++;

        if( (temp = fgetc(fp)) == '\n')
        {
            (*rows)++;
        }
    }
}
