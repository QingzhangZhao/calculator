#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse( char *s )        /*将字符串逆置*/
{
    int length;
    int i = 0;
    char temp;
    length = strlen( s );
    while( i < length - i - 1 )
    {
        temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
        i++;
    }
}

void MinusBigNum( char* s1, char* s2, char* result )
{

    int len1 = strlen( s1 );  //被减数的长度
    int len2 = strlen( s2 );  //减数的长度
    int acc = 0, temp, i;        /*acc为借位标记*/
    char * tmp;
    int flag= 0;
	int _bool=0;
    if (len1<len2)
	{
		int tp;
		tmp=s1;
		s1=s2;
		s2=tmp;
		tp=len1;
		len1=len2;
		len2=tp;
		flag=1;
	}

    if( s1 == NULL || s2 == NULL || result == NULL )
    {
        return;
    }
    reverse( s1 );
    reverse( s2 );
    for( i = 0; i < len1 && i < len2; i++ )
    {
        temp = s1[i]  - s2[i] -acc ;        /*计算每位的实际和*/
		if (temp<0)
		{
			acc=1;  //借位
			temp=temp+10;
		}
			else
			acc = 0;
            result[i] = temp +'0';        /*通过求余数来确定每位的最终值*/
    }
    if( i < len1 )        /*两个加数位数不同*/
    {
        for( ; i < len1; i++ )
        {
            temp = s1[i] - acc-'0';        /*依旧要考虑进位，比如9999 + 1的情况*/
		    if (temp<0)
		    {
			    acc=1;  //借位
			    temp=temp+10;
		    }
            else
                acc = 0;
                result[i] = temp+'0' ;        /*通过求余数来确定每位的最终值*/
        }
    }
    // if( i < len2 )
    //{
    //   for( ; i < len2; i++ )
    //  {
    //     temp = s2[i] -'0' - acc;
    //        result[i] = abs(temp) + '0';
    //        if( temp < 0 )
    //            acc = 1;
    //        else
    //            acc = 0;
    //    }
    // }

    if( acc == 1 )        /*考虑如:123 + 911 = 1034的情况，如果不增加这个条件会得到结果为034，进位被舍弃*/
	{
		if(len1==len2)
	    {
		    tmp=s1;
		    s1=s2;
		    s2=tmp;
	        MinusBigNum(s1,s2,result);    
	    } 
		result[i++]='-';
	}
	if(flag==1)
		result[i++]='-';
	result[i]='\0';
    
	reverse( result );
    
	int len=strlen(result);
	i=0;
	if (result[0]=='-')
	{i++;_bool=1;}
	while (result[i]=='0')
		i++;
	
	reverse(result);
	if (_bool==1)
	{
		result[len-i]='-';
		result[len-i+1]='\0';
	}
	else
		result[len-i]='\0';
	reverse(result);
}
/*测试一下*/
int main()
{
    char s1[] = "1000000000000000000000000000000000000000000000000000000000";
    char s2[] = "1";
	char * result=malloc(sizeof(char)*(strlen(s1)+strlen(s2)));	
    MinusBigNum( s1, s2,result);
    printf( "%s\n", result);
	free(result);
}


