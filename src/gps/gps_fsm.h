/*
 * gps_fsm.h
 *
 * Created: 7/5/2011 7:52:45 AM
 *  Author: Ryan
 */ 


#ifndef GPS_FSM_H_
#define GPS_FSM_H_

#define GPS_FSM_VERSION						"1.00"

#define GPS_FSM_UNDETERMINED				0

// NMEA Message GGA
#define GPS_FSM_GGA_START					1
#define GPS_FSM_GGA_UTC						2
#define GPS_FSM_GGA_LATITUDE				3
#define GPS_FSM_GGA_LATITUDE_NORS			4
#define GPS_FSM_GGA_LONGITUDE				5
#define GPS_FSM_GGA_LONGITUDE_EORW			6
#define GPS_FSM_GGA_GPS_QUALITY				7
#define GPS_FSM_GGA_SATELLITES				8
#define GPS_FSM_GGA_HDOP					9
#define GPS_FSM_GGA_ALTITUDE				10
#define GPS_FSM_GGA_ALTITUDE_UNITS			11
#define GPS_FSM_GGA_GEOIDAL					12
#define GPS_FSM_GGA_GEOIDAL_UNITS			13
#define GPS_FSM_GGA_DIFF_GPS_DATA_AGE		14
#define GPS_FSM_GGA_DIFF_STATION_ID			15


// NMEA Message GSA
#define GPS_FSM_GSA_START					16
#define GPS_FSM_GSA_MODE					17
#define GPS_FSM_GSA_CURRENT_MODE			18
#define GPS_FSM_GSA_PRN_SAT1				19
#define GPS_FSM_GSA_PRN_SAT2				20
#define GPS_FSM_GSA_PRN_SAT3				21
#define GPS_FSM_GSA_PRN_SAT4				22
#define GPS_FSM_GSA_PRN_SAT5				23
#define GPS_FSM_GSA_PRN_SAT6				24
#define GPS_FSM_GSA_PRN_SAT7				25
#define GPS_FSM_GSA_PRN_SAT8				26
#define GPS_FSM_GSA_PRN_SAT9				27
#define GPS_FSM_GSA_PRN_SAT10				28
#define GPS_FSM_GSA_PRN_SAT11				29
#define GPS_FSM_GSA_PRN_SAT12				30
#define GPS_FSM_GSA_PDOP					31
#define GPS_FSM_GSA_HDOP					32
#define GPS_FSM_GSA_VDOP					33


// NMEA Message RMC
#define GPS_FSM_RMC_START					34
#define GPS_FSM_RMC_UTC						35
#define GPS_FSM_RMC_STATUS					36
#define GPS_FSM_RMC_LATITUDE				37
#define GPS_FSM_RMC_LATITUDE_NORS			38
#define GPS_FSM_RMC_LONGITUDE				39
#define GPS_FSM_RMC_LONGITUDE_EORW			40
#define GPS_FSM_RMC_SPEED					41
#define GPS_FSM_RMC_TRACK					42
#define GPS_FSM_RMC_DATE					43
#define GPS_FSM_RMC_MAG_VARIATION			44
#define GPS_FSM_RMC_MAG_VARIATION_EORW		45

#define GPS_FSM_CHECKSUM					46


#endif /* GPS_FSM_H_ */