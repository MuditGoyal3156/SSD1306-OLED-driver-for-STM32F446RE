
#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

#define RCC_BASE_ADDR		0x40023800U
#define AHB1ENR		(*(volatile uint32_t* )(RCC_BASE_ADDR + 0x30U))
#define APB2ENR		(*(volatile uint32_t* )(RCC_BASE_ADDR + 0x44U))

#define GPIOA_BASE_ADDR		0x40020000U
#define GPIOA_MODER			(*(volatile uint32_t* )(GPIOA_BASE_ADDR + 0x00U))
#define GPIOA_AFRL 			(*(volatile uint32_t* )(GPIOA_BASE_ADDR + 0x20U))

#define SPI1_BASE_ADDR		0x40013000U
#define SPI1_CR1			(*(volatile uint32_t*)(SPI1_BASE_ADDR + 0x00U))
#define SPI1_CR2			(*(volatile uint32_t*)(SPI1_BASE_ADDR + 0x04U))
#define SPI1_SR				(*(volatile uint32_t*)(SPI1_BASE_ADDR + 0x08U))
#define SPI1_DR				(*(volatile uint32_t*)(SPI1_BASE_ADDR + 0x0CU))

void SPI1_GPIO_INIT(void);

void SPI_Master_INIT(void);
void SPI_Enable(void);
void SPI_Disable(void);

void Send_Data(uint8_t *Data,uint32_t length);

#endif /* SPI_H_ */
