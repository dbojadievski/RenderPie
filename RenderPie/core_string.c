#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "core_types.h"
#include "core_string.h"

void
core_string_create ( core_string * p_string, UINT16 size )
{
	assert ( p_string );
	p_string->p_content						= ( LPSTR ) malloc ( size * sizeof ( CHAR ) );
	p_string->allocated						= size;
}

void
core_string_size ( core_string * p_string, CONST UINT16 size )
{
	assert ( p_string );

	free ( p_string->p_content );
	p_string->p_content = ( LPSTR ) malloc ( size * sizeof ( CHAR ) );
	assert ( p_string->p_content );
	p_string->used = 0;
	p_string->allocated = size;

	assert ( p_string->p_content );
}

void
core_string_resize ( core_string * p_string, CONST UINT16 size )
{
	assert ( p_string );

	LPSTR buffer = ( LPSTR ) malloc ( p_string->used * sizeof ( CHAR ) );
	assert ( buffer );
	strncpy ( buffer, p_string->p_content, p_string->allocated );

	free ( p_string->p_content );
	p_string->p_content = ( LPSTR ) malloc ( size * sizeof ( CHAR ) );
	assert ( p_string->p_content );
	strncpy ( p_string->p_content, buffer, p_string->allocated );

	p_string->allocated = size;

	free ( buffer );
	assert ( p_string->allocated );
}

void
core_string_destroy ( core_string * p_string )
{
	p_string->allocated = 0;
	p_string->used = 0;

	free ( p_string->p_content );
	p_string->p_content = NULL;
}

void
core_string_set ( core_string * p_string, LPSTR p_c_str )
{
	assert ( p_string );
	assert ( p_string->p_content );
	assert ( p_c_str );

	char * p_char = p_c_str;
	DWORD offset = 0;
	while ( *p_char )
		p_string->p_content [ offset++ ] = *( p_char++ );
	p_string->used = offset;
}

void
core_string_set_size ( core_string * p_string, LPSTR p_c_str, UINT16 length )
{
	assert ( p_string );
	assert ( p_string->p_content );
	assert ( p_string->allocated >= length );
	assert ( p_c_str );

	INT i;
	for ( i = 0; i < length; i++ )
		p_string->p_content [ i ] = p_c_str [ i ];
}

void
core_string_empty ( core_string * p_string )
{
	assert ( p_string );
	assert ( p_string->p_content );
	p_string->used = 0;
}

void
core_string_zero ( core_string * p_string )
{
	assert ( p_string );
	assert ( p_string->p_content );

	UINT16 i;
	for ( i = 0; i < p_string->allocated; i++ )
		p_string->p_content [ i ] = 0;
}

void
core_string_cat ( core_string * p_dest, core_string * p_source )
{
	assert ( p_dest );
	assert ( p_dest->p_content );

	assert ( p_source );
	assert ( p_source->p_content );

	assert ( p_dest->allocated >= ( p_dest->used + p_source->used ) );
	UINT16 final_size = ( p_dest->used + p_source->used );
	UINT16 i, j;
	for ( i = p_dest->used, j = 0; i < final_size; i++, j++ )
		p_dest->p_content [ i ] = p_source->p_content [ j ];
	p_dest->used = final_size;
}

INT32
core_string_last_index_of ( core_string * p_str, const CHAR needle )
{
	assert ( p_str );
	INT32 last_index_of = -1;

	for ( INT32 curr_pos = p_str->used - 1; curr_pos >= 0; curr_pos = curr_pos - sizeof ( CHAR ) )
		if ( p_str->p_content [ curr_pos ] == needle )
		{
			last_index_of = curr_pos;
			break;
		}

	return last_index_of;
}