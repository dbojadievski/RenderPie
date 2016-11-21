#pragma once
#include "core_types.h"

#pragma pack(push, 1)
typedef struct
{
	WORD	type;						// If this field is nod 0x4D42, then this file is not really a .bitmap.
	DWORD	size;
	
	WORD	reserved_1;					// This field is required to be equal to 0.
	WORD	reserved_2;					// This field is required to be equal to 0.
	
	DWORD	offset;						// This field shows the offset to the bitmap data itself.
} core_bitmap_file_header;
#pragma pack(pop)