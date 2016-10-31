#include "linked_list.h"
#include "core_types.h"
#include "core_string.h"

#include <assert.h>

void
linked_list_create ( linked_list *p_list )
{
	assert ( p_list );
	p_list->p_prev = NULL;
	p_list->p_next = NULL;
	p_list->p_data = NULL;
}

void
linked_list_add ( linked_list * p_to_add, linked_list ** p_add_to )
{
	assert ( p_to_add );
	assert ( p_add_to );

	if ( !( *p_add_to ) )
		*p_add_to = p_to_add;
	else
	{
		if ( ( *p_add_to )->p_next )
		{
			linked_list * p_next = ( *p_add_to )->p_next;
			p_next->p_prev = p_to_add;
			p_to_add->p_next = p_next;
			p_to_add->p_prev = *p_add_to;
			( *p_add_to )->p_next = p_to_add;
		}
		else
		{
			( *p_add_to )->p_next = p_to_add;
			( *p_add_to )->p_next = p_to_add;
			p_to_add->p_prev = ( *p_add_to );
		}
	}
}

void
linked_list_free ( linked_list * p_to_free )
{
	assert ( p_to_free );
	while ( p_to_free )
	{
		linked_list * p_node = p_to_free;
		p_to_free = p_to_free->p_next;
		free ( p_node->p_data );
		free ( p_node );
	}
}

void
linked_list_free_single ( linked_list * p_to_free )
{
	assert ( p_to_free );
	free ( p_to_free->p_data );
	free ( p_to_free );
}

DWORD32
linked_list_count ( linked_list * p_to_count )
{
	DWORD count = 0;
	while ( p_to_count )
	{
		++count;
		p_to_count = p_to_count->p_next;
	}

	return count;
}