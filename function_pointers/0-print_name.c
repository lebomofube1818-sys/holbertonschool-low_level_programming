#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name using a function pointer
 * @name: pointer to the name string
 * @f: function pointer that takes a char * argument
 *
 * Description: This function checks if @name and @f are not NULL,
 * then calls the function pointed to by @f with @name as argument.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

