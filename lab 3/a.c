#include<stdio.h>
#include<math.h>
void dec2binary(int, int *);
int bin2dec(char *a);
void main()
{
FILE *fp,*fp1,*fp2, *fp4,*fp5;
fp=fopen("ai.txt","r");
fp1=fopen("8bit.txt","w");
fp2=fopen("compressed.txt","w");
fp4=fopen("7bit.txt","w");
fp5=fopen("temp.txt","w");
char a;
unsigned int b;
int rep[8];
int i,ii=0;
char in[3];
while((a=fgetc(fp))!=EOF)
{
ii=0;
while(a!='\n')
{
in[ii]=a;
ii++;
a=fgetc(fp);
}
ii--;
b=0;
for(i=0;i<=ii;i++)
{
int l=ii-i;
int ll=(int)in[i]-48;
b+=pow(10,l)*ll;
}


dec2binary(b,rep);

int quo,quo1;
for(i=0;i<8;i++)
{
if(rep[i]==0)
quo=48;
else
quo=49;
fputc(quo,fp1);
if(i!=7)
{
fputc(quo,fp4);
fputc(quo,fp5);
}

}


}
fseek(fp5,0,SEEK_END);
int sz=ftell(fp5);
if((sz%8)!=0)
{
int yy=sz%8;
char p='0';
int pp=(int)p;
for(i=1;i<=yy;i++)
{
fputc(pp,fp5);
}
}

fclose(fp);
fclose(fp1);
fclose(fp4);
fclose(fp5);

FILE *fp3;
fp3=fopen("temp.txt","r");
fseek(fp3,0,SEEK_END);
int sz1=ftell(fp3);
sz1=sz1/8;
fseek(fp3,0,SEEK_SET);
int qq;
char ip[8];
for(i=0;i<sz1;i++)
{
int qq=0;
for(qq=0;qq<8;qq++)
{
ip[qq]=fgetc(fp3);
}
int res=bin2dec(ip);
fputc(res,fp2);
}

fclose(fp2);
fclose(fp3);
}

void dec2binary(int a, int *rep)
{
int i=0,k,temp;
for(i=7;i>=0;i--)
{
temp=a%2;
a=a/2;
rep[i]=temp;
}
}

int bin2dec(char *a)
{
int sum=0,i;
for(i=0;i<8;i++)
{
int z=(int)a[i]-48;
sum=sum+pow(2,i)*z;
}
return sum;
}
