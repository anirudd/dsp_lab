#include<stdio.h>
#include<math.h>

int big_endian(int );
int bin2dec(int *);

void main()
{
	FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5;
	fp=fopen("def.wav","r");
	fp1=fopen("def_cmprsd.wav","w");
	fp2=fopen("temp.txt","w");
	fp4=fopen("data1.txt","w");
	fp5=fopen("data2.txt","w");
	fseek(fp,0,SEEK_END);
	unsigned long long int len=ftell(fp);
	fseek(fp,0,SEEK_SET);
	unsigned int a;
	int sum=0;
	int step=5;
	int a1[8];
	int quo;
	while(ftell(fp)<44)
	{
		a=fgetc(fp);
		if((ftell(fp)>=4)&&(ftell(fp)<8))
		printf("\n%d",big_endian(a));
		fputc(a,fp1);
	}

	a=fgetc(fp);
	a=big_endian(a);
	sum=a;
	fputc(a,fp1);
	fputc(a,fp4);
	fputc(10,fp4);
	fputc(sum,fp5);
	fputc(10,fp5);

	while(ftell(fp)<len)
	{
		a=fgetc(fp);
		a=big_endian(a);
		fputc(a,fp4);
		fputc(10,fp4);
		if(sum<=a)
		{
			quo=49;
			sum=sum+step;
		}
		else
		{
			quo=48;
			sum=sum-step;
		}
		fputc(quo,fp2);
		fputc(sum,fp5);
		fputc(10,fp5);
	}
	unsigned long long int len1=ftell(fp2);
	int temp=len1%8;
	if(temp!=0)
	{
		temp=8-temp;
		while(temp>0)
		{
			fputc(48,fp2);
			temp--;
		}	
	}
	fclose(fp);
	fclose(fp2);
	fp3=fopen("temp.txt","r");
	
	fseek(fp3,0,SEEK_END);
	unsigned long long int len3=ftell(fp3);
	fseek(fp3,0,SEEK_SET);
	len3=len3/8;
	int i=0;
	while(len3>0)
	{
		for(i=0;i<8;i++)
		{
			a1[i]=(int)fgetc(fp3)-48;
		}
		len3--;
		a=bin2dec(a1);
		fputc(a,fp1);
	}
	fclose(fp1);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}

int bin2dec(int *a1)
{
	int a=0;
	int i=0;
	for(i=7;i>=0;i--)
	{
		a+=pow(2,i)*a1[(7-i)];
	}
	return a;
}

int big_endian(int a)
{
	int a1[8]={0,0,0,0,0,0,0,0};
	int i=0,b=0;
	for(i=0;i<8;i++)
	{
		a1[i]=a%2;
		a=a/2;
	}
	
	for(i=7;i>=0;i--)
	{
		b+=pow(2,i)*a1[(7-i)];
	}
	return b;
}
