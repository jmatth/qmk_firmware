/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "phantom.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    led_init_ports();
    matrix_init_user();
    phantom_blink_all_leds();

    // Should always come last
    matrix_init_user();
};

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

void led_init_ports(void) {
    DDRB |= (1<<6) | (1<<7); // OUT
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK))
    {
        PORTB |= (1<<6); // HI
    }
    else
    {
        PORTB &= ~(1<<6); // LO
    }

    if (usb_led & (1<<USB_LED_SCROLL_LOCK))
    {
        PORTB |= (1<<7); // HI
    }
    else
    {
        PORTB &= ~(1<<7); // LO
    }

    led_set_user(usb_led);
}

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
