#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table
 * @ht: pointer to the hash table to delete
 *
 * Description: Frees all nodes and the array, then the hash table itself.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	hash_node_t *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			tmp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = tmp;
		}
	}

	free(ht->array);
	free(ht);
}

