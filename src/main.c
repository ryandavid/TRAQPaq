/******************************************************************************
 *
 * Main Application for traq|paq
 *
 * - Compiler:          GNU GCC for AVR32
 * - Supported devices: traq|paq hardware version 1.1
 * - AppNote:			N/A
 *
 * - Last Author:		Ryan David ( ryan.david@redline-electronics.com )
 *
 *
 * Copyright (c) 2012 Redline Electronics LLC.
 *
 * This file is part of traq|paq.
 *
 * traq|paq is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * traq|paq is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with traq|paq. If not, see http://www.gnu.org/licenses/.
 *
 ******************************************************************************/
#include "asf.h"
#include "drivers.h"

// ------------------------------------------------------------
// Main
// ------------------------------------------------------------
int main( void ){
	unsigned short temp = 0;
	
	wdt_disable();
	
	// Initialization ---------------------------------------------
	Disable_global_exception();
	Disable_global_interrupt();
	
	INTC_init_interrupts();
	board_init();
	
	// Check to see if we got reset from a watchdog timeout
	if( wdt_triggered() ){
		debug_log("WARNING [WDT]: Recovering from watchdog reset!");
	}
	
	if( !gpio_get_pin_value(GPIO_BUTTON2) ){
		debug_log("INFO [PM]: Powered on via USB");
	}
	
	// Schedule Tasks ---------------------------------------------
	#if( TRAQPAQ_HW_SPI_ENABLED )
	dataflash_task_init();
	#endif
	
	#if( TRAQPAQ_HW_EBI_ENABLED )
	lcd_task_init();
	#endif
		
	#if( TRAQPAQ_HW_PWM_ENABLED )
	pwm_task_init();
	#endif
	
	#if( TRAQPAQ_HW_USB_ENABLED )
	usb_task_init();
	#endif
	
	#if( TRAQPAQ_HW_TWI_ENABLED )
	fuel_task_init();
	#endif
	
	#if( TRAQPAQ_HW_GPS_ENABLED )
	gps_task_init();
	#else
	// Kick the GPS out of reset so we can use it for external datalogging
	gpio_set_gpio_pin(GPS_RESET);
	#endif
	
	#if( TRAQPAQ_HW_EXINT_ENABLED )
	buttons_task_init();
	// If switches are enabled, then keep the main power supply on!
	gpio_set_gpio_pin(PM_ENABLE);
	#endif
	
	#if( TRAQPAQ_HW_CHARGE_ENABLED )
	charge_task_init();
	#endif
	
	#if( TRAQPAQ_HW_ADC_ENABLED )
	adc_task_init();
	#endif
	
	#if( TRAQPAQ_HW_WDT_ENABLED )
	wdt_task_init();
	#endif
	
	Enable_global_interrupt();

	// Start the scheduler! ---------------------------------------
	vTaskStartScheduler();
	
	debug_log("CRITICAL [RTOS]: Scheduler has ended");
	
	// Should never reach this!
	while (true){
		asm("nop");
	};			
}