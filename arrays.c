#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <memory.h>

#define MEMORY_ELEMENT_INC 10

struct array_list
{
    char* ptr;
    int count;
    int ocount;
    size_t element_size;
};

void init_array_list(struct array_list* list, size_t element_size)
{
    list->ptr = (char*) malloc(element_size * MEMORY_ELEMENT_INC);
    list->count = MEMORY_ELEMENT_INC;
    list->ocount = 0;
    list->element_size = element_size;
}

int al_count(struct array_list* list)
{
    return list->ocount;
}

void al_append(struct array_list* list, void* ptr)
{

    if (list->ocount >= list->count)
    {
        // we must resize memory
        list->ptr = (char*) realloc(list->ptr, ((list->count + MEMORY_ELEMENT_INC ) * list->element_size));
        // adjust the count 
        list->count += MEMORY_ELEMENT_INC;
    }
    memcpy(&list->ptr[list->ocount * list->element_size], ptr, list->element_size);
    list->ocount += 1;
}

bool al_get(struct array_list* list, int index_, void* out)
{
    if (index_ >= list->ocount)
    {
        // out of bounds
        return false;
    }

    memcpy(out, &list->ptr[index_*list->element_size], list->element_size);
    return true;
}

bool al_remove(struct array_list* list, int index_)
{
    if (index_ >= list->ocount)
    {
        // out of bounds
        return false;
    }

    for (int i = index_; i < list->ocount; i++)
    {
        memcpy(&list->ptr[i * list->element_size], &list->ptr[(i + 1) * list->element_size], list->element_size);
    }

    list->ocount -= 1;
    return true;
}

void al_destruct(struct array_list* list)
{
    free(list->ptr);
    list->ptr = NULL;
}

int main( int argc, char* argv )
{
    
    struct array_list list;
    init_array_list(&list, sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        int data = i*i;
        al_append(&list, &data);
    }
    
    al_remove(&list, 3);

    for (int i = 0; i < 10; i++)
    {
        
        int result = 0;
        al_get(&list, i, &result);

        printf(" %i. %i\n", i, result);

    }

    al_destruct(&list);
    return 0;
}
