#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * bigmuilty(char*muiltied,char *muilty)//muiltied 为被乘数
{
   int len;
   int i=0;
   int j=0;
   int k=0;
   int tmp_result=0;
   int carry=0;
   char* result;
   int len1 = strlen(muiltied);
   int len2 = strlen(muilty);
   len=len1+len2; //两个数相乘他们的最大长度为乘数与被乘数的长度和
   result=(char*)calloc(len,1);//动态分配内存
   for(i=0;i<len2;i++)//用乘数的每一位去乘以被乘数
   {
     for(j=0;j<len1;j++)
     {
        tmp_result=muilty[len2-i-1]*muiltied[len1-j-1]-'0'*muiltied[len1-j-1]-'0'*muilty[len2-i-1]-'0'*'0';//得到零时结果
        result[j+i]+=tmp_result;//如果以0为起始标号，被乘数和乘数下标分别从右往左依次增加，则结果存放的位置为j+i
     }
     for(k=0;k<=j+i-1;k++)//整理结果，使每位的值在0-9之间
     {
                
        if(result[k]>9)
        {
           carry=result[k]/10;
           result[k]=result[k]%10;
           result[k+1]+=carry;
        }
     }
   }
   
   char *  result2=(char*)calloc(len,1);//动态分配内存
       int size =0;
   i=len-2;
   if(result[len-1]>0)
   {
	 result2[size++]=result[len-1]+'0';
   }
    while(i>=0)
   {
	  result2[size++]=result[i]+'0';
      i--;
   
   }
   free(result);
   result2[size]='\0';
   
   return result2;
}

