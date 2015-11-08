#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * bigmuilty(char*muiltied,char *muilty)//muiltied 为被乘数，len1为其长。muilty为乘数，len2为其长
{
   printf("ok!");
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
   for(i=0;i<len1;i++)
   {
       muiltied[i]=muiltied[i]-'0';
   }
   for(i=0;i<len2;i++)
   {
      muilty[i]=muilty[i]-'0';
   }
   for(i=0;i<len2;i++)//用乘数的每一位去乘以被乘数
   {
     for(j=0;j<len1;j++)
     {
        tmp_result=muilty[len2-i-1]*muiltied[len1-j-1];//得到零时结果
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
   
   
//   i=len-2;
//   printf("\nresult : ");
//   if(result[len-1]>0)
//   {
//     printf("%c",result[len-1]+'0');
//   }
//    while(i>=0)
//   {
//      printf("%c",result[i]+'0');
//      i--;
//   }

   return result;
}
int main()
{
   int i=0;
   int num='0';
   char muiltied[BUFSIZ];//被乘数存放位置
   char muilty[BUFSIZ];
   
   char s1[]="222";
   char s2[]="222";
   bigmuilty(s1,s2);
  // free(result);
   return 0;
}
