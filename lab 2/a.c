#include<stdio.h>
#include<math.h>
#define pi 3.14
const int freq=8000;
const int freq1=24000;
void main()
{
float ts=1/freq1,t;
float T=1/freq;
int n=T/ts;
float a[n];
for(t=0;t<T;t=t+ts)
{
a[i]=sin(2*pi*freq*t);
i++;
prinrf("\n%f",a[i]);
}

}