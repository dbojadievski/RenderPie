#include "core_types.h"
#include "vec3.h"
#include <assert.h>

void
core_vec3_set ( core_vec3 * p_vec, FLOAT x, FLOAT y, FLOAT z )
{
	assert ( p_vec );
	p_vec->x						= x;
	p_vec->y						= y;
	p_vec->z						= z;
}