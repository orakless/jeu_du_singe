#include <fstream>
#include "types_const.h"
#include "text_file.h"

ulong get_line_count(std::ifstream &stream)
{
    ulong count = 0;

    char temp[MAX_WORD_SIZE];

    while (stream.peek() != EOF)
    {
        stream.getline(temp, MAX_WORD_SIZE);
        ++count;
    }

    return count;
}