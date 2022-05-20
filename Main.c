/* Program implementing a function returning either int or string based on the input argument */

#include <stdio.h>
#include <stdlib.h>

// Declaring struct containing enum storing type of the return value, and void pointer to store the return value
struct ret
{
	enum {I, S} type;
	void* ret;
};

// Function of the type struct ret to return the type of the return value along with the return value
struct ret foo (char i)
{
	struct ret r;

	if (i == 's')
	{
		r.type = S;
		r.ret = malloc(6 * sizeof(char));
		sprintf((char*)r.ret, "hello");
	}
	else if (i == 'i')
	{
		r.type = I;
		r.ret = malloc(sizeof(int));
		*((int*)r.ret) = 69;
	}

	return r;
}

int main()
{
	struct ret r = foo('i');

	if (r.type == S)
		printf("%s", (char*)r.ret);
	else if (r.type == I)
		printf("%d", *((int*)r.ret));
}
