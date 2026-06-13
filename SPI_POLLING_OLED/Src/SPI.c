#include "SPI.h"

/*
 * PIN Connections
 * NSS -> PA4
 * SCK -> PA5
 * MISO -> PA6
 * MOSI -> PA7
 */
void SPI1_GPIO_INIT(void)
{
	//1. Enable Clock(GPIOA)
	AHB1ENR |= (1U << 0);

	//2.Set output type to alternate function
	//PA4
	GPIOA_MODER &= ~(3U << 8);
	GPIOA_MODER |= (1U << 9);

	//PA5
	GPIOA_MODER &= ~(3U << 10);
	GPIOA_MODER |= (1U << 11);

	//PA6
	GPIOA_MODER &= ~(3U << 12);
	GPIOA_MODER |= (1U << 13);

	//PA7
	GPIOA_MODER &= ~(3U << 14);
	GPIOA_MODER |= (1U << 15);

	//3.Set Alternate function mode to AF5
	//PA4
	GPIOA_AFRL &= ~(0xF << 16);
	GPIOA_AFRL |= (1U << 16);
	GPIOA_AFRL |= (1U << 18);

	//PA5
	GPIOA_AFRL &= ~(0xF << 20);
	GPIOA_AFRL |= (1U << 20);
	GPIOA_AFRL |= (1U << 22);

	//PA6
	GPIOA_AFRL &= ~(0xF << 24);
	GPIOA_AFRL |= (1U << 24);
	GPIOA_AFRL |= (1U << 26);

	//PA7
	GPIOA_AFRL &= ~(0xF << 28);
	GPIOA_AFRL |= (1U << 28);
	GPIOA_AFRL |= (1U << 30);
}


void SPI_Master_INIT(void)
{
	//Enable Clock
	APB2ENR |= (1U << 12);     // SPI1EN

	//Set device mode
	SPI1_CR1 |= (1U << 2);		//Master Mode

	//Set Bus configurations

	//Set Baud rate
	SPI1_CR1 &= ~(3U << 3);		//Reset
	SPI1_CR1 |= (1U << 4);		//Fclk/8

	//Clock settings
	SPI1_CR1 &= ~(1U << 0);		//CPHA
	SPI1_CR1 &= ~(1U << 1);		//CPOL

	//set data frame format
	SPI1_CR1 &= ~(1U << 11);		//16bit format

	//Set hardware slave management
	SPI1_CR1 &= ~(1U << 9);		//Disable SSM
	SPI1_CR2 |= (1U << 2);		//SSOE enable


}

void SPI_Enable(void)
{
	SPI1_CR1 |= (1U << 6);
}


void SPI_Disable(void)
{
	SPI1_CR1 &= ~(1U << 6);
}

void Send_Data(uint8_t *Data,uint32_t length)
{
	while(length > 0)
	{
		while(!(SPI1_SR & (1U << 1))); //Wait for TXE flag

		SPI1_DR=*Data;
		Data++;
		length--;
	}

	while((SPI1_SR & (1U << 7))); //Wait for BSY flag
}

