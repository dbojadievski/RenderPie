#include "core_types.h"
#include "core_vec2.h"
#include "vec3.h"
#include "core_vertex.h"

#include <assert.h>

void
core_vertex_basic_create ( core_vertex_basic * p_vertex )
{
	assert ( p_vertex );
	core_vec3_set ( &( p_vertex->position ), 0, 0, 0 );
	core_vec3_set ( &( p_vertex->normal ), 0, 0, 0 );
}

void
core_vertex_textured_create ( core_vertex_textured * p_vertex )
{
	assert ( p_vertex );
	core_vec3_set ( &( p_vertex->position ), 0, 0, 0 );
	core_vec3_set ( &( p_vertex->normal ), 0, 0, 0 );
	core_vec2_set ( &( p_vertex->tex_coords ), 0, 0 );
}

void 
core_vertex_triple_tex_create ( core_vertex_triple_tex * p_vertex )
{
	assert ( p_vertex );
	core_vec3_set ( &( p_vertex->position ), 0, 0, 0 );
	core_vec3_set ( &( p_vertex->normal ), 0, 0, 0 );
	core_vec2_set ( &( p_vertex->tex_coords_1 ), 0, 0 );
	core_vec2_set ( &( p_vertex->tex_coords_1 ), 0, 0 );
	core_vec2_set ( &( p_vertex->tex_coords_1 ), 0, 0 );


}