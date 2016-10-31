#include "core_types.h"
#include "core_vec2.h"

#include <assert.h>

void core_vec2_set ( core_vec2 * p_vec, REAL x, REAL y )
{
	assert ( p_vec );
	p_vec->x							= x;
	p_vec->y							= y;
}