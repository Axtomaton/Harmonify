#ifndef HW8_H_
#define HW8_H_

#include <stdint.h>

/**
 * @brief - Parse delay bytes to a uint32_t
 * @param delay - midi message delay bytes
 * @return uint32_t - integer value for the delay
 */
uint32_t parseDelay(uint8_t* delay);

/**
 * @brief - Test function for parsing delay
 */
void test_Parsing();

#endif /* HW8_H_ */
