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

void BubbleSort_Schwartzian (content* base, int n, size_t size, int (*compare)(content*, content*)){
	int i = 0, j;
	content* tmp[n];
	content* temp;
    content p[n];
    for(int i = 0; i < n; i++){
		tmp[i] = (content*)malloc(sizeof(content));
		tmp[i] = base+i; 
	}
	for(i = 0; i < n; i++){
		for(j = n-1; j > i; j--){
			
			if(compare(tmp[j], tmp[j-1]) == -1){
				temp = tmp[j];
			    tmp[j] = tmp[j-1];
			    tmp[j-1] = temp;
			}
		}
	}
    for(i = 0; i < n; i++){
        p[i].progress = tmp[i]->progress;
        strcpy((char*)p[i].name, (char*)tmp[i]->name);
		p[i].lastscore=tmp[i]->lastscore;
		p[i].thisscore=tmp[i]->thisscore;
	}	
	for(i = 0; i < n; i++){
        base[i].progress = p[i].progress;
        strcpy((char*)base[i].name, (char*)p[i].name);
		base[i].lastscore=p[i].lastscore;
		base[i].thisscore=p[i].thisscore;
	}		
}

void SelectionSort_Schwartzian (content* base, int n, size_t size, int (*compare)(content*, content*)){          //失敗
	int i = 0, j;
	content* tmp[n];
	content* temp;
    content p[n];
	for(int i = 0; i < n; i++){
		tmp[i] = (content*)malloc(sizeof(content));
		tmp[i] = base+i; 
	}
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			if( compare(tmp[j], tmp[j-1]) == -1){
				temp = tmp[j];
			    tmp[j] = tmp[j-1];
			    tmp[j-1] = temp;
			}
		}
	}
    for(i = 0; i < n; i++){
        p[i].progress = tmp[i]->progress;
        strcpy((char*)p[i].name, (char*)tmp[i]->name);
		p[i].lastscore=tmp[i]->lastscore;
		p[i].thisscore=tmp[i]->thisscore;
	}	
	for(i = 0; i < n; i++){
        base[i].progress = p[i].progress;
        strcpy((char*)base[i].name, (char*)p[i].name);
		base[i].lastscore=p[i].lastscore;
		base[i].thisscore=p[i].thisscore;
	}	
}

void insertionsort_Schwartzian (content* base, int n, size_t size, int (*compare)(content*, content*)){
	int i = 0, j;
	content* temparr[n];
	content* temp;
    content trans[n];
	for(int i = 0; i < n; i++){
		temparr[i] = (content*)malloc(sizeof(content));
		temparr[i] = base+i; 
	}
	for(i = 0; i < n; i++){
		j = i;
		while(j > 0 && compare(temparr[j], temparr[j-1]) == -1){
			temp = temparr[j];
			temparr[j] = temparr[j-1];
			temparr[j-1] = temp;
			j--;
		}
	}
	for(i = 0; i < n; i++){
        trans[i].progress = temparr[i]->progress;
        strcpy((char*)trans[i].name, (char*)temparr[i]->name);
		trans[i].lastscore=temparr[i]->lastscore;
		trans[i].thisscore=temparr[i]->thisscore;
	}	
	for(i = 0; i < n; i++){
        base[i].progress = trans[i].progress;
        strcpy((char*)base[i].name, (char*)trans[i].name);
		base[i].lastscore=trans[i].lastscore;
		base[i].thisscore=trans[i].thisscore;
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
    for(int k=1;k<31;k++){
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

        insertionsort_Schwartzian (Content, (n*k), sizeof(content), compare);
        BubbleSort_Schwartzian (Content, (n*k), sizeof(content), compare);
        //SelectionSort_Schwartzian (Content, (n*k), sizeof(content), compare);
     
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