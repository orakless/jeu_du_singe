//
// Created by evag on 15/12/22.
//

#ifndef SINGE_FILE_H
#define SINGE_FILE_H

#include "node.h"
#include "range.h"
#include <cassert>

struct File {
    Node * first;
    Node * last;
};

/**
 * @brief Checks if the file is empty
 * @param file
 * @return True of false, depending on if the file is empty or not
 */
bool is_file_empty(const File &file);

/**
 * @brief Returns the head node
 * @param file
 * @return Node variable
 */
Node * head(const File &file);

/**
 * @brief Adds a range to the File
 * @param file
 * @param range
 */
void add(File &file, const Range &range);

/**
 * @brief Removes a range from the File
 * @param file
 */
void remove(File &file);

/**
 * @brief Destroys the File's nodes in memory
 * @param file
 */
void destroy(File &file);

#endif //SINGE_FILE_H
