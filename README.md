# STM32_HAL_CoreMark
[Coremark](https://github.com/eembc/coremark) on stm32f103c8t6  

this project can also port to other stm32 mcu.  
## how to use  
Install `arm-none-eabi-gcc` first. Use command `make` to build, and flash `build/CoreMark103.bin` to mcu with st-link or jlink or dap-link. UART1(PA9, PA10) is used to print the coremark result. 
