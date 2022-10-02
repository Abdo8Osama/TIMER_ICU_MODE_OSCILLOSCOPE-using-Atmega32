
/****************GUARD MY FILE********************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

//TCCR0_REG
#define	FOC0 	7
#define	WGM00 	6
#define	COM01 	5
#define	COM00 	4
#define	WGM01 	3
#define	CS02 	2
#define	CS01 	1
#define	CS00 	0
//TIMSK_REG
#define	TOIE0 	0
#define	OCIE0	1
//TIFR_REG
#define	TOV0 	0
#define	OCF0	1
//SREG_REG
#define GIE_PIN		7		
//TIMER_PIN
#define	TIMER0		0
#define	TIMER1		1
#define	TIMER2		2
//TIMER_MODE
#define	NORMAL		0
#define	PWM			1
#define	CTC			2
#define	FAST_PWM	3
//CLOCK_SOURCE
#define	OFF						0
#define	FCPU					1
#define	FCPU8					2
#define	FCPU64					3
#define	FCPU256					4
#define	FCPU1024				5
#define	FALLING_EDGE_COUNTER	6
#define	RISING_EDGE_COUNTER		7
//INTERRUPT_POLLING
#define	INTERRUPT	0
#define	POLLING		1
//OCO_INVERTING_NONINVERTING
#define	OCO_DISABLE			0
#define	OCO_TOGGLE			1
#define	NONINVERTING		2
#define	INVERTING			3

/****************TIMER FUNCTIONS *********************/
void TIMER_INIT(u8 TIMER_MODE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u8 TCNT_PRELOAD ,u8 OCR_PRELOAD , u8 OCO_INVERTING_NONINVERTING);
u8 OCF0_Flag_Read(void);
u8 TOV0_Flag_Read(void);
void OCF0_Flag_Clear(void);
void TOV0_Flag_Clear(void);
void TIMER0C_INT_Disable (void );
void TIMER0V_INT_Disable (void );
void CALLback_TIMER (void (* ptr) (void));
void TCNT0_REG_LOAD(u8 TCNT0_VALUE);
void OCR0_REG_LOAD(u8 OCR0_VALUE);
void TIMER0_DELAY_ms(u32 TIME_ms);





#endif


