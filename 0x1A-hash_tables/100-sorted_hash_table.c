#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table with a given size
 * @size: size of the hash table
 * Return: the created hash table, or NULL if function fails
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	hash_node_t **array;
	unsigned long int i;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	table->array = array;
	table->size = size;
	table->head = NULL;
	table->tail = NULL;

	return (table);
}

/**
 * add_n_hash - adds a node at the beginning of a hash at a given index
 * @h: head of the hash linked list
 * @key: key of the hash
 * @value: value to store
 * Return: created node
 */

hash_node_t *add_n_hash(hash_node_t **h, const char *key, const char *value)
{
	hash_node_t *tmp;

	tmp = *h;

	while (tmp != NULL)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (tmp);
		}
		tmp = tmp->next;
	}

	tmp = malloc(sizeof(hash_node_t));

	if (tmp == NULL)
		return (NULL);

	tmp->key = strdup(key);
	tmp->value = strdup(value);
	tmp->next = *h;

	*h = tmp;

	return (tmp);
}

/**
 * add_i_hash - adds a node on the DLL of the hash table
 * @ht: pointer to the table
 * @new: new node to add
 * Return: no return
 */

void add_i_hash(hash_table_t *ht, hash_node_t *new)
{
	hash_node_t *tmp1, *tmp2;
	int ret;

	tmp1 = tmp2 = ht->head;

	while (tmp1 != NULL)
	{
		ret = strcmp(new->key, tmp1->key);
		if (ret == 0)
		{
			return;
		}
		else if (ret < 0)
		{
			new->prev = tmp1->prev;

			if (tmp1->prev)
				tmp1->prev->next = new;
			else
				ht->head = new;

			tmp1->prev = new;
			new->next = tmp1;

			return;
		}
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}

	new->prev = tmp2;
	new->next = NULL;

	if (ht->head)
		tmp2->next = new;
	else
		ht->head = new;

	ht->tail = new;
}

/**
 * hash_table_set - adds a hash (key, value)
 * @ht: pointer to the hash table
 * @key: key of the hash
 * @value: value to store
 * Return: 1 if successes, 0 if fails
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_index;
	hash_node_t *new;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	k_index = key_index((unsigned char *)key, ht->size);

	new = add_n_hash(&(ht->array[k_index]), key, value);

	if (new == NULL)
		return (0);

	add_i_hash(ht, new);

	return (1);
}

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: pointer to the hash table
 * @key: key of the hash
 * Return: value of the hash.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int k_index;
	hash_node_t *tmp;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	k_index = key_index((unsigned char *)key, ht->size);

	tmp = ht->array[k_index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * hash_table_print - prints the keys and values
 * @ht: pointer to the shash table
 * Return: no return
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp;
	char *sep;

	if (ht == NULL)
		return;

	printf("{");
	sep = "";

	tmp = ht->head;

	while (tmp != NULL)
	{
		printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
		sep = ", ";
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * hash_table_print_rev - prints the keys and values of the hash
 * table in reverse
 * @ht: pointer to the hash table
 * Return: no return
 */

void hash_table_print_rev(const hash_table_t *ht)
{
	hash_node_t *tmp;
	char *sep;

	if (ht == NULL)
		return;
	printf("{");
	sep = "";

	tmp = ht->stail;

	while (tmp != NULL)
	{
		printf("%s'%s': '%s'", sep, tmp->key, tmp->value);
		sep = ", ";
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * hash_table_delete - deletes a hash table
 * @ht: pointer to the hash table
 * Return: no return
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp1;
	hash_node_t *tmp2;

	if (ht == NULL)
	return;
	for (i = 0; i < ht->size; i++)
	{
		tmp1 = ht->array[i];
		while ((tmp2 = tmp1) != NULL)
		{
			tmp1 = tmp1->next;
			free(tmp2->key);
			free(tmp2->value);
			free(tmp2);
}
}
free(ht->array);
free(ht);
}
