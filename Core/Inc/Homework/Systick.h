#ifndef INC_HOMEWORK_SYSTICK_H_
#define INC_HOMEWORK_SYSTICK_H_

#include <stdint.h>

struct systick {
    uint32_t CSR;
    uint32_t RVR;
    uint32_t CVR;
    uint32_t CALIB;
};

struct systick * init_systick();

void delay_systick();

#endif /* INC_HOMEWORK_SYSTICK_H_ */
