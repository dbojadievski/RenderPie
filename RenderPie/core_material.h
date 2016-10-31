#pragma once
#include "core_types.h"
#include "core_string.h"
#include "colour.h"
#include "linked_list.h"

typedef struct
{
	DWORD			id;

	core_string		name;

	COLOUR_RGB		ambient;
	COLOUR_RGB		diffuse;

	COLOUR_RGB		specular;
	FLOAT shininess;

	DWORD			illumination;
	COLOUR_RGB		transmission_filter;
	COLOUR_RGB		color;
	FLOAT			dissolve			/* 1.0 - opaque, 0 - transparent */;

	linked_list		textures;
} core_material;

void core_material_create ( core_material * p_material );