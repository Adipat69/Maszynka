#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  // init();
  DDRD |= (0xFF); // PD3 Output
  PORTD = 0x01;
  while(1)
  {
    // loop();
  _delay_ms(500);
    PORTD << 1;

  }
}
