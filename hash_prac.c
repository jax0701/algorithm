#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct entry_t
{
	int key;
	char *value;
	struct entry_t *next;
}entry_s;

typedef struct table_t
{
	int  size;
	entry_s **table; 	
}table_s;

table_s *create_htable(int size)
{
	table_s *htable = NULL;
	int i;

	htable = malloc( sizeof (table_s));
	htable->table = malloc (sizeof(entry_s *) * size);
	for (i=0; i<size; i++)
	{
		htable->table[i] = NULL;
	}

	htable->size = size;

	return htable;
}

entry_s *create_entry(int key, char *value)
{
	entry_s *new_entry;
	new_entry = malloc (sizeof(entry_s));
	new_entry->key = key;
	new_entry->value = strdup(value);
	new_entry->next = NULL;
	return new_entry;
}

int create_hashing_index(table_s *htable, int key)
{
	int bin;
	bin = key % htable->size;
	return bin;
}

entry_s *lookup_entry(table_s *htable, int key)
{
	entry_s *entry;
	entry_s *last;
	int bin;

	bin = create_hashing_index(htable, key);
	entry = htable->table[bin];
	while((entry != NULL) && (entry->key != key))
	{
		entry = entry->next;
	}

	if (entry == NULL)
		return NULL;
	else
		return entry;
}

void set_pair(table_s *htable, int key, char *value)
{
	entry_s *entry;
	entry_s *last;
	int bin;
	
	bin = create_hashing_index(htable, key);
	entry = lookup_entry(htable, key);
	
	if(entry)
		/* if there is an entry that has a same key, replace a value  */
		entry->value = strdup(value);
	else 
	{       entry = create_entry (key, value);
		entry->next = htable->table[bin];
	        htable->table[bin] = entry;	
	}
}

char *get_value(table_s *htable, int key)
{
	entry_s *entry;
	entry = lookup_entry(htable, key);
	
	if (entry)
		return entry->value;
	else
		return NULL;

}

void main()
{
	table_s *htable;
	
	htable = create_htable(10);
	set_pair(htable, 1, "jax");
	set_pair(htable, 5, "yulia");
	set_pair(htable, 3, "Misu");
	set_pair(htable, 7, "Batbaatar");
	set_pair(htable, 8, "Naraa");
	set_pair(htable, 9, "Khulan");

	printf("Hashed name is %s\n", get_value(htable,1));
	printf("Hashed name is %s\n", get_value(htable,3));
	printf("Hashed name is %s\n", get_value(htable,5));
	printf("Hashed name is %s\n", get_value(htable,9));
	printf("Hashed name is %s\n", get_value(htable,7));


}


























