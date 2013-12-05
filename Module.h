/**
 * @file Module.h
 * ファイルの説明
 */

#ifndef MODULE_H_INCLUDE
#define MODULE_H_INCLUDE

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

typedef struct Module
{
	int member;
	double propety;
	double* value;
} Module;

/**
 * <Summary>
 *
 * <Detail>
 *
 * @param value_size size of member "value"
 * @return Module instance
 */
Module* CreateModule(int value_size);

/**
 * <Summary>
 *
 * <Detail>
 *
 * @param Module instance
 * @return 0 / Error: -1
 */
void DeleteModule(Module* module);

/**
 * <Summary>
 *
 * <Detail>
 *
 * @param Module instance
 * @param arg argument
 * @return value(Always return arg value.)
 */
int Method(Module* module, int arg);



#endif
