#include"stack.c"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"parse.c"
void convert();
int compare(char c1,char c2);

//test
//int main()
//{
//	convert();
//	Data test;
//	while (!is_empty_1())
//	push_2(pop_1());
//	while (!is_empty_2())
//	{
//		test =pop_2();
//		if(test.flag)
//		{	    printf("get :%s\n",test.numberator); 
//		    
	  // printf("%s/%s",test.numberator,test.denominator); 
//	}
//	else 
//	    printf("get :%c\n",test.op);
//	}
//}

/*比较运算级优先级*/
int compare(char c1,char c2)
{
	switch(c1)
	{
		case('+'):
			{
			if (c2=='-'||c2=='+'||c2=='(')
				return 1;
			else if (c2=='*'||'/')
				return 0;
			}

		case('-'):
			{
				if (c2=='-'||c2=='+'||c2=='(')
				    return 1;
			    else if (c2=='*'||'/')
				    return 0;
			}
		default:
			{ 
			    return 1;
			}
	}
}

void convert()
{
	char uinit[1000];
	 uinit[0]='\0';
	char c,c2;
	int size=0;
	Data operator;
	Data number;
	Data test;
	printf(">>>");
	while ((c=getchar())!='\n')
	{
		
		if((c>='0')&&(c<='9')||(c=='.')) 
		{
			uinit[size]=c;
			size++;
		}
		else if(c=='(')
		{
			//if(strlen(uinit)!=1)
			//{
			//	printf("2333");
			//	uinit[size]='\0';
			//	push_1(parse_number(uinit));
			//	size=0;
			//}
			operator.op=c;
			operator.flag=0;
			push_2(operator);
		}
		else if(c==')')
		{
			if(strlen(uinit)!=0)
			{
				uinit[size]='\0';
				push_1(parse_number(uinit));
				size=0;uinit[0]='\0';
			}
			char _X=top_2().op;
			while(_X!='(')
			{	
					push_1(pop_2());
					_X=top_2().op;
			}
			pop_2();
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/')
		{
			if(strlen(uinit)!=0)
			{
				uinit[size]='\0';
				number=parse_number(uinit);
				push_1(number);	
				test=number;
				size=0;uinit[0]='\0';
			}
			//如果栈２为空则直接入栈
			if (is_empty_2())
			{
			    operator.op=c;
				operator.flag=0;
			    push_2(operator);
			}
            //如果栈２不为空
			else
			{

				//比较栈２顶与当前运算符的优先级
				c2=top_2().op;
				if(compare(c,c2))
				{
			       //如果当前运算符优先级大于或等于栈顶运算符优先级,直接如栈２
					operator.op=c;
					operator.flag=0;
			        push_2(operator);
				}
				else
				{
					while(!is_empty_2()&&!compare(c,c2))
					{
						push_1(pop_2());
					    if (!is_empty_2())
						c2=top_2().op;
						else
							break;
					}
					operator.op=c;
					operator.flag=0;
			        push_2(operator);
				}
			}
		}
	}
	//最后一个数入栈
	if(strlen(uinit)!=0)
	{
		uinit[size]='\0';	
	    number=parse_number(uinit);
		number.flag=1;
		push_1(number);
	}
    while (!is_empty_2())
		push_1(pop_2());
}
