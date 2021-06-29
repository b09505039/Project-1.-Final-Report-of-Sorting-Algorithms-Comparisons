#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int compare(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int compare1(const void*a,const void*b){
    return *(int*)b-*(int*)a;
}
void SWAP(int* p1, int* p2, int width){
	int i = 1;
	for(i = 1; i <= width; i++){
		char tmp = *p1;
		*p1++ = *p2;
		*p2++ = tmp;
	}
	
}
void BubbleSort(int a[], int len)                   
{                                                   
	int i, j;
    int temp;
	for (i = 0; i < len - 1; i++)               
		for (j = 0; j < len - 1 - i; j++)       
			if (a[j] > a[j + 1])                
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}

void swap(int *newmin, int *first) 
{ 
    int temp = *newmin; 
    *newmin = *first; 
    *first = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j;
    int min; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 
void insertionSort(int arr[], int n)
{
    int i, j;
    int key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    clock_t start, end;
    int n=1000;
    for(int k=1;k<31;k++){
        FILE *writefile, *readfile;
        writefile = fopen("C:\\data.txt", "w");       //寫入
        readfile = fopen("C:\\data.txt", "r");        //讀取
        int i, j;
        int numbers[n*k];
        srand((unsigned)time(NULL));
        for (int i = 0; i < (n*k); ++i)
        {
            numbers[i] = (int)(rand() % (n*k));
        }

        start = clock();
        qsort(numbers, (n*k), sizeof(int), compare);
        //BubbleSort(numbers,(n*k));
        //insertionSort(numbers,(n*k));
        //selectionSort(numbers,(n*k));
        end = clock();
        double diff = end - start; 

        for (int i = 0; i < (n*k); i++)
            {
                fprintf(writefile, "%d\n", numbers[i]);
            }

        fclose(writefile);
        fclose(readfile);
        printf("%f\n",diff);
    }
    return 0;
}