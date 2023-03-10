#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    if(input(data, &n)){
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

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
void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v){
                    printf("%d %d %.6lf% .6lf\n", max_v, min_v, mean_v, variance_v);
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