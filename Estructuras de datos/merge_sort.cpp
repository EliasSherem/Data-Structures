#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *array, int p, int q, int r);
void merge_sort(int *array, int p, int r);


int main()
{
    int i;
    int A[200];
    int r , p = 0;
    srand(time(0));
    for(i=0;i<200;i++){
    	A[i]=rand() %100+1;
		printf("%d, ",A[i]);
	}
	printf("\nPresione ENTER PARA ORDENAR");
	fflush(stdin);
	getchar();
	system("cls");
	r= sizeof(A)/sizeof(A[0]) - 1;

    merge_sort(A, p, r);

    for (i = 0; i < r + 1; i++)
    {
        printf(" %i ", *(A + i));
    }
}

void merge(int *array, int p, int q, int r)
{
    int i, j, k;
    int n_1 = (q - p) + 1;
    int n_2 = (r - q);
    int *L, *R;
    L = (int*)malloc(n_1 * sizeof(int));
    R = (int*)malloc(n_2 * sizeof(int));
    for (i = 0; i < n_1; i++)
    {
        L[i] = *(array + p + i);
    }
    for (j = 0; j < n_2; j++)
    {
        R[j] = *(array + q + j + 1);
    }
    i = 0;
    j = 0;
    for (k = p; k < r + 1; k++)
    {
        if (i == n_1)
        {
            *(array + k) = *(R + j);
            j =  j+ 1;
        }
        else if(j == n_2)
        {
            *(array + k) = *(L + i);
            i = i + 1;
        }
        else
        {
            if (*(L + i) <= *(R + j))
            {
                *(array + k) = *(L + i);
                i = i + 1;
            }
            else
            {
                *(array + k) = *(R + j);
                j = j + 1;
            }
        }
    }
}

void merge_sort(int *array, int p, int r)
{
    if (p < r)
    {
        int q = (p + r)/2;
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }
}

