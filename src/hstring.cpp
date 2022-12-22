#include "hstring.h"
#include "types_const.h"
#include <cstring>
#include <cassert>
#include <cctype>

void init(String &str)
{
    str.value = new char[CHUNK_SIZE];
    str.value[0] = 0;
    str.memUsed = CHUNK_SIZE;
}

bool is_allocated(const String &SRC)
{
    return (SRC.value != nullptr);
}

void to_upper(String &src)
{
    uint count = 0;
    while (src.value[count] != 0)
    {
        if (src.value[count] >= 'a' && src.value[count] <= 'z')
            src.value[count] = (char)toupper(src.value[count]);
    }
}

char * get(const String &SRC)
{
    return SRC.value;
}

void set(String &dest, const char *SRC)
{
    unsigned long len = strlen(SRC),
            memSize = (len/CHUNK_SIZE)*CHUNK_SIZE*sizeof(char);
    if (len % CHUNK_SIZE != 0) memSize += CHUNK_SIZE;

    if (memSize != dest.memUsed || dest.value == nullptr)
    {
        delete[] dest.value;
        dest.value = new char[memSize];
        dest.memUsed = memSize;
    }
    strcpy(dest.value, SRC);
}

void set(String &dest, const String &SRC)
{
    set(dest, SRC.value);
}

void append(String &dest, char SRC)
{
    ulong currLen = strlen(dest.value);
    assert (dest.value != nullptr);

    if (currLen+2 > dest.memUsed)
    {
        auto newValue = new char[dest.memUsed+CHUNK_SIZE];
        dest.memUsed += CHUNK_SIZE;

        strcpy(newValue, dest.value);

        delete[] dest.value;
        dest.value = newValue;
    }
    dest.value[currLen] = SRC;
    dest.value[currLen+1] = 0;
}

void append(String &dest, const char *SRC)
{
    ulong currLen = strlen(dest.value)+strlen(SRC);
    if (currLen+1 > dest.memUsed)
    {
        uint memToUse = (currLen/CHUNK_SIZE)*CHUNK_SIZE;
        if (currLen%CHUNK_SIZE > 0) memToUse += CHUNK_SIZE;

        auto newValue = new char[memToUse]; // clears the memory allocated
        strcpy(newValue, dest.value);

        dest.memUsed = memToUse;
        delete[] dest.value;
        dest.value = newValue;
    }
    strcpy(&dest.value[strlen(dest.value)], SRC);
}

void append(String &dest, const String &SRC)
{
    append(dest, SRC.value);
}

void destroy(String &str)
{
    delete[] str.value;
    str.memUsed = 0;
}