#include <stdio.h>
#include <stdlib.h>
#include "Module.h"

#include "Support.h"

Module* CreateModule(int value_size)
{
	Module* module = NULL;

	module = (Module*)malloc(sizeof(Module));
	module->value = (double*)malloc(sizeof(double)*value_size);

	return module;
}

void DeleteModule(Module* module)
{
	if (module)
	{
		if (module->value)
		{
			free(module->value);
			module->value = NULL;
		}
		free(module);
		module = NULL;
	}
}

int Method(Module* module, int arg)
{
	return SupportFunction(arg);
}
