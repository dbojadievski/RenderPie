#include "core_types.h"
#include "core_texture.h"

#include <assert.h>

void core_texture_create ( core_texture * p_texture )
{
	assert ( p_texture );
	static DWORD last_assigned_id							= 0;
	p_texture->id											= ++last_assigned_id;
	core_string_create ( &( p_texture->path ), 255 );
}