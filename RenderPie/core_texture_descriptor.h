#pragma once
#include "core_types.h"
#include "core_string.h"


typedef struct
{
	DWORD id;
	core_string path;
} core_texture_descriptor;

void core_texture_descriptor_create ( core_texture_descriptor * p_texture );