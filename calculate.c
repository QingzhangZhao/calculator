#include"add.c"
#include"convert.c"
Data calculate()
{
	Data current;
    Data left;	
	Data right;
	Data rst;
    while (!is_empty_1())
	{
		push_2(pop_1());
	}
	while(!is_empty_2())
   {

	   current=pop_2();
       if (current.flag==1)
	       push_1(current);
       else
       {
	       left=pop_1();
           right=pop_1();

	       switch(current.op)
		   {	
			   case('+'):
				   {
					   char * result;
					   AddBigNum(left.numberator,right.numberator,result=malloc(sizeof(char)*(strlen(left.numberator)+strlen(right.numberator))));
				       printf("%s",result);
					   rst.numberator=result; //bug
					   push_1(rst);
				        break;
				   }
			   case('-'):

				   break;
			   case('*'):

				   break;
			   case('/'):

				   break;
		   }
	   }
   }
   
}
int main()
{
	convert();
	calculate();
}
