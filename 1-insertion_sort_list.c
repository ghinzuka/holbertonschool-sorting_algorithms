#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: pointer of pointer of head of list of integer
 * 
*/
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;  // If list is empty or has only one node, it's already sorted

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            int temp_val = temp->n;
            temp->n = temp->prev->n;
            temp->prev->n = temp_val;
            temp = temp->prev;
        }
        current = current->next;
    }
}