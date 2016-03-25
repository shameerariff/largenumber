#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXVARIABLE 10
#define MAXSIZE 1024
#define MAXARRAYVARIABLE 10
#define MAXARRAYSIZE 1024


struct Number 
{
    char name[16];
    long long inte[1024];
    int length;
    int sign;
};
struct Number num[MAXVARIABLE];


struct Array 
{
    char name[16];
    long long inte[MAXARRAYSIZE][1024];
    int length;
    int sign;
};

struct Array anum[MAXARRAYVARIABLE];

//Print Number
int Print_Number(char variable[])
{
	int i,vid=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable,num[i].name)==0)
			vid=i;
	if(vid==-1)
	{
		return 0x00;
	}
	if(num[vid].sign==1)
		printf("-");
	for(i=0;i<=num[vid].length;i++)
		printf("%lld ",num[vid].inte[i]);
	return 0;
}

//Print Array
int Print_Array(char variable[],int id)
{
	int i,vid=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable,anum[i].name)==0)
			vid=i;
	if(vid==-1)
	{
		return 0x00;
	}
	if(anum[vid].sign==1)
		printf("-");
	for(i=0;i<=anum[vid].length;i++)
		printf("%lld ",anum[vid].inte[id][i]);
	return 0;
}

//Copy Array to Array
int Copy_Array(char variable1[],int id1,char variable2[],int id2)
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXARRAYVARIABLE;i++)
		if(strcmp(variable1,anum[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		i=0;
		while(strlen(anum[i].name)!=0)
		{
			i++;
		}
		vid1=i;
	}
	for(i=0;i<MAXARRAYVARIABLE;i++)
		if(strcmp(variable2,anum[i].name)==0)
			vid2=i;
	if(vid2!=-1)
	{
		for(i=0;i<=1024;i++)
			num[vid1].inte[i]=0x00;
		strcpy(anum[vid1].name,variable1);
		for(i=0;i<=num[vid2].length;i++)
		{
			anum[vid1].inte[id1][i]=0;
			anum[vid1].inte[id1][i]=anum[vid2].inte[id2][i];
		}
		anum[vid1].length=anum[vid2].length;
		anum[vid1].sign=anum[vid2].sign;
		return 0;
	}
	else
		return -1;
}

//Copy Array to Number
int Copy_toNumber(char variable1[],char variable2[],int id)
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable1,num[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		i=0;
		while(strlen(num[i].name)!=0)
		{
			i++;
		}
		vid1=i;
	}
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable2,anum[i].name)==0)
			vid2=i;
	if(vid2!=-1)
	{
		for(i=0;i<=1024;i++)
			num[vid1].inte[i]=0x00;
		strcpy(num[vid1].name,variable1);
		for(i=0;i<=anum[vid2].length;i++)
		{
			num[vid1].inte[i]=0;
			num[vid1].inte[i]=anum[vid2].inte[id][i];
		}
		num[vid1].length=anum[vid2].length;
		num[vid1].sign=anum[vid2].sign;
		return 0;
	}
	else
		return -1;
}

//Copy Number to Array
int Copy_toArray(char variable1[],int id,char variable2[])
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable1,anum[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		i=0;
		while(strlen(anum[i].name)!=0)
		{
			i++;
		}
		vid1=i;
	}
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable2,num[i].name)==0)
			vid2=i;
	if(vid2!=-1)
	{
		for(i=0;i<=1024;i++)
			anum[vid1].inte[id][i]=0x00;
		strcpy(anum[vid1].name,variable1);
		for(i=0;i<=num[vid2].length;i++)
		{
			anum[vid1].inte[id][i]=0;
			anum[vid1].inte[id][i]=num[vid2].inte[i];
		}
		anum[vid1].length=num[vid2].length;
		anum[vid1].sign=num[vid2].sign;
		return 0;
	}
	else
		return -1;
}


//Copy Number
int Copy_Number(char variable1[],char variable2[])
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable1,num[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		i=0;
		while(strlen(num[i].name)!=0)
		{
			i++;
		}
		vid1=i;
	}
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable2,num[i].name)==0)
			vid2=i;
	if(vid2!=-1)
	{
		for(i=0;i<=1024;i++)
			num[vid1].inte[i]=0x00;
		strcpy(num[vid1].name,variable1);
		for(i=0;i<=num[vid2].length;i++)
		{
			num[vid1].inte[i]=0;
			num[vid1].inte[i]=num[vid2].inte[i];
		}
		num[vid1].length=num[vid2].length;
		num[vid1].sign=num[vid2].sign;
		return 0;
	}
	else
		return -1;
}

