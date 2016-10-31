#pragma once
#include "core_types.h"

typedef struct
{
	FLOAT x, y;
} core_vec2;

void core_vec2_set ( core_vec2 * p_vec, REAL x, REAL y );