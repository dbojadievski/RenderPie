#pragma once
#include "core_types.h"
typedef struct
{
	FLOAT x, y, z;
} core_vec3;

void
core_vec3_set ( core_vec3 * p_vec, FLOAT x, FLOAT y, FLOAT z );