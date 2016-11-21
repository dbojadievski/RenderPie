#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "core_types.h"
#include "core_bitmap_file_header.h"
#include "core_bitmap_info_header.h"
#include "core_bitmap_utils.h"

BYTE *
core_bitmap_utils_load ( LPSTR p_filename, core_bitmap_info_header * p_info_header )
{
	assert ( p_filename );
	assert ( p_info_header );

	FILE * p_file;
	core_bitmap_file_header file_header;
	BYTE * p_bitmap_buffer						= NULL;
	INT image_idx								= 0;
	BYTE temp_rgb;

	p_file										= fopen ( p_filename, "rb" );
	assert ( p_file );
	if ( p_file )
	{
		/* We can start by reading the bitmap header.*/
		fread ( &file_header, sizeof ( core_bitmap_file_header ), 1, p_file );
		assert ( file_header.type == 0x4D42 );
		if ( file_header.type == 0x4D42 )
		{
			fread ( p_info_header, sizeof ( core_bitmap_info_header ), 1, p_file );
			fseek ( p_file, file_header.offset, SEEK_SET );

			p_bitmap_buffer						= ( BYTE * ) malloc ( p_info_header->size );
			assert ( p_bitmap_buffer );

			if ( p_bitmap_buffer )
			{
				/* The default storage in the .BMP file is actually BGR, instead of RGB. We prefer working with RGB colours, so we need to reorder the bytes. */
				for ( image_idx = 0; image_idx < p_info_header->size; image_idx += 3 )
				{
					temp_rgb							= p_bitmap_buffer [ image_idx ];
					p_bitmap_buffer [ image_idx ]		= p_bitmap_buffer [ image_idx + 2 ];
					p_bitmap_buffer [ image_idx + 2 ]	= temp_rgb;
				}
			}
		}

		fclose ( p_file );
		return p_bitmap_buffer;
	}
}