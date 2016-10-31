#pragma once
#include "core_types.h"
#include "vec3.h"
#include "core_vec2.h"

typedef struct
{
	core_vec3 position;
	core_vec3 normal;
	core_vec2 tex_coords;
} core_vertex_textured;


typedef struct
{
	core_vec3 position;
	core_vec3 normal;
} core_vertex_basic;

typedef struct
{
	core_vec3 position;
	core_vec3 normal;

	core_vec2 tex_coords_1;
	core_vec2 tex_coords_2;
	core_vec2 tex_coords_3;
} core_vertex_triple_tex;

void core_vertex_basic_create ( core_vertex_basic * p_vertex );
void core_vertex_textured_create ( core_vertex_textured * p_vertex );
void core_vertex_triple_tex_create ( core_vertex_triple_tex * p_vertex );