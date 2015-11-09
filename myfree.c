#include<stdlib.h>
#include<stab.h>
void my_free(Data * data)
{
	free(data->numberator);
	free(data->denominator);
	free(data);
}
