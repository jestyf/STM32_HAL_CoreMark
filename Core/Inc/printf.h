#ifndef _printf_h_
#define _printf_h_
#include <stdio.h>
#include <stdlib.h>
#include "usart.h"
#ifdef __GNUC__

// in arm-none-eabi-gcc, printf implements with _write
int _write (int fd, char *pBuffer, int size)  
{  
    HAL_UART_Transmit(&huart1,(uint8_t*)pBuffer,(uint16_t)size,0xffff);
    return size;  
}
  // /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
  //    set to 'Yes') calls __io_putchar() */
  // #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
// #endif /* __GNUC__ */
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}
#endif /* __GNUC__ */

#endif