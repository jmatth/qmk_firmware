#include "phantom.h"
#include "led.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    led_init_ports();
    phantom_blink_all_leds();

    // Should always come last
    matrix_init_user();
};

void phantom_blink_all_leds(void)
{
    phantom_led_all_off();
    phantom_led_l_on();
    _delay_ms(100);
    phantom_led_r_on();
    _delay_ms(100);
    phantom_led_l_off();
    _delay_ms(100);
    /* phantom_led_r_off(); */
    /* _delay_ms(100); */
    /* phantom_led_r_on(); */
    /* _delay_ms(100); */
    phantom_led_l_on();
    _delay_ms(100);
    phantom_led_r_off();
    _delay_ms(100);
    phantom_led_l_off();
    //ergodox_led_all_on();
    //_delay_ms(333);
    phantom_led_all_off();
}
