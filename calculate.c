#include"add.c"
#include"convert.c"
#include"multiply.c"
#include"minus.c"
Data Add(Data left,Data right)
{ 

   Data result;
   char *result_below,*result_top_1,*result_top_2,*result_top;
   result_below=bigmuilty(left.denominator,right.denominator);
   result_top_1=bigmuilty(left.numberator,right.denominator);
   result_top_2=bigmuilty(left.denominator,right.numberator);
   AddBigNum(result_top_1,result_top_2,result_top=malloc(sizeof(char)*(strlen(result_top_1))+strlen(result_top_2))); 
   result.numberator=result_top;
   result.denominator=result_below;
   return result;
}

Data Minus(Data left,Data right)
{
   Data result;
   char *result_below,*result_top_1,*result_top_2,*result_top;
   result_below=bigmuilty(left.denominator,right.denominator);
   result_top_1=bigmuilty(left.numberator,right.denominator);
   result_top_2=bigmuilty(left.denominator,right.numberator);
   MinusBigNum(result_top_1,result_top_2,result_top=malloc(sizeof(char)*(strlen(result_top_1))+strlen(result_top_2))); 
   result.numberator=result_top;
   result.denominator=result_below;
   return result;
}

Data Multitply(Data left,Data right)
{
   Data result;
   char *result_below,*result_top;
   result_below=bigmuilty(left.denominator,right.denominator);
   result_top=bigmuilty(left.numberator,right.numberator);
   result.numberator=result_top;
   result.denominator=result_below;
   return result;
}
Data Divide(Data left,Data right)
{
   Data result;
   char *result_below,*result_top;
   result_below=bigmuilty(left.denominator,right.numberator);
   result_top=bigmuilty(left.numberator,right.denominator);
   result.numberator=result_top;
   result.denominator=result_below;
   return result;
}

Data calculate()
{
	Data current;
    Data left;	
	Data right;
	Data result;
    while (!is_empty_1())
	{
		push_2(pop_1());
	}
	while(!is_empty_2())
   {
	   current=pop_2();
       if (current.flag==1)
	   {
		   printf("get :%s\n",current.numberator);
	       push_1(current);
	   }
       else
       {

	       right=pop_1();
           left=pop_1();

	       switch(current.op)
		   {	
			   case('+'):
				   {
					   result=Add(left,right);
					   printf("%s\n",result.numberator);
					   push_1(result);
				        break;
				   }
			   case('-'):
				   {
				         result=Minus(left,right);
						 printf("%s\n",result.numberator);
						 push_1(result);
				  
						 break;
				   }
			   case('*'):
				   {
					     result=Multitply(left,right);
						 printf("??%s\n",result.numberator);
						 push_1(result);
				         break;
				   }
			   case('/'):
				   {
                         result=Divide(left,right);
						 printf("%s/%s\n",result.numberator,result.denominator);
						 push_1(result);
				         break;
				   }
		   }
	   }
   } 
}
int main()
{
	convert();
	calculate();
}
