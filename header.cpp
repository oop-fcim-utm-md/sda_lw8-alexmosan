#include "header.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

void initialize(node_t **first, const char **names, const unsigned int length)
{
    node_t **nodes = new node_t *[length];
    for (size_t i = 0; i < length; i++)
    {
        if (!*first)
        {
            *first = new node_t;
            (*first)->data_.id_ = i + 1;
            strcpy((*first)->data_.name_, names[i]);
            (*first)->next_ = NULL;
        }
        else
        {
            nodes[i] = new node_t;
            nodes[i]->data_.id_ = i + 1;
            strcpy(nodes[i]->data_.name_, names[i]);
            nodes[i]->next_ = NULL;

            if (!(*first)->next_)
                (*first)->next_ = nodes[i];
            else
                nodes[i - 1]->next_ = nodes[i];
        }
    }
}

void print(node_t *arr)
{
    while (arr)
    {
        std::cout << arr->data_.name_ << " ";
        arr = arr->next_;
    }
}

void clear(node_t *arr)
{
    while (arr)
    {
        arr->data_.id_ = 0;
        for (size_t i = 0; i < strlen(arr->data_.name_); i++)
        {
            arr->data_.name_[i] = 0;
        }
        arr = arr->next_;
    }
}

void swap(node_t *a, node_t *b)
{
    int temp = a->data_.id_;
    char str_temp[50];
    strcpy(str_temp, a->data_.name_);

    a->data_.id_ = b->data_.id_;
    strcpy(a->data_.name_, b->data_.name_);

    b->data_.id_ = temp;
    strcpy(b->data_.name_, str_temp);
}

data_t find(node_t *arr, const char *name, const unsigned int id)
{
    if (!name && !id)
    {
        data_t *res = new data_t;
        return *res;
    }
    else if (!name)
    {
        while (arr)
        {
            if (arr->data_.id_ == id)
            {
                return arr->data_;
            }
            arr = arr->next_;
        }
    }
    else if (!id)
    {
        int flag = 0;
        while (arr)
        {
            for (size_t i = 0; i < strlen(arr->data_.name_); i++)
            {
                if (arr->data_.name_[i] == name[i])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }

            if (flag)
            {
                return arr->data_;
            }
            arr = arr->next_;
        }
    }
    else
    {
        while (arr)
        {
            if (arr->data_.id_ == id && strcpy(arr->data_.name_, name))
            {
                return arr->data_;
            }
            arr = arr->next_;
        }
    }
    // data_t *res = new data_t;
    return data_t{};
}

node_t *find_ref(node_t *arr, const char *name, const unsigned int id)
{
    if (!name && !id)
    {
        return NULL;
    }
    else if (!name)
    {
        while (arr)
        {
            if (arr->data_.id_ == id)
            {
                return arr;
            }
            arr = arr->next_;
        }
    }
    else if (!id)
    {
        while (arr)
        {
            if (strcpy(arr->data_.name_, name))
            {
                return arr;
            }
            arr = arr->next_;
        }
    }
    else
    {
        while (arr)
        {
            if (arr->data_.id_ == id && strcpy(arr->data_.name_, name))
            {
                return arr;
            }
            arr = arr->next_;
        }
    }

    return NULL;
}

void edit(node_t *arr, const char *name)
{
    if (name)
        strcpy(arr->data_.name_, name);
}