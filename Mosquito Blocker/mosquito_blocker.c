#include <avr/io.h>
#include <util/delay.h>

#define BUZZER_PORT PORTB
#define BUZZER_DDR DDRB
#define BUZZER_PIN 2

#define MAX_FREQUENCY 1000000000

void my_delay_ms(int ms){
    while (0 < ms){  
      _delay_ms(1);
      --ms;
    }
}

void generate_tone(float frequency, float duration){
     int total_cycles = duration * frequency / 1000;

     for(int i = 0; i < total_cycles; i++){
        my_delay_ms(1000 / (2 * frequency));
        BUZZER_PORT = BUZZER_PORT | (1 << BUZZER_PIN);
        my_delay_ms(1000 / (2 * frequency));
        BUZZER_PORT = BUZZER_PORT & ~(1 << BUZZER_PIN);
     }
}

int main(){
    BUZZER_DDR = BUZZER_DDR | (1 << BUZZER_PIN);

    while(1){
        generate_tone(38000, 50);
        generate_tone(40000, 50);
        generate_tone(44000, 50);
    }
   
    return 0;
}