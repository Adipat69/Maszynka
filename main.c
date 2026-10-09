#include <avr/io.h>
#include <util/delay.h>
//BOILER PLATE DO TESTÓW HARDWARE
int main(void)
{
 // DEKLARACJA PORTÓW TUTAJ ZMIENIAĆ
    DDRB |= (1 << PB1) | (1 << PB2); //9 i 10 do LS9110s A i B wejść
  while(1)
  {
{
  //9 wysoki 10 niski
        PORTB |= (1 << PB1);
        PORTB &= ~(1 << PB2);
        _delay_us(10);
  //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
        _delay_us(10);
  //9 niski 10 wysoki
        PORTB &= ~(1 << PB1);
        PORTB |= (1 << PB2);
        _delay_us(10);
  //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
        _delay_us(10);
    }
  }
}
