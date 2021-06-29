#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct 
{
    int progress;
    char name[10];
    int lastscore;
    int thisscore;
    
}content;

char *names[10] = {"BLAKE","ODIN", "JADA", "KELVIN", "KALEB", "PIPER", "JAYSON", "JULIAN", "ANDI", "ABBY"};

int compare_progress(int n, int m)
{
    if (n == m)
        return 0;
    else if (n < m)
        return 1;
    else if (n > m)
        return -1;
}
int compareName(char* ch1, char* ch2){
	if(*ch1 == *ch2 && *ch1 != '\0')
		return compareName(ch1+1, ch2+1);
	else if(*ch1 == *ch2)
		return 0;
	else if(*ch1 < *ch2)
		return -1;
	else if(*ch1 > *ch2)
		return 1;
}
int compare(content *pt1, content *pt2)
{
    int d = compare_progress(pt1->progress, pt2->progress);
    int e = compareName(pt1->name, pt2->name);
	int f = compare_progress(pt1->lastscore, pt2->lastscore);
	int g = compare_progress(pt1->thisscore, pt2->thisscore);
    if (d == -1)
        return -1;
    else if (d == 1)
        return 1;
    else{
		if(e == -1)
			return -1;
		else if(e == 1)
			return 1;
		else{
			if(f == -1)
				return -1;
			else if(f == 1)
				return 1;
			else{
				if(g == -1)
					return -1;
				else if(g == 1)
					return 1;
				else
					return 0;
			}
        }
    }
    //return (*(int *)a - *(int *)b);
}

void SWAP(char* p1, char* p2, int width){
	int i = 1;
	for(i = 1; i <= width; i++){
		char tmp = *p1;
		*p1++ = *p2;
		*p2++ = tmp;
	}
	
}

void bubbleSort(void *base, int n, size_t width, int (*compare)(const void *, const void *)){
	int i = 0, j, temp;
	for(i = 0; i < n; i++){
		for(j = n-1; j > i; j--){
			temp = (compare)((char*)(base + j*width), (char*)(base + (j-1)*width));
			if(temp == -1){
				SWAP((char*)(base + j*width), (char*)(base + (j-1)*width), width);
			}
		}
	}
}

void selectionSort(void *base, int n, size_t width, int (*compare)(const void *, const void *)){
	int i = 0, j, tmp;
	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if((compare)((char*)(base + i*width), (char*)(base + (j)*width)) > 0){
				SWAP((char*)(base + i*width), (char*)(base + (j)*width), width);
			}
		}
	}
}

void insertion_Sort(void *base, int n, size_t width, int (*compare)(const void *, const void *))
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && (compare((char*)base+j*width,(char*)base+(j-1)*width))<0)
        {
            SWAP((char*)base + j*width, (char*)base + (j - 1)*width,width);
            j--;
        }
    }
}

swap(char *p, char *q)
{
    while (*p != '\0')
    {
        *q++ = *p++;
    }
    *q = '\0';
}

int main()
{
    clock_t start, end;
    int n=1000;
    char *Name[1];
    for(int k=1;k<2;k++){
        FILE *writefile, *readfile;
        writefile = fopen("C:\\data.txt", "w");       //寫入
        readfile = fopen("C:\\data.txt", "r");        //讀取
        int i, j;
        content Content[n*k];

        srand((unsigned)time(NULL));
        for (int i = 0; i < (n*k); ++i)
        {
            //隨機生成
            Content[i].lastscore = (rand() % 1000);
            Content[i].thisscore = (rand() % 1000);
            Content[i].progress = Content[i].thisscore - Content[i].lastscore;
            j = rand()%10;
            Name[0] = names[j];
            swap(Name[0], Content[i].name);
        }

        start = clock();

        qsort(Content, (n*k), sizeof(content), compare);
        selectionSort(Content, (n*k), sizeof(content), compare);
        insertion_Sort(Content, (n*k), sizeof(int), compare);
        bubbleSort(Content, (n*k), sizeof(int), compare);
        
        end = clock();
        double diff = end - start; 

        fprintf(writefile, "progress    name    score   last score\n");
        for (int i = 0; i < (n*k); i++)
        {
            fprintf(writefile, "%8d%8s%9d%13d\n", Content[i].progress, Content[i].name, Content[i].thisscore, Content[i].lastscore);    //寫入檔案
        }
        
        fclose(writefile);
        fclose(readfile);
        printf("%f\n",diff);
    }
    return 0;
}