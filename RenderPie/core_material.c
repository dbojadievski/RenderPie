#include "core_types.h"
#include "vec3.h"
#include "colour.h"
#include "core_string.h"
#include "linked_list.h"
#include "core_material.h"

void
core_material_create ( core_material * p_material )
{
	static DWORD last_assigned_mat		= 0;

	core_vec3_set ( &( p_material->ambient ), 0, 0, 0 );
	core_vec3_set ( &( p_material->diffuse ), 0, 0, 0 );
	core_vec3_set ( &( p_material->specular ), 0, 0, 0 );
	core_vec3_set ( &( p_material->transmission_filter ), 0, 0, 0 );

	p_material->dissolve				= 1.0f;
	p_material->illumination			= 0;
	p_material->shininess				= 0;

	p_material->textures.p_data			= 0;
	p_material->textures.p_next			= 0;
	p_material->textures.p_prev			= 0;

	p_material->id						= ++last_assigned_mat;
}