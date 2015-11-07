//#include"stack.h"
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//得到有理数
Data   parse_number(char *number)
{
	Data data;
	int point=0;
	int size = strlen(number);


	int i;
	//得到小数点的位置
	for (i=0;i<=size;i++)
	{
		if(number[i]=='.')
		{	point=i;
		}
	}
		
	int _10=size-point-2;
	int de=1;
	//根据小数点后面有多少数除以１０的几次方
	for (i=0;i<=_10;i++)
	{
		de*=10;
	}

	//如果没有小数点
	if(point==0)
	{
		
        data.numberator=malloc(sizeof(char)*size+3);
		memcpy(data.numberator,number,size+1);
		data.denominator="1";
	}
	//如果有小数点
	else
	{
        data.numberator=malloc(sizeof(char)*size);
		char * temp;
		temp=malloc(sizeof(char)*size+1);
		for (i=0;i<size;i++)
		{   
			if (i<point)
			    temp[i]=number[i];
			if (i>=point)
				temp[i]=number[i+1];
		}
		memcpy(data.numberator,temp,strlen(temp)+1);
		data.denominator=malloc(sizeof(char)*_10);
		//	itoa(de,data.denominator,10); //标准库中没有该函数
              
		sprintf(data.denominator,"%d",de);
	}
	data.flag=1;
	return data;
}


//int main()
//{
//  Data a = parse_number("123.456");
//  printf("%s/%s",a.numberator,a.denominator);
//}
