#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"DIO_interface.h"

/*
	DIO_voidSetPinDireation(PORTA , PIN0 ,OUTPUT);
	A0 ===> output 				===> 	DDR = 1
	
	
	DIO_voidSetPinDireation(PORTA , PIN1 ,OUTPUT);
	A1 ===> input 				===> 	DDR = 0
*/
void	DIO_voidSetPinDir(uint_8 PortID , uint_8 PinID ,uint_8 Direction)
{
	/*		Range Check						*/
	if(PortID <4 && PinID < 8)
	{
		if(Direction==OUTPUT)
		{
			switch(PortID)
			{
				case PORTA	:	SET_BIT(DDRA_REG,PinID);	break;
				case PORTB	:	SET_BIT(DDRB_REG,PinID);	break;
				case PORTC	:	SET_BIT(DDRC_REG,PinID);	break;
				case PORTD	:	SET_BIT(DDRD_REG,PinID);	break;
			}
		}
		else if (Direction==INPUT)
		{
			switch(PortID)
			{
				case PORTA	:	CLR_BIT(DDRA_REG,PinID);	break;
				case PORTB	:	CLR_BIT(DDRB_REG,PinID);	break;
				case PORTC	:	CLR_BIT(DDRC_REG,PinID);	break;
				case PORTD	:	CLR_BIT(DDRD_REG,PinID);	break;
			}
		}
		else
		{
			/*		Return ERROR				*/
		}
	}
	else
	{
		/*		Return ERROR				*/
	}
}

void	DIO_voidSetPinValue(uint_8 PortID , uint_8 PinID ,uint_8 Value)
{
	/*		Range Check						*/
	if(PortID <4 && PinID < 8)
	{
		if(Value == HIGH)
		{
			switch(PortID)
			{
				case PORTA	:	SET_BIT(PORTA_REG,PinID);	break;
				case PORTB	:	SET_BIT(PORTB_REG,PinID);	break;
				case PORTC	:	SET_BIT(PORTC_REG,PinID);	break;
				case PORTD	:	SET_BIT(PORTD_REG,PinID);	break;
			}
		}
		else if (Value==LOW)
		{
			switch(PortID)
			{
				case PORTA	:	CLR_BIT(PORTA_REG,PinID);	break;
				case PORTB	:	CLR_BIT(PORTB_REG,PinID);	break;
				case PORTC	:	CLR_BIT(PORTC_REG,PinID);	break;
				case PORTD  :	CLR_BIT(PORTD_REG,PinID);	break;
			}
		}
		else
		{
			/*		Return ERROR				*/
		}
	}
	else
	{
		/*		Return ERROR				*/
	}	
}
/*
x = DIO_uint_8GetPinValue(PORTA , PIN0);
*/
uint_8	DIO_uint_8GetPinValue(uint_8 PortID , uint_8 PinID)
{
	uint_8	Local_Value = 0xFF ;
	/*		Range Check						*/
	if(PortID <4 && PinID < 8)
	{
			switch(PortID)
			{
				case PORTA	:	Local_Value	=	GET_BIT(PINA_REG,PinID);	break;
				case PORTB	:	Local_Value	=	GET_BIT(PINB_REG,PinID);	break;
				case PORTC	:	Local_Value	=	GET_BIT(PINC_REG,PinID);	break;
				case PORTD	:	Local_Value	=	GET_BIT(PIND_REG,PinID);	break;
			}
	}
	else
	{
		/*		Return ERROR				*/
	}		
	return Local_Value ;
}
