#include <stdio.h>

#include <mcheck.h>

#include "../Module.h"
#include "../Support.h"

int main()
{
	mtrace();

	Module* module = NULL;

	module = CreateModule(2);

#ifdef _DEBUG
	printf("This is DEBUG message defined '_DEBUG' env value.\n");
#endif

	printf("Method result : %d\n", Method(module, 5));

	DeleteModule(module);

	muntrace();
}
