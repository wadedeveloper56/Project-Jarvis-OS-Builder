#include "pch.h"
#include "orllevel.h"
#include "orlhash.h"

#define _HashAlloc( a, b ) a->funcs->alloc( b )
#define _HashFree( a, b ) a->funcs->free( b )
#define _HashCompare( a, b, c ) a->compare( b, c )

void ORLHashTableFree(orl_hash_table hash_table)
{
    int                         loop;
    orl_hash_struct* hash_ptr;
    orl_hash_struct* last_hash_ptr;
    orl_hash_data_struct* data_ptr;
    orl_hash_data_struct* last_data_ptr;

    for (loop = 0; loop < (int)hash_table->size; loop++)
    {
        hash_ptr = hash_table->table[loop];
        while (hash_ptr != NULL) {
            data_ptr = hash_ptr->data_struct;
            while (data_ptr != NULL) {
                last_data_ptr = data_ptr;
                data_ptr = data_ptr->next;
                _HashFree(hash_table, last_data_ptr);
            }
            last_hash_ptr = hash_ptr;
            hash_ptr = hash_ptr->next;
            _HashFree(hash_table, last_hash_ptr);
        }
    }
    _HashFree(hash_table, hash_table->table);
    _HashFree(hash_table, hash_table);
}
