typedef struct my_data{
	char *numberator;  //分数的分子
	char *denominator; //分数的分母
	char op;           //操作符　运算符
	int flag;
}Data;
typedef struct my_stack{
    Data value;
	struct my_stack *next;
}Stack;