//Store Number
int Store_Number(char sign,int * value, int size, char variable[])
{
	int i,j,vid=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable,num[i].name)==0)
			vid=i;
	if(vid==-1)
	{
		i=0;
		while(strlen(num[i].name)!=0)
		{
			i++;
		}
		vid=i;
	}
	strcpy(num[vid].name,variable);
	num[vid].inte[0]=0;
	int k=0;
	long long t1;
	num[vid].inte[(size/15)+1]=0;
	for(i=size-1,j=(size/15)+1;i>=0;i--,k++)
	{
		int t;
		t1=value[i];
		if((k%15)==0)
			j--;
		else
		{
			for(t=k%15;t>0;t--)
				t1*=10;
		}
		num[vid].inte[j]+=t1;
		t1=0;
		
	}
	
	if(sign==1)
		num[vid].sign= 1;
	else
		num[vid].sign= 0;
	num[vid].length=(size/15);
	return 0;
}

//Store Array
int Store_Array(char sign,int * value, int size, char variable[],int id)
{
	int i,j,vid=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable,anum[i].name)==0)
			vid=i;
	if(vid==-1)
	{
		i=0;
		while(strlen(anum[i].name)!=0)
		{
			i++;
		}
		vid=i;
	}
	strcpy(anum[vid].name,variable);
	anum[vid].inte[id][0]=0;
	int k=0;
	long long t1;
	anum[vid].inte[id][(size/15)+1]=0;
	for(i=size-1,j=(size/15)+1;i>=0;i--,k++)
	{
		int t;
		t1=value[i];
		if((k%15)==0)
			j--;
		else
		{
			for(t=k%15;t>0;t--)
				t1*=10;
		}
		anum[vid].inte[id][j]+=t1;
		t1=0;
		
	}
	
	if(sign==1)
		num[vid].sign= 1;
	else
		num[vid].sign= 0;
	num[vid].length=(size/15);
	return 0;
}


//Get Number
int Scan_Number(char variable[])
{
	char input[MAXSIZE];
	scanf("%s",input);
	int sign=0,value[MAXSIZE];
	int len=strlen(input);
	if(len>0)
	{
		int i,j;
		if(input[0]==45)
		{
			sign=1;
			i=1;
		}
		else
			i=0;
		for(j=0;i<len;i++)
		{
			if((input[i]>47)&&(input[i]<58))
				value[j]=input[i]-48;
			else
				return 0x00;
			j++;
		}
		if(sign==1)
			len--;
	}
	Store_Number(sign,&value[0], len, variable);
	return 0;
}

//Get Array
int Scan_Array(char variable[],int id)
{
	char input[MAXSIZE];
	scanf("%s",input);
	int sign=0,value[MAXSIZE];
	int len=strlen(input);
	if(len>0)
	{
		int i,j;
		if(input[0]==45)
		{
			sign=1;
			i=1;
		}
		else
			i=0;
		for(j=0;i<len;i++)
		{
			if((input[i]>47)&&(input[i]<58))
				value[j]=input[i]-48;
			else
				return 0x00;
			j++;
		}
		if(sign==1)
			len--;
	}
	Store_Array(sign,&value[0], len, variable, id);
	return 0;
}


//Logical operation
int Logical_opp(char variable1[],char variable2[])
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable1,num[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		return 0x00;
	}
	for(i=0;i<MAXVARIABLE;i++)
		if((strcmp(variable2,num[i].name))==0)
			vid2=i;
	if(vid2!=-1)
	{
		if(num[vid1].sign!=num[vid2].sign)
		{
			if(num[vid1].sign==0)
				return 1;
			else
				return 0;
		}
		else
		{
			int ga=0,gb=0,eab=0;
			for(i=0;i<=1024;i++)
			{
				if((num[vid1].inte[i]!=0x00)||(num[vid2].inte[i]!=0x00))
				{
					printf("\n%lld,%lld",num[vid1].inte[i],num[vid2].inte[i]);
					if(num[vid1].inte[i]>num[vid2].inte[i])
						ga++;
					else if(num[vid1].inte[i]==num[vid2].inte[i])
						eab++;
					else
						gb++;
				}
			}
			printf("\nga=%d, gb=%d ,eab=%d\n",ga,gb,eab);
			if((ga>gb)&&(ga>eab))
			{
				if(num[vid1].sign==1)
					return -1;
				else
					return 1;
			}
			else if((gb>ga)&&(gb>eab))
			{
				if(num[vid2].sign==1)
					return 1;
				else
					return -1;
			}
			else
				return 0;
		}
	}
	else
		return 0x00;
}

