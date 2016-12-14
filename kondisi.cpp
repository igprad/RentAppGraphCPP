#include "header.h"

bool valid_input_string(string input)
{
	int i;
	for(i=0;i<20;i++)
	{
		if((input[i]>90||input[i]<65)&&(input[i]>122||input[i]<97))
			return false;
		
	}
	return true;
}