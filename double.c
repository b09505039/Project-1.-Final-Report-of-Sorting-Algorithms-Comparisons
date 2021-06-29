#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    if (*(double *)a > *(double *)b)
        return 1;
    else if (*(double *)a < *(double *)b)
        return -1;
    else
        return 0;
}
int compare1(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
void SWAP(int *p1, int *p2, int width)
{
    int i = 1;
    for (i = 1; i <= width; i++)
    {
        char tmp = *p1;
        *p1++ = *p2;
        *p2++ = tmp;
    }
}
void BubbleSort(double a[], int len)
{
    int i, j;
    double temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

void swap(double *newmin, double *first)
{
    double temp = *newmin;
    *newmin = *first;
    *first = temp;
}

void selectionSort(double arr[], int n)
{
    int i, j;
    int min;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(&arr[min], &arr[i]);
    }
}
void insertionSort(double arr[], int n)
{
    int i, j;
    double key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
int main()
{
    clock_t start, end;
    int n = 1000;
    for (int k = 1; k < 31; k++)
    {
        FILE *writefile, *readfile;
        writefile = fopen("C:\\data.txt", "w"); //寫入
        readfile = fopen("C:\\data.txt", "r");  //讀取
        int i, j;
        double numbers[n * k];

        srand((unsigned)time(NULL));
        for (int i = 0; i < (n * k); ++i)
        {
            numbers[i] = fRand((double)0, (double)n * k);
        }

        start = clock();
        qsort(numbers, (n*k), sizeof(double), compare);
        //BubbleSort(numbers,(n*k));
        //insertionSort(numbers, (n * k));
        //selectionSort(numbers,(n*k));
        end = clock();
        double diff = end - start;
        for (int i = 0; i < (n * k); i++)
        {
            fprintf(writefile, "%f\n", numbers[i]);
        }
        fclose(writefile);
        fclose(readfile);
        printf("%f\n", diff);
    }
    return 0;
}