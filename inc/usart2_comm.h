/*
 * usart2_comm.h
 *
 *  Created on: Apr 1, 2018
 *      Author: abel
 */

#ifndef USART2_COMM_H_
#define USART2_COMM_H_


void init_USART2(void);
void USART_TX_byte(uint8_t byte);
void USART_TX_string(char *str_to_transmit);

#endif /* USART2_COMM_H_ */