//Logical Arrays to number
int Logical_opp_Arrays_Numbers(char variable1[],int id,char variable2[])
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXARRAYVARIABLE;i++)
		if(strcmp(variable1,anum[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		return 0x00;
	}
	for(i=0;i<MAXVARIABLE;i++)
		if((strcmp(variable2,num[i].name))==0)
			vid2=i;
	if(vid2!=-1)
	{
		if(anum[vid1].sign!=num[vid2].sign)
		{
			if(anum[vid1].sign==0)
				return 1;
			else
				return 0;
		}
		else
		{
			int ga=0,gb=0,eab=0;
			for(i=0;i<=1024;i++)
			{
				if((anum[vid1].inte[id][i]!=0x00)||(num[vid2].inte[i]!=0x00))
				{
					printf("\n%lld,%lld",anum[vid1].inte[id][i],num[vid2].inte[i]);
					if(anum[vid1].inte[id][i]>num[vid2].inte[i])
						ga++;
					else if(anum[vid1].inte[id][i]==num[vid2].inte[i])
						eab++;
					else
						gb++;
				}
			}
			printf("\nga=%d, gb=%d ,eab=%d\n",ga,gb,eab);
			if((ga>gb)&&(ga>eab))
			{
				if(anum[vid1].sign==1)
					return -1;
				else
					return 1;
			}
			else if((gb>ga)&&(gb>eab))
			{
				if(num[vid2].sign==1)
					return 1;
				else
					return -1;
			}
			else
				return 0;
		}
	}
	else
		return 0x00;
}

//Logical operation Numbers to Arrays
int Logical_opp_Numbers_Arrays(char variable1[],char variable2[],int id)
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXVARIABLE;i++)
		if(strcmp(variable1,num[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		return 0x00;
	}
	for(i=0;i<MAXARRAYVARIABLE;i++)
		if((strcmp(variable2,anum[i].name))==0)
			vid2=i;
	if(vid2!=-1)
	{
		if(num[vid1].sign!=anum[vid2].sign)
		{
			if(num[vid1].sign==0)
				return 1;
			else
				return 0;
		}
		else
		{
			int ga=0,gb=0,eab=0;
			for(i=0;i<=1024;i++)
			{
				if((num[vid1].inte[i]!=0x00)||(anum[vid2].inte[id][i]!=0x00))
				{
					printf("\n%lld,%lld",num[vid1].inte[i],anum[vid2].inte[id][i]);
					if(num[vid1].inte[i]>anum[vid2].inte[id][i])
						ga++;
					else if(num[vid1].inte[i]==anum[vid2].inte[id][i])
						eab++;
					else
						gb++;
				}
			}
			printf("\nga=%d, gb=%d ,eab=%d\n",ga,gb,eab);
			if((ga>gb)&&(ga>eab))
			{
				if(num[vid1].sign==1)
					return -1;
				else
					return 1;
			}
			else if((gb>ga)&&(gb>eab))
			{
				if(anum[vid2].sign==1)
					return 1;
				else
					return -1;
			}
			else
				return 0;
		}
	}
	else
		return 0x00;
}


//Logical Arrays
int Logical_opp_Arrays(char variable1[],int id1,char variable2[],int id2)
{
	int i,vid1=-1,vid2=-1;
	for(i=0;i<MAXARRAYVARIABLE;i++)
		if(strcmp(variable1,anum[i].name)==0)
			vid1=i;
	if(vid1==-1)
	{
		return 0x00;
	}
	for(i=0;i<MAXARRAYVARIABLE;i++)
		if((strcmp(variable2,anum[i].name))==0)
			vid2=i;
	if(vid2!=-1)
	{
		if(anum[vid1].sign!=anum[vid2].sign)
		{
			if(num[vid1].sign==0)
				return 1;
			else
				return 0;
		}
		else
		{
			int ga=0,gb=0,eab=0;
			for(i=0;i<=1024;i++)
			{
				if((anum[vid1].inte[id1][i]!=0x00)||(anum[vid2].inte[id2][i]!=0x00))
				{
					printf("\n%lld,%lld",anum[vid1].inte[id1][i],anum[vid2].inte[id2][i]);
					if(anum[vid1].inte[id1][i]>anum[vid2].inte[id2][i])
						ga++;
					else if(anum[vid1].inte[id1][i]==anum[vid2].inte[id2][i])
						eab++;
					else
						gb++;
				}
			}
			printf("\nga=%d, gb=%d ,eab=%d\n",ga,gb,eab);
			if((ga>gb)&&(ga>eab))
			{
				if(anum[vid1].sign==1)
					return -1;
				else
					return 1;
			}
			else if((gb>ga)&&(gb>eab))
			{
				if(anum[vid2].sign==1)
					return 1;
				else
					return -1;
			}
			else
				return 0;
		}
	}
	else
		return 0x00;
}


//Main Function
int main()
{
	Scan_Number("a");
	Scan_Number("b");
	printf("\n A is ");
	Print_Number("a");
	printf("\n B is ");
	Print_Number("b");
	Copy_Number("c","a");
	Copy_Number("a","b");
	Copy_Number("b","c");
	printf("\n A is ");
	Print_Number("a");
	printf("\n B is ");
	Print_Number("b");
	int logical=Logical_opp("a","b");
	if(logical == 1)
		puts("A is greater");
	else if (logical == -1)
		puts("B is greater");
	else if(logical == 0)
		puts("A and B are equal");
	else
		puts("Invalid");
	printf("\n");
	return 0;
}
