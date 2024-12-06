#include "stdafx.h"

#include "config.h"

#ifndef IS_SET
#	define IS_SET(flag,bit)		((flag) & (bit))
#endif	// IS_SET

#ifndef SET_BIT
#	define SET_BIT(var,bit)		((var) |= (bit))
#endif	// SET_BIT

#ifndef REMOVE_BIT
#	define REMOVE_BIT(var,bit)		((var) &= ~(bit))
#endif	// REMOVE_BIT

#ifndef TOGGLE_BIT
#	define TOGGLE_BIT(var,bit)		((var) = (var) ^ (bit))
#endif	// TOGGLE_BIT

static int	s_log_mask = 0xffffffff;

void dev_log_add_level(int level)
{
	SET_BIT(s_log_mask, level);
}

void dev_log_del_level(int level)
{
	REMOVE_BIT(s_log_mask, level);
}

void dev_log_set_level(int mask)
{
	s_log_mask = mask;
}

