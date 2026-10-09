#include <avr/io.h>
#include <util/delay.h>
///Wszelkie Lewa Zastrzeżone.
///Kod działa. 
/////////////////////////////////
/// Dla 25hz EU to dajemy 10000us
/// Dla 20hz US to dajemy 12500us
/// Nie wiem ile to daje na wyjściu ale dzwoni teraz. 
/// Nie ma co bawić sie w matematyke. 
//////////////////////////////////
int main(void)
{
uint16_t CZAS = 0; ///To nam liczy. Tutaj dla ułatwnienia liczymy w ms. inaczej chyba większa zmienna by sie przdała więc marnujemy miejsce
uint8_t stan = 0; ///0 brak wezwania 1 wezwanie abonenta AVR wspaniały program napisany w 1996 nie wspiera takiej prostej rzeczy jak BOOL czegoś co języki programowania wspierają od 1960
 // DEKLARACJA PORTÓW TUTAJ ZMIENIAĆ
    DDRB |= (1 << PB1) | (1 << PB2); //9 i 10 do LS9110s A i B wejść
 // UWAGA PINY TE MUSZĄ MIEĆ PULLDOWN.
    DDRD &= ~(1 << PD7); ///Pin 7 czyli wejście W wzywanie
    DDRB &= ~(1 << PB0); ///Pin 8 czyli wejście H OffHook/OnHook
 uint16_t Freq = 10000;
/// US uint16_t Freq = 12500;


  while(1)
  {
  sprawdzamy:
        if (PINB & (1 << PB0)) //OffHook
        {
            //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
            CZAS = 0;
            stan = 0;
            goto sprawdzamy;/// wracamy na start
        }

        //Czekamy na robote
        if (stan == 0)
        {
            if (PIND & (1 << PD7)) // OnHook
            {
                stan = 1;          // Dzwonimy
                CZAS = 0;          // Reset zegar
            }
            else
            {
                //Fajrant
             //Stop
        PORTB &= ~((1 << PB1) | (1 << PB2));
                goto sprawdzamy;
            }
        }
    if(stan == 1) //Dzień dobry dzwonimy.
    {
if (CZAS < 2000) ///Czyli 2 sekundy dzwonienia
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
}
