#pragma once
#include "core_types.h"
#include <stdlib.h>
#include <assert.h>

/*
* A fast C string library that does nothing behind your back.
* Author: Bojadjievski Dino  (@bojadjievski)
*/
typedef struct core_string
{
	UINT16 allocated;
	UINT16 used;
	LPSTR p_content;
} core_string;


void
core_string_create ( core_string * p_string, UINT16 size );

void
core_string_size ( core_string * p_string, CONST UINT16 size );

void
core_string_resize ( core_string * p_string, CONST UINT16 size );

void
core_string_destroy ( core_string * p_string );

void
core_string_set ( core_string * p_string, LPSTR p_c_str );

void
core_string_set_size ( core_string * p_string, LPSTR p_c_str, UINT16 length );

/* Note: this function does not empty out the string buffer. */
void
core_string_empty ( core_string * p_string );

void
core_string_zero ( core_string * p_string );

void
core_string_cat ( core_string * p_dest, core_string * p_source );

INT32
core_string_last_index_of ( core_string * p_str, const CHAR needle );