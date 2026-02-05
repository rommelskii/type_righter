#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_


#include "dtk.h"

/**
* @brief Writes a token list to a file
* @param buflist Token list
*/
void file_save(struct DTkL* buflist, const char* PATH);

/**
* @brief Performs a fixed-buffer XOR obfuscation on a plaintext file to produce a binary file
* @param buflist Token list
*/
void file_obfuscate(const char* PATH);

#endif //FILE_UTILS_H_
