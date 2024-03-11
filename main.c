#include <stdint.h>
#include "boardSupport.h"


// background loop
static enum {
	OFF,
	ON
}state = OFF;

int main(void) {
    initValues();
    while (1) {
			switch (state){
				case OFF:
					LedHandleOn(BLUE);
					LedHandleOn(RED);
					delay(100U / 4U);
					state = ON;
					break;
				case ON:
					LedHandleOff(BLUE);
					LedHandleOff(RED);
					delay(100U * 3U / 4U);
					state = OFF;
					break;
			}
			
    }

    //return 0;
	}
