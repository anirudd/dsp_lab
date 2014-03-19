#include<stdio.h>
#include<math.h>
void dec2binary(int, int *);
int bin2dec(int *);
void main()
{
FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5;
fp=fopen("abc_cmprsd.wav","r");
fp1=fopen("abc_dcmprsd.wav","w");
fp2=fopen("tempo.txt","w");
fp3=fopen("tempo1.txt","w");
fseek(fp,0,SEEK_END);
int cntrl=0,l=0;
unsigned long long int len=ftell(fp);
printf("%lu",len);
fseek(fp,0,SEEK_SET);
unsigned int a;
char ch;
int rep[8],i=0,quo,j=0;
while(ftell(fp)<len)
{
while(ftell(fp)<44)
{
a=fgetc(fp);
fputc(a,fp1);
}



//printf("\n%lu",ftell(fp));
a=fgetc(fp);
dec2binary(a,rep);
if(cntrl==0)
{
for(i=0;i<7-l;i++)
{
if(rep[i]==0)
quo=48;
else
quo=49;
fputc(quo,fp2);
}
fputc(48,fp2);
for(i=7-l;i<8;i++)
{
if(rep[i]==0)
quo=48;
else
quo=49;
fputc(quo,fp2);
}
if(l==7)
{
cntrl=0;
l=0;
}
else
{
cntrl=1;
l++;
}
}
else
{
for(i=0;i<8;i++)
{
if(rep[i]==0)
quo=48;
else
quo=49;
fputc(quo,fp2);
}
cntrl=0;
}

}
printf("\n%lu",ftell(fp));
fclose(fp2);
fp5=fopen("tempo.txt","r");
fseek(fp5,0,SEEK_END);
unsigned long long int len1=ftell(fp5);
printf("\n%llu",len1);
int len2=len1%8;
len1=len1-len2;
fseek(fp5,0,SEEK_SET);
while(ftell(fp5)<len1)
{
a=fgetc(fp2);
fputc(a,fp3);
}
fclose(fp);
fclose(fp5);
fclose(fp3);
fp4=fopen("tempo1.txt","r");
fseek(fp4,0,SEEK_END);
unsigned long int len3=ftell(fp4);
fseek(fp4,0,SEEK_SET);
len3=len3/8;
for(i=0;i<len3;i++)
{
for(j=0;j<8;j++)
{
rep[j]=fgetc(fp4)-48;
}
a=bin2dec(rep);
fputc(a,fp1);
}
fclose(fp4);
fclose(fp1);
}

void dec2binary(int a, int *rep)
{
int i,k;
for(i=7;i>=0;i--)
{
k=a%2;
a=a/2;
rep[i]=k;
}
}

int bin2dec(int *rep)
{
int a=0;
int i=0;
for(i=0;i<8;i++)
{
a+=pow(2,i)*rep[(7-i)];
}
return a;
}
