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

void AddBigNum( char* s1, char* s2, char* result )
{
    int len1 = strlen( s1 );
    int len2 = strlen( s2 );
    int acc = 0, temp, i;        /*acc为进位标记*/
    if( s1 == NULL || s2 == NULL || result == NULL )
    {
        return;
    }
    reverse( s1 );
    reverse( s2 );
    for( i = 0; i < len1 && i < len2; i++ )
    {
        temp = s1[i] - '0' + s2[i] - '0' + acc;        /*计算每位的实际和*/
        result[i] = temp % 10 + '0';        /*通过求余数来确定每位的最终值*/
        if( temp >= 10 )        /*通过这个if..else..条件来判断是否有进位，并设置进位值*/
            acc = 1;
        else
            acc = 0;
    }
    if( i < len1 )        /*两个加数位数不同*/
    {
        for( ; i < len1; i++ )
        {
            temp = s1[i] - '0' + acc;        /*依旧要考虑进位，比如9999 + 1的情况*/
            result[i] = temp % 10 + '0';
            if( temp >= 10 )        
                acc = 1;
            else
                acc = 0;
        }
    }
    if( i < len2 )
    {
        for( ; i < len2; i++ )
        {
            temp = s2[i] - '0' + acc;
            result[i] = temp % 10 + '0';
            if( temp >= 10 )
                acc = 1;
            else
                acc = 0;
        }
    }

    if( acc == 1 )        /*考虑如:123 + 911 = 1034的情况，如果不增加这个条件会得到结果为034，进位被舍弃*/

        result[i++] ='1';

    result[i] = '\0';
    reverse( result );
}

//int main()
//{
//    char s1[] = "111111111111111111111111";
//    char s2[] = "111111111111111111111111";
//	char * result=malloc(sizeof(char)*(strlen(s1)+strlen(s2)));	
 //   AddBigNum( s1, s2,result);
  //  printf( "%s\n", result);
//	free(result);
//}
//

