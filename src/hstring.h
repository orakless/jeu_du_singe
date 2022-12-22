#ifndef SINGE_STRING
#define SINGE_STRING

struct String
{
    char * value;
    unsigned long memUsed;
};

/**
 * @brief Initialize a string structure with default values
 * @param[IN] str The string to initialize
 */
void init(String &str);

/**
 * @brief Checks whether the String is allocated or not.
 * @param SRC
 */
bool is_allocated(const String &SRC);

/**
 *
 * @param SRC
 */
void to_upper(String &SRC);

/**
 * @brief Returns the String value as a c-string.
 * @param SRC
 * @return c-string
 */
char * get(const String &SRC);

/**
 * @brief Sets the value for a given String
 * @param[IN,OUT] dest The string to change
 * @param[IN] SRC the new value (as a c-string)
 */
void set(String &dest, const char *SRC);

/**
 * @brief Sets the value for a given String
 * @param[IN,OUT] dest The string to change
 * @param[IN] SRC the new value (as a String)
 */
void set(String &dest, const String &SRC);

/**
 * @brief Appends a character to a given String
 * @param[IN,OUT] dest The String to change
 * @param[IN] SRC the value to append (as a char)
 */
void append(String &dest, char SRC);

/**
 * @brief Appends a value to a given String
 * @param[IN,OUT] dest The String to change
 * @param[IN] SRC the value to append (as a c-string)
 */
void append(String &dest, const char *SRC);

/**
 * @brief Appends a value to a given String
 * @param[IN,OUT] dest The String to change
 * @param[IN] SRC the value to append (as a String)
 */
void append(String &dest, const String &SRC);

/**
 * @brief Destroys a String structure.
 * @param str The String structure to destroy.
 */
void destroy(String &str);

#endif