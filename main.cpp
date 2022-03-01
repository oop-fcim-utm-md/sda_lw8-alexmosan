#include "header.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[], char *envp[])
{
    node_t * first = NULL;
    const char * data [3] = {"Alpha", "Bravo", "Charlie"};

    initialize(&first, data, 3);

    assert(first->data_.id_ == 1);
    assert(!strcmp(first->data_.name_, "Alpha"));

    print(first);

    node_t * alpha_ref = find_ref(first, "Alpha", 0);
    assert(alpha_ref->data_.id_ == 1);
    printf("\n%d", alpha_ref->data_.id_);

    node_t * bravo_ref = find_ref(first, NULL, 2);
    assert(bravo_ref->data_.id_ == 2);
    printf("\n%s", bravo_ref->data_.name_);

    node_t * charlie_ref = find_ref(first, "Charlie", 3);
    assert(charlie_ref->data_.id_ == 3);
    printf("\n%s", charlie_ref->data_.name_);

    swap(alpha_ref, charlie_ref);

    assert(alpha_ref->data_.id_ == 3);
    assert(!strcmp(alpha_ref->data_.name_, "Charlie"));

    edit(bravo_ref, "Bob");

    assert(bravo_ref->data_.id_ == 2);
    assert(!strcmp(bravo_ref->data_.name_, "Bob"));

    data_t alpha = find(first, "Alpha", 0);
    assert(alpha.id_ == 1);
    printf("\n%d", alpha.id_);

    data_t bravo = find(first, NULL, 2);
    assert(bravo.id_ == 2);
    printf("\n%s", bravo.name_);

    data_t charlie = find(first, "Charlie", 3);
    assert(charlie.id_ == 3);
    printf("\n%s", charlie.name_);

    print(first);

    clear(first);
}
