#include <bcm2835.h>
#include <stdio.h>

int led = 14;
int dt = 500;

int main(){
    if (!bcm2835_init()) return 1;

    bcm2835_gpio_fsel(led, BCM2835_GPIO_FSEL_OUTP);
    printf("Hello World");

    while (1){
        bcm2835_gpio_write(led, HIGH);
        bcm2835_delay(dt);
        bcm2835_gpio_write(led, LOW);
        bcm2835_delay(dt);
    }
}