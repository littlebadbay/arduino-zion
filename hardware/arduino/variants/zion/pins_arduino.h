/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
  ------------------------------------------------------
  2010-03,  Add Arduino Zion Support.       Edison
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            50
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 40 : -1)
#define digitalPinHasPWM(p)         (((p) >= 35 && (p) <= 38) || ((p) >= 28 && (p)<= 31))

static const uint8_t SS   = 24;
static const uint8_t MOSI = 26;
static const uint8_t MISO = 27;
static const uint8_t SCK  = 25;

static const uint8_t SDA = 1;
static const uint8_t SCL = 0;
static const uint8_t LED_BUILTIN = 48;

static const uint8_t A0 = 40;
static const uint8_t A1 = 41;
static const uint8_t A2 = 42;
static const uint8_t A3 = 43;
static const uint8_t A4 = 44;
static const uint8_t A5 = 45;
static const uint8_t A6 = 46;
static const uint8_t A7 = 47;

// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// 
// Edison: 
// ATmega128 doesn't have PCINTs, I added the regular external interrupt,INT0-INT3, reserve but works on pin change, INT4-INT7 has pin change interrupt option
// Pins:  0,1,2,3,36,37,38,39

/*
#define digitalPinToPCICR(p)    ( (((p) >= 36) && ((p) <= 39)) ? (&EICRB) : ((uint8_t *)0) )

#define digitalPinToPCICRbit(p) ( (((p) >= 36) && ((p) <= 39)) ? (p-36)*2 : 0 ) 

#define digitalPinToPCMSK(p)    ( (((p) >= 36) && ((p) <= 39)) ? (&EIMSK) : \
                                ((uint8_t *)0) ) 

#define digitalPinToPCMSKbit(p) ( (((p) >= 36) && ((p) <= 39)) ? ((p-32)):0 )

*/

#define digitalPinToPCICR(p)    ( (((p) >= 36) && ((p) <= 39)) ? (&EICRB) : \
                                  (((p) >= 0) && ((p) <= 3)) ? (&EICRA) : ((uint8_t *)0) )

#define digitalPinToPCICRbit(p) ( (((p) >= 36) && ((p) <= 39)) ? ((p-36)*2) : \
                                ( (((p) >= 0) && ((p) <= 3))) ? ((p*2)) : \
                                0 )

#define digitalPinToPCMSK(p)    ( (((p) >= 36) && ((p) <= 39)) || (((p) >= 0) && ((p) <= 3)) ? (&EIMSK) : \
                                ((uint8_t *)0) ) 

#define digitalPinToPCMSKbit(p) ( (((p) >= 36) && ((p) <= 39)) ? ((p-32)) : \
                                ( (((p) >= 0) && ((p) <= 3))) ? ((p)) : \
                                0 )




