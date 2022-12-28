#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct list_element
{
    void* data;
    struct list_element* next;
};

struct list_element* get_last_le(struct list_element* head) {
    struct list_element* lastE = head;
    while (lastE != NULL)
    {
        if (lastE->next == NULL)
            break;
        lastE = lastE->next;
    }
    return lastE;
}

void init_list_element(struct list_element* elm) {
    elm->data = NULL;
    elm->next = NULL;
}

void add_list_element(struct list_element* head_, void* data) {
    if( head_->data == NULL )
    {
        head_->data = data;
        return ;
    }
    else
    {
        struct list_element* last_element = get_last_le(head_);
        struct list_element* elm = (struct list_element*) malloc(sizeof(struct list_element ));
        init_list_element(elm);
        elm->data = data;
        last_element->next = elm;
    }
}

void destruct_list(struct list_element* head_)
{
    struct list_element* cur = head_->next;
    while (cur != NULL)
    {
        struct list_element* next = cur->next;
        free(cur);
        cur = next;
    }
}

int main( int argc, char** argv ) {

    struct list_element head;

    // initializing list elements !
    init_list_element(&head);

    // add the first element to the list
    add_list_element(&head, "Hello, World!");

    // add the second element to the list
    add_list_element(&head, "This is the second Element!");

    // add the third element to the list
    add_list_element(&head, "This is the third Element!");

    struct list_element* cur = &head;

    while (cur != NULL)
    {
        printf("%s\n", (const char*)cur->data);
        cur = cur->next;
    }

    // clean up the memory of the list
    destruct_list(&head);
    return 0;
}
