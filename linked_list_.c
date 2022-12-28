// Implementing A Linked List With The Value being the List Element

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

struct list_element {
	struct list_element* next;
};

struct animal {
	struct list_element element;
	const char* name;
	int age;
};

void init_list_element(struct list_element* element)
{
	element->next = NULL;
}

struct list_element* get_last_le(struct list_element* head)
{
	struct list_element* current_ = head;
	while (current_ != NULL)
	{
		if (current_->next == NULL)
			break;

		current_ = current_->next;
	}

	return current_;
}

void add_list_element(struct list_element* head, struct list_element* value)
{
	struct list_element* last_element = get_last_le(head);
	last_element->next = value;
}

int main(int argc, char** argv)
{

	struct animal head;
	head.name = "v¨µ£D%SDc%138JDSH£QZD¨µ£Q%";
	head.age = 998;
	init_list_element((struct list_element*)&head);

	struct animal dog;
	init_list_element((struct list_element*)&dog);
	dog.name = "jake";
	dog.age = 293;

	add_list_element((struct list_element*)&head, (struct list_element*)&dog);

	struct animal* cur_ = &head;
	while (cur_ != NULL)
	{
		printf(" [ELEMENT] %s : %i\n", cur_->name, cur_->age);
		cur_ = (struct animal*)cur_->element.next;
	}

	return 0;
}