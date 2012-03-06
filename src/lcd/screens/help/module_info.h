/******************************************************************************
 *
 * Help -> Module Info
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

if(lcd_redraw_required()){
	menu_clear(&mainMenu);
	
	lcd_writeText_16x32("Software Ver: "TRAQPAQ_SW_LEVEL_ASCII, FONT_LARGE_POINTER, LCD_MIN_X + 5, LCD_MAX_Y - LCD_TOPBAR_THICKNESS - 36, COLOR_BLACK);
	
	lcd_writeText_16x32("Build Date: "TRAQPAQ_SW_BUILD_DATE, FONT_LARGE_POINTER, LCD_MIN_X + 5, LCD_MAX_Y - LCD_TOPBAR_THICKNESS - 68, COLOR_BLACK);
	
	lcd_writeText_16x32("HW Ver:", FONT_LARGE_POINTER, LCD_MIN_X + 5, LCD_MAX_Y - LCD_TOPBAR_THICKNESS - 100, COLOR_BLACK);
	
	tempString[0] = hexLookup[(dataflashOTP.pcb_rev >> 4) & 0xF];
	tempString[1] = '.';
	tempString[2] = hexLookup[(dataflashOTP.pcb_rev >> 0) & 0xF];
	tempString[3] = NULL;
	lcd_writeText_16x32(&tempString, FONT_LARGE_POINTER, LCD_MIN_X + 133, LCD_MAX_Y - LCD_TOPBAR_THICKNESS - 100, COLOR_BLACK);
	
	lcd_writeText_16x32("S/N:", FONT_LARGE_POINTER, LCD_MIN_X + 5, LCD_MAX_Y - LCD_TOPBAR_THICKNESS - 132, COLOR_BLACK);
	strlcpy(&tempString, &dataflashOTP.serial, OTP_SERIAL_LENGTH);
	lcd_writeText_16x32(&tempString, FONT_LARGE_POINTER, LCD_MIN_X + 85, LCD_MAX_Y - LCD_TOPBAR_THICKNESS - 132, COLOR_BLACK);
	
	lcd_writeText_8x16("Used Memory", FONT_SMALL_POINTER, 50, 50, COLOR_BLACK);
	progressBar = lcd_createProgressBar(50, 50, 350, 25, COLOR_REDLINERED, COLOR_BLACK, COLOR_WHITE);
	dataflash_send_request(DFMAN_REQUEST_USED_SPACE, &responseU8, NULL, NULL, TRUE, 20);
	lcd_updateProgressBar(&progressBar, responseU8);
	
	lcd_redraw_complete();
}

if( xQueueReceive(lcdButtonsManagerQueue, &button, 0) == pdTRUE ){
	switch(button){
		
		// ---------------------------------
		// Short duration button presses
		// ---------------------------------
		case(BUTTON_UP):
			asm("nop");
			break;
			
		case(BUTTON_DOWN):
			asm("nop");
			break;
			
		case(BUTTON_SELECT):
			//lcd_force_redraw();
			//lcd_change_screens( LCDFSM_HELP );
			break;
			
		case(BUTTON_BACK):
			lcd_force_redraw();
			lcd_change_screens( LCDFSM_HELP );
			break;
			
			
		// ---------------------------------
		// Long duration button presses
		// ---------------------------------
		case(BUTTON_LONG_UP):
			asm("nop");
			break;
			
		case(BUTTON_LONG_DOWN):
			asm("nop");
			break;
			
		case(BUTTON_LONG_SELECT):
			asm("nop");
			break;
			
		case(BUTTON_LONG_BACK):
			asm("nop");
			break;
	}
}