#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void MinusBigNum( char* s1, char* s2, char* result )
{

    int len1 = strlen( s1 );  //被减数的长度
    int len2 = strlen( s2 );  //减数的长度
    int acc = 0, temp, i;     //acc为借位标记
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
        temp = s1[i]  - s2[i] -acc ;        
		if (temp<0)
		{
			acc=1;  //借位
			temp=temp+10;
		}
			else
			acc = 0;
            result[i] = temp +'0';        
	}
    if( i < len1 )       
    {
        for( ; i < len1; i++ )
        {
            temp = s1[i] - acc-'0';       
		    if (temp<0)
		    {
			    acc=1;  //借位
			    temp=temp+10;
		    }
            else
                acc = 0;
                result[i] = temp+'0' ;       
        }
    }

    if( acc == 1 )        
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
