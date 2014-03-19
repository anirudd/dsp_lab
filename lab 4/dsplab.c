#include<stdio.h>
#include<math.h>
void dec2binary(int, int *);
int bin2dec(int *);
void main()
{
char ch;
unsigned int a;
int rep[8];
FILE *fp,*fp1,*fp2,*fp3;
fp=fopen("abc.wav","r");
fp1=fopen("abc_cmprsd.wav","w");
fp2=fopen("temper.txt","w");
fseek(fp,0,SEEK_END);
unsigned long int len=0;
len=ftell(fp);
printf("%lu\n",len);
fseek(fp,0,SEEK_SET);
int i=0,quo;
while(ftell(fp)<len)
{
while(ftell(fp)<44)
{
a=fgetc(fp);
fputc(a,fp1);
if((ftell(fp)==35)||(ftell(fp)==36))
{
//printf("%d\n",a);
}
}
a=fgetc(fp);
dec2binary(a,rep);
for(i=0;i<7;i++)
{
if(rep[i]==0)
quo=48;
else
quo=49;
fputc(quo,fp2);
}


a=fgetc(fp);
dec2binary(a,rep);
for(i=0;i<8;i++)
{
if(rep[i]==0)
quo=48;
else
quo=49;
fputc(quo,fp2);
}



}
unsigned long len2=ftell(fp2);
int yy=len2%8;
if(yy!=0)
{
yy=8-yy;
for(i=0;i<yy;i++)
{
fputc(48,fp2);
}
}
fclose(fp);
fclose(fp2);
fp3=fopen("temper.txt","r");
fseek(fp3,0,SEEK_END);
unsigned long int len1=ftell(fp3);
fseek(fp3,0,SEEK_SET);
len1=len1/8;
int j=0;
for(i=0;i<len1;i++)
{
for(j=0;j<8;j++)
{
rep[j]=fgetc(fp3)-48;
}
a=bin2dec(rep);
fputc(a,fp1);
}
fclose(fp3);
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
