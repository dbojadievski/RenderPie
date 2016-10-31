#pragma once
#include "core_types.h"
#include "core_string.h"


typedef struct
{
	DWORD id;
	core_string path;
} core_texture;

void core_texture_create ( core_texture * p_texture );