#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST		
	// -------------------------------------------		
	PD	, // PD 0 ** 0 ** I2C_SCL INT0
	PD	, // PD 1 ** 1 ** I2C_SDA INT1
	PD	, // PD 2 ** 2 ** USART1_RX INT2
	PD	, // PD 3 ** 3 ** USART1_TX INT3
	PD	, // PD 4 ** 4 ** D4	
	PD	, // PD 5 ** 5 ** D5	
	PD	, // PD 6 ** 6 ** D6	
	PD	, // PD 7 ** 7 ** D7	
	PC	, // PC 0 ** 8 ** D8	
	PC	, // PC 1 ** 9 ** D9	
	PC	, // PC 2 ** 10 ** D10	
	PC	, // PC 3 ** 11 ** D11	
	PC	, // PC 4 ** 12 ** D12	
	PC	, // PC 5 ** 13 ** D13	
	PC	, // PC 6 ** 14 ** D14	
	PC	, // PC 7 ** 15 ** D15	
	PA	, // PA 0 ** 16 ** D16	
	PA	, // PA 1 ** 17 ** D17	
	PA	, // PA 2 ** 18 ** D18	
	PA	, // PA 3 ** 19 ** D19	
	PA	, // PA 4 ** 20 ** D20	
	PA	, // PA 5 ** 21 ** D21	
	PA	, // PA 6 ** 22 ** D22	
	PA	, // PA 7 ** 23 ** D23	
	PB	, // PB 0 ** 24 ** SPI_SS
	PB	, // PB 1 ** 25 ** SPI_SCK
	PB	, // PB 2 ** 26 ** SPI_MOSI
	PB	, // PB 3 ** 27 ** SPI_MISO
	PB	, // PB 4 ** 28 ** PWM	OC0
	PB	, // PB 5 ** 29 ** PWM	OC1A
	PB	, // PB 6 ** 30 ** PWM	OC1B
	PB	, // PB 7 ** 31 ** PWM	OC2/OC1C
	PE	, // PE 0 ** 32 ** USART0_RX
	PE	, // PE 1 ** 33 ** USART0_TX
	PE	, // PE 2 ** 34 ** D34	
	PE	, // PE 3 ** 35 ** PWM OC3A
	PE	, // PE 4 ** 36 ** PWM OC3B INT4
	PE	, // PE 5 ** 37 ** PWM OC3C INT5
	PE	, // PE 6 ** 38 ** INT6
	PE	, // PE 7 ** 39 ** INT7
	PF	, // PF 0 ** 40 ** D40 A0
	PF	, // PF 1 ** 41 ** D41 A1
	PF	, // PF 2 ** 42 ** D42 A2
	PF	, // PF 3 ** 43 ** D43 A3
	PF	, // PF 4 ** 44 ** D44 A4
	PF	, // PF 5 ** 45 ** D45 A5
	PF	, // PF 6 ** 46 ** D46 A6
	PF	, // PF 7 ** 47 ** D47 A7
	PG	, // PG 0 ** 48 ** D48	
	PG	, // PG 1 ** 49 ** D49	
	PG	, // PG 2 ** 50 ** D50	
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 0 )	, // PD 0 ** 0 ** I2C_SCL INT0      
	_BV( 1 )	, // PD 1 ** 1 ** I2C_SDA INT1             
	_BV( 2 )	, // PD 2 ** 2 ** USART1_RX INT2           
	_BV( 3 )	, // PD 3 ** 3 ** USART1_TX INT3           
	_BV( 4 )	, // PD 4 ** 4 ** D4	                  
	_BV( 5 )	, // PD 5 ** 5 ** D5	                  
	_BV( 6 )	, // PD 6 ** 6 ** D6	                  
	_BV( 7 )	, // PD 7 ** 7 ** D7	                  
	_BV( 0 )	, // PC 0 ** 8 ** D8	                  
	_BV( 1 )	, // PC 1 ** 9 ** D9	                  
	_BV( 2 )	, // PC 2 ** 10 ** D10	                  
	_BV( 3 )	, // PC 3 ** 11 ** D11	                  
	_BV( 4 )	, // PC 4 ** 12 ** D12	                  
	_BV( 5 )	, // PC 5 ** 13 ** D13	                  
	_BV( 6 )	, // PC 6 ** 14 ** D14	                  
	_BV( 7 )	, // PC 7 ** 15 ** D15	                  
	_BV( 0 )	, // PA 0 ** 16 ** D16	                  
	_BV( 1 )	, // PA 1 ** 17 ** D17	                  
	_BV( 2 )	, // PA 2 ** 18 ** D18	                  
	_BV( 3 )	, // PA 3 ** 19 ** D19	                  
	_BV( 4 )	, // PA 4 ** 20 ** D20	                  
	_BV( 5 )	, // PA 5 ** 21 ** D21	                  
	_BV( 6 )	, // PA 6 ** 22 ** D22	                  
	_BV( 7 )	, // PA 7 ** 23 ** D23	                  
	_BV( 0 )	, // PB 0 ** 24 ** SPI_SS                  
	_BV( 1 )	, // PB 1 ** 25 ** SPI_SCK                 
	_BV( 2 )	, // PB 2 ** 26 ** SPI_MOSI                
	_BV( 3 )	, // PB 3 ** 27 ** SPI_MISO                
	_BV( 4 )	, // PB 4 ** 28 ** PWM	OC0               
	_BV( 5 )	, // PB 5 ** 29 ** PWM	OC1A              
	_BV( 6 )	, // PB 6 ** 30 ** PWM	OC1B              
	_BV( 7 )	, // PB 7 ** 31 ** PWM	OC2/OC1C          
	_BV( 0 )	, // PE 0 ** 32 ** USART0_RX               
	_BV( 1 )	, // PE 1 ** 33 ** USART0_TX               
	_BV( 2 )	, // PE 2 ** 34 ** D34	                  
	_BV( 3 )	, // PE 3 ** 35 ** PWM OC3A                
	_BV( 4 )	, // PE 4 ** 36 ** PWM OC3B INT4           
	_BV( 5 )	, // PE 5 ** 37 ** PWM OC3C INT5           
	_BV( 6 )	, // PE 6 ** 38 ** INT6                    
	_BV( 7 )	, // PE 7 ** 39 ** INT7                    
	_BV( 0 )	, // PF 0 ** 40 ** D40 A0                  
	_BV( 1 )	, // PF 1 ** 41 ** D41 A1                  
	_BV( 2 )	, // PF 2 ** 42 ** D42 A2                  
	_BV( 3 )	, // PF 3 ** 43 ** D43 A3                  
	_BV( 4 )	, // PF 4 ** 44 ** D44 A4                  
	_BV( 5 )	, // PF 5 ** 45 ** D45 A5                  
	_BV( 6 )	, // PF 6 ** 46 ** D46 A6                  
	_BV( 7 )	, // PF 7 ** 47 ** D47 A7                  
	_BV( 0 )	, // PG 0 ** 48 ** D48	                  
	_BV( 1 )	, // PG 1 ** 49 ** D49	                  
	_BV( 2 )	, // PG 2 ** 50 ** D50	                
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	NOT_ON_TIMER	, // PD 0 ** 0 ** I2C_SCL INT0        
	NOT_ON_TIMER	, // PD 1 ** 1 ** I2C_SDA INT1        
	NOT_ON_TIMER	, // PD 2 ** 2 ** USART1_RX INT2      
	NOT_ON_TIMER	, // PD 3 ** 3 ** USART1_TX INT3      
	NOT_ON_TIMER	, // PD 4 ** 4 ** D4	              
	NOT_ON_TIMER	, // PD 5 ** 5 ** D5	              
	NOT_ON_TIMER	, // PD 6 ** 6 ** D6	              
	NOT_ON_TIMER	, // PD 7 ** 7 ** D7	              
	NOT_ON_TIMER	, // PC 0 ** 8 ** D8	              
	NOT_ON_TIMER	, // PC 1 ** 9 ** D9	              
	NOT_ON_TIMER	, // PC 2 ** 10 ** D10	              
	NOT_ON_TIMER	, // PC 3 ** 11 ** D11	              
	NOT_ON_TIMER	, // PC 4 ** 12 ** D12	              
	NOT_ON_TIMER	, // PC 5 ** 13 ** D13	              
	NOT_ON_TIMER	, // PC 6 ** 14 ** D14	              
	NOT_ON_TIMER	, // PC 7 ** 15 ** D15	              
	NOT_ON_TIMER	, // PA 0 ** 16 ** D16	              
	NOT_ON_TIMER	, // PA 1 ** 17 ** D17	              
	NOT_ON_TIMER	, // PA 2 ** 18 ** D18	              
	NOT_ON_TIMER	, // PA 3 ** 19 ** D19	              
	NOT_ON_TIMER	, // PA 4 ** 20 ** D20	              
	NOT_ON_TIMER	, // PA 5 ** 21 ** D21	              
	NOT_ON_TIMER	, // PA 6 ** 22 ** D22	              
	NOT_ON_TIMER	, // PA 7 ** 23 ** D23	              
	NOT_ON_TIMER	, // PB 0 ** 24 ** SPI_SS             
	NOT_ON_TIMER	, // PB 1 ** 25 ** SPI_SCK            
	NOT_ON_TIMER	, // PB 2 ** 26 ** SPI_MOSI           
	NOT_ON_TIMER	, // PB 3 ** 27 ** SPI_MISO           
	TIMER0A		, // PB 4 ** 28 ** PWM	OC0           
	TIMER1A 	, // PB 5 ** 29 ** PWM	OC1A          
	TIMER1B 	, // PB 6 ** 30 ** PWM	OC1B          
	TIMER2  	, // PB 7 ** 31 ** PWM	OC2/OC1C      
	NOT_ON_TIMER	, // PE 0 ** 32 ** USART0_RX          
	NOT_ON_TIMER	, // PE 1 ** 33 ** USART0_TX          
	NOT_ON_TIMER	, // PE 2 ** 34 ** D34	              
	TIMER3A		, // PE 3 ** 35 ** PWM OC3A           
	TIMER3B 	, // PE 4 ** 36 ** PWM OC3B INT4      
	TIMER3C 	, // PE 5 ** 37 ** PWM OC3C INT5      
	NOT_ON_TIMER	, // PE 6 ** 38 ** INT6               
	NOT_ON_TIMER	, // PE 7 ** 39 ** INT7               
	NOT_ON_TIMER	, // PF 0 ** 40 ** D40 A0             
	NOT_ON_TIMER	, // PF 1 ** 41 ** D41 A1             
	NOT_ON_TIMER	, // PF 2 ** 42 ** D42 A2             
	NOT_ON_TIMER	, // PF 3 ** 43 ** D43 A3             
	NOT_ON_TIMER	, // PF 4 ** 44 ** D44 A4             
	NOT_ON_TIMER	, // PF 5 ** 45 ** D45 A5             
	NOT_ON_TIMER	, // PF 6 ** 46 ** D46 A6             
	NOT_ON_TIMER	, // PF 7 ** 47 ** D47 A7             
	NOT_ON_TIMER	, // PG 0 ** 48 ** D48	              
	NOT_ON_TIMER	, // PG 1 ** 49 ** D49	              
	NOT_ON_TIMER	, // PG 2 ** 50 ** D50	              
};

#endif

#endif