#ifndef STREAM_UTILS_H_
#define STREAM_UTILS_H_

#include "dtk.h" // for DTkL

/**
* @brief Receives lines from line buffer up to stream_len bytes
*
* @param lbuf Line buffer 
* @param stream_len Maximum number of bytes to stream
*/
void stream_input(struct DTkL* buflist, char* lbuf, size_t stream_len);

/**
* @brief Obfuscates a character buffer by performing XOR with a key 
*
* @param lbuf Line buffer 
* @param stream_len Maximum number of bytes to stream
*/
void stream_obfuscate(char* str, size_t len, const char* key);


#endif //STREAM_UTILS_H_
