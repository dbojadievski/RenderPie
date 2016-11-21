#pragma once
#include "core_types.h"

#pragma pack(push, 1)
typedef struct
{
	DWORD struct_size;

	LONG width;
	LONG height;

	WORD colour_planes;				// This field is required to be equal to 1.
	WORD bits_per_pixel;
	DWORD compression;
	DWORD size;						// This field represents the size of the image, expressed in bytes.

	LONG pixels_per_metre_x;		// This field represents the number of pixels per metre along the x-axis.
	LONG pixels_per_metre_y;		// This field represents the number of pilels per metre along the y-axis.

	DWORD colours_used;
	DWORD colours_important;
} core_bitmap_info_header;
#pragma pack(pop)