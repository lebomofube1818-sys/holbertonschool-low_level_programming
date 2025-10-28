#include "hash_tables.h"

/**
 * _strdup - Duplicate a string (simple implementation)
 * @s: The string to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL on failure
 */
static char *_strdup(const char *s)
{
	char *dup;
	size_t len;
	size_t i;

	if (s == NULL)
		return (NULL);

	len = 0;
	while (s[len])
		len++;

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = s[i];

	return (dup);
}

/**
 * _create_node - Create and initialize a hash node with duplicated strings
 * @key: Key string
 * @value: Value string
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static hash_node_t *_create_node(const char *key, const char *value)
{
	hash_node_t *node;

	if (key == NULL || value == NULL)
		return (NULL);

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = _strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = _strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Adds or updates an element in the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key. Cannot be an empty string
 * @value: The value associated with the key. Must be duplicated.
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current, *new_node, *head;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	head = ht->array[index];

	/* If key exists, replace value */
	current = head;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			char *dup_value = _strdup(value);

			if (dup_value == NULL)
				return (0);
			free(current->value);
			current->value = dup_value;
			return (1);
		}
		current = current->next;
	}

	/* Key not found: create new node and insert at beginning */
	new_node = _create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = head;
	ht->array[index] = new_node;

	return (1);
}

