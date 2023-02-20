#include <stdio.h>
#include <math.h>
#define NMAX 30
#define sigma return sqrt;

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n);
int Sigma(int *a, int n, int *q);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    if(input(data, &n)){
    printf("%d\n", search(data, n));
    }
    return 0;
}
int input(int *a, int *n)
{
    char c=0;
    if(scanf("%d", n))
    for(int *p = a; p - a < *n; p++)
    {
        scanf("%d", p);
    }
    else{
        printf("n/a\n");
    }
}
void output(int *a, int n)
{
    {
    for(int *p = a; p - a < n-1; p++)
     printf("%d ", *p);
     printf("%d\n", *(a + n - 1));
    }

}
    int max(int *a, int n){
        int max = *a;
        for(int *p = a + 1; p - a < n; p++)
        if(*p >max)
        max = *p;
        return max;
    }
     int min(int *a, int n){
        int min = *a;
        for(int *p = a + 1; p - a < n; p++)
        if(*p <min)
        min = *p;
        return min;
    }
       double mean(int *a, int n){
        double mean = 0;
        for(int *p = a; p - a < n; p++){
            mean += ((double)(*p))/n;
        }
        return mean;
    }
    double variance(int *a, int n){
        double variance = 0;
        double m = mean (a, n);
        for(int *p = a; p - a < n; p++)
        variance += pow(*p - m, 2)/n;
        return variance;
    }
    int Sigma(int *a, int n, int *q){
       if ((*q - mean (a, n)) <= 3 * sqrt(variance (a, n))){
        return 1;
       }else{
        return 0;
        printf("%d\n", *q);
       }
    }
    int search(int *a, int n){
        double m = mean (a, n);
        for(int *p = a; p - a < n; p++){
            if(*p %2 == 0 && *p!=0 && *p > m && Sigma(a, n, p)){
                return *p;
            }
        }
        return 0;
    }




