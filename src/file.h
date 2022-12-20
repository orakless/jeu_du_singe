//
// Created by evag on 15/12/22.
//

#ifndef SINGE_FILE_H
#define SINGE_FILE_H

#include "node.h"
#include "range.h"

struct File {
    Node * first;
    Node * last;
};

bool is_file_empty(const File &file);

Node * head(const File &file);

void add(File &file, const Range &range);
void remove(File &file);
void destroy(File &file);

#endif //SINGE_FILE_H
