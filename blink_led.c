#include <avr/io.h>
#include <util/delay.h>

int main(){
    DDRB = DDRB | (1 << DDB1);
    DDRB = DDRB | (1 << DDB2);

    while(1){
        PORTB = PORTB | (1 << PORTB1);
        PORTB = PORTB & ~(1 << PORTB2);
        _delay_ms(10000);
        PORTB = PORTB & ~(1 << PORTB1);
        PORTB = PORTB | (1 << PORTB2);
        _delay_ms(10000);
    }

    return 0;
}
