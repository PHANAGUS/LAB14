#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[])
{
    double sum = 0, sum2 = 0, sum3 = 0, sumlog = 0;
    double max = a[0], min = a[0], mean, sd, gm, hm;

    for(int i=0 ; i<n ; i++)
    {
        sum += a[i];
    }
    mean = sum/n;
    b[0] = mean;

    for(int i=0 ; i<n ;i++)
    {
        sum2 += pow((a[i]-mean),2);
    }
    sd = sqrt(sum2/n);
    b[1] = sd;

    for(int i=0 ; i<n ; i++)
    {
        sumlog += log10(a[i]);
    }
    gm = pow(10,sumlog/n);
    b[2] = gm;

    for(int i=0 ; i<n ; i++)
    {
        sum3 += (1/a[i]);
    }
    hm = n/sum3;
    b[3] = hm;

    for(int i=1 ; i<n ; i++)
    {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    b[4] = max;
    b[5] = min;
}