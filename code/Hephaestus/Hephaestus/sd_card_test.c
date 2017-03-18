#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
//#include "xitoa.h"
//#include "uart.h"
#include "diskio.h"
#include "ffconf.h"
#include "ff.h"
#include "mmc_avr.h"
//#include "RSXAVRD.h"

int main(void) {

    //AVR_init();
    //DDRD = 0xFF;
    FIL* fp = malloc(sizeof(FIL));
    
    char* path = "filename";
    UINT bytesRead = 0;
    UINT bytesWrite = 0;
    int i;

    
    //FRESULT res;
    FATFS fs;
    //RTC rtc;
    //f_mount(&fs, "0:/", 1);
    DDRB |= 0xF0;
		/* Turn socket power on and wait for 10ms+ (nothing to do if no power controls) */
	// N/a for our design

	/* Configure MOSI/MISO/SCLK/CS pins */
	
    //if(mmc_disk_initialize() == FR_OK){ // changed line in find_volume to call mmc_disk_initialize instead of regular disk_initialize

    //}

    /* Enable SPI module in SPI mode 0 */
    //Enable AVR SPI as Master, SCK as Fosc/64 = 250kHz, SPI mode 0
    
    

    if(f_mount(&fs,"0:/", 1) == FR_OK){
       
        // todo: figure out which FR code is being return by storing result in Var and checking which one is the broken one
    }
    	// ack should mount the drive - not sure how to do this with our SD card

    

    char *toWrite = "Hello World";
    char *toRead = malloc(1000);
    if(f_open(fp, path, FA_READ | FA_WRITE | FA_OPEN_ALWAYS) == FR_OK){
        PORTB = 0xAA;
        if(f_write(fp, toWrite, 11, &bytesWrite) == FR_DISK_ERR){ // write buffer

        }
 
    } /*
    f_lseek(fp, 0); // set pointer to top
    f_read(fp, (void *)toRead, sizeof(toWrite), &bytesRead); // read what we wrote

    if(bytesRead == 0){
       PORTD = 0xBF;
    }
    //DRESULT stat = mmc_disk_write(toWrite, 1, 1); // in theory - this should write the string to the first sector and only the first sector
    //ack can't tell if we need to use mmc functions or can still use regular FatFS api???
    */
    if(f_close(fp) != FR_OK){
    	

    }

    for( ; ; ){

    }
    
    return 0;



}
