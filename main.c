#include <avr/io.h>
#include <util/delay.h>
//BOILER PLATE DO TESTÓW HARDWARE
/////////////////////////////////
/// Dla 25hz EU to dajemy 10000us
/// Dla 20hz US to dajemy 12500us
/// Nie wiem ile to daje na wyjściu ale dzwoni teraz. 
/// Nie ma co bawić sie w matematyke. 
//////////////////////////////////
int main(void)
{
int16_t CZAS = 0; ///To nam liczy. Tutaj dla ułatwnienia liczymy w ms. inaczej chyba większa zmienna by sie przdała więc marnujemy miejsce
 // DEKLARACJA PORTÓW TUTAJ ZMIENIAĆ
    DDRB |= (1 << PB1) | (1 << PB2); //9 i 10 do LS9110s A i B wejść

 uint16_t Freq = 10000;
/// US uint16_t Freq = 12500;


  while(1)
  {
if (CZAS < 2000) ///Czyli 2 sekundy
{
  //9 wysoki 10 niski
        PORTB |= (1 << PB1);
        PORTB &= ~(1 << PB2);
        _delay_us(Freq);
  //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
        _delay_us(Freq);
  //9 niski 10 wysoki
        PORTB &= ~(1 << PB1);
        PORTB |= (1 << PB2);
        _delay_us(Freq);
  //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
        _delay_us(Freq);
  CZAS = CZAS + 4 * Freq / 1000; ///Czas 4 korków i na ms
    }
    else ///Ponad 2s
        {
            ///Stop 
            PORTB &= ~((1 << PB1) | (1 << PB2));
            _delay_ms(4000); ///Czekaj 4s
            CZAS = 0; ///Wracaj na start
        }
  }
}
