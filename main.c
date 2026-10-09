#include <avr/io.h>
#include <util/delay.h>
//BOILER PLATE DO TESTÓW HARDWARE
/////////////////////////////////
///Dla sinusa 
////Vout=Vpeak*Pierwiastek(Ton/Thalf)
///Toteż Ton=thalf*(Vout/Vpeak)^2
///Toff = Thalf-Ton
//////////////////////////////////
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
        _delay_us(4600);
  //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
        _delay_us(4600);
  //9 niski 10 wysoki
        PORTB &= ~(1 << PB1);
        PORTB |= (1 << PB2);
        _delay_us(4600);
  //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
        _delay_us(4600);
    }
  }
}
