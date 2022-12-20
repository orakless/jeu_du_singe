//
// Created by evag on 15/12/22.
//

#include "file.h"
#include "range.h"

#include <cassert>

bool is_file_empty(const File &file)
{
    return (file.first == nullptr && file.last == nullptr);
}

Node * head(const File &file)
{
    return file.first;
}

void add(File &file, const Range &range)
{

    auto newNode = new Node;
    newNode->currentRange = {.start = range.start, .end = range.end};
    newNode->nextNode = nullptr;

    if (is_file_empty(file)) file.first = newNode;
    else file.last->nextNode = newNode;

    file.last = newNode;
}

void remove(File &file)
{
    assert (!is_file_empty(file));

    Node * nodeToDel = file.first;
    if (file.first->nextNode != nullptr)
    {
        file.first = file.first->nextNode;
    }
    else
    {
        file.first = nullptr;
        file.last = nullptr;
    }
    delete nodeToDel;
}

void destroy(File &file)
{

}