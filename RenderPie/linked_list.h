#pragma once
#include "core_types.h"

typedef struct
{
	void * p_data;
	struct linked_list * p_prev, *p_next;
} linked_list;

void
linked_list_create ( linked_list *p_list );

void
linked_list_add ( linked_list * p_to_add, linked_list ** p_add_to );

void
linked_list_free ( linked_list * p_to_free );

void
linked_list_free_single ( linked_list * p_to_free );


DWORD32
linked_list_count ( linked_list * p_to_count );