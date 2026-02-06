#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

#include "dtk.h"

#define FILE_OBF_LEN 8192
#define KEY "WeDoNotTalkAboutTheKey"

/**
* @brief Writes a token list to a file
* @param buflist Token list
*/
void file_save(struct DTkL* buflist, const char* PATH);

/**
* @brief Performs a fixed-buffer XOR obfuscation on a plaintext file to produce a binary file
* @param buflist Token list
*/
void file_obfuscate(const char* ORIGINAL_PATH, const char* RESULT_PATH);

void xor_cize_offset(char* str, size_t len, const char* key, size_t keylen, size_t file_offset);

#endif //FILE_UTILS_H_
