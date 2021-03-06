EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:switches
LIBS:musicbox-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Buzzer BZ1
U 1 1 5987B6DA
P 5700 3100
F 0 "BZ1" H 5850 3150 50  0000 L CNN
F 1 "Buzzer" H 5850 3050 50  0000 L CNN
F 2 "" V 5675 3200 50  0001 C CNN
F 3 "" V 5675 3200 50  0001 C CNN
	1    5700 3100
	1    0    0    -1  
$EndComp
$Comp
L SW_Reed SW2
U 1 1 5987B8FB
P 5800 3450
F 0 "SW2" H 5800 3550 50  0000 C CNN
F 1 "SW_Reed" H 5800 3350 50  0000 C CNN
F 2 "" H 5800 3450 50  0001 C CNN
F 3 "" H 5800 3450 50  0001 C CNN
	1    5800 3450
	1    0    0    -1  
$EndComp
$Comp
L SW_SP3T SW3
U 1 1 5987BAE3
P 5800 2450
F 0 "SW3" H 5800 2650 50  0000 C CNN
F 1 "SW_SP3T" H 5800 2250 50  0000 C CNN
F 2 "" H 5175 2625 50  0001 C CNN
F 3 "" H 5175 2625 50  0001 C CNN
	1    5800 2450
	-1   0    0    -1  
$EndComp
$Comp
L SW_SPST SW1
U 1 1 5987BF47
P 1250 3800
F 0 "SW1" H 1250 3925 50  0000 C CNN
F 1 "SW_SPST" H 1250 3700 50  0000 C CNN
F 2 "" H 1250 3800 50  0001 C CNN
F 3 "" H 1250 3800 50  0001 C CNN
	1    1250 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5987BFFB
P 1850 2900
F 0 "#PWR01" H 1850 2650 50  0001 C CNN
F 1 "GND" H 1850 2750 50  0000 C CNN
F 2 "" H 1850 2900 50  0001 C CNN
F 3 "" H 1850 2900 50  0001 C CNN
	1    1850 2900
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR02
U 1 1 5987D650
P 900 4150
F 0 "#PWR02" H 900 4000 50  0001 C CNN
F 1 "VCC" H 900 4300 50  0000 C CNN
F 2 "" H 900 4150 50  0001 C CNN
F 3 "" H 900 4150 50  0001 C CNN
	1    900  4150
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG03
U 1 1 59880A52
P 2750 1200
F 0 "#FLG03" H 2750 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 2750 1350 50  0000 C CNN
F 2 "" H 2750 1200 50  0001 C CNN
F 3 "" H 2750 1200 50  0001 C CNN
	1    2750 1200
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 59880A72
P 2750 1300
F 0 "#PWR04" H 2750 1150 50  0001 C CNN
F 1 "VCC" H 2750 1450 50  0000 C CNN
F 2 "" H 2750 1300 50  0001 C CNN
F 3 "" H 2750 1300 50  0001 C CNN
	1    2750 1300
	1    0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 59880A96
P 3200 1200
F 0 "#FLG05" H 3200 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 3200 1350 50  0000 C CNN
F 2 "" H 3200 1200 50  0001 C CNN
F 3 "" H 3200 1200 50  0001 C CNN
	1    3200 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 59880AAF
P 3200 1300
F 0 "#PWR06" H 3200 1050 50  0001 C CNN
F 1 "GND" H 3200 1150 50  0000 C CNN
F 2 "" H 3200 1300 50  0001 C CNN
F 3 "" H 3200 1300 50  0001 C CNN
	1    3200 1300
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG07
U 1 1 59880BDC
P 1450 3600
F 0 "#FLG07" H 1450 3675 50  0001 C CNN
F 1 "PWR_FLAG" H 1450 3750 50  0000 C CNN
F 2 "" H 1450 3600 50  0001 C CNN
F 3 "" H 1450 3600 50  0001 C CNN
	1    1450 3600
	1    0    0    -1  
$EndComp
$Comp
L ATTINY45-20PU U1
U 1 1 59972B66
P 3750 3150
F 0 "U1" H 2600 3550 50  0000 C CNN
F 1 "ATTINY45-10PU" H 4750 2750 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 4750 3150 50  0001 C CIN
F 3 "" H 3750 3150 50  0001 C CNN
	1    3750 3150
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR08
U 1 1 599738B9
P 6300 3050
F 0 "#PWR08" H 6300 2800 50  0001 C CNN
F 1 "GND" H 6300 2900 50  0000 C CNN
F 2 "" H 6300 3050 50  0001 C CNN
F 3 "" H 6300 3050 50  0001 C CNN
	1    6300 3050
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 599738FB
P 5300 3650
F 0 "R3" V 5380 3650 50  0000 C CNN
F 1 "R10K" V 5300 3650 50  0000 C CNN
F 2 "" V 5230 3650 50  0001 C CNN
F 3 "" H 5300 3650 50  0001 C CNN
	1    5300 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	900  3800 1050 3800
Wire Wire Line
	2750 1200 2750 1300
Wire Wire Line
	3200 1200 3200 1300
Wire Wire Line
	1450 3600 1450 3800
Wire Wire Line
	900  4150 900  3800
Wire Wire Line
	2400 3400 2400 3800
Connection ~ 2400 3800
Wire Wire Line
	5600 3000 5450 3000
Wire Wire Line
	5450 3000 5450 3200
Wire Wire Line
	5450 3200 5100 3200
Wire Wire Line
	5350 3100 5100 3100
Wire Wire Line
	4950 2450 5600 2450
Wire Wire Line
	5250 2450 5250 3000
Wire Wire Line
	5250 3000 5100 3000
Wire Wire Line
	5600 3450 5300 3450
Wire Wire Line
	5300 3450 5300 3300
Wire Wire Line
	5300 3300 5100 3300
Wire Wire Line
	1850 2900 2400 2900
Wire Wire Line
	5600 3200 5600 3300
Wire Wire Line
	5600 3300 6200 3300
Wire Wire Line
	6200 3300 6200 3050
Connection ~ 6300 3050
Wire Wire Line
	5600 2550 5350 2550
Wire Wire Line
	5350 2550 5350 3100
$Comp
L R R2
U 1 1 59973ACD
P 5500 2750
F 0 "R2" V 5580 2750 50  0000 C CNN
F 1 "R10K" V 5500 2750 50  0000 C CNN
F 2 "" V 5430 2750 50  0001 C CNN
F 3 "" H 5500 2750 50  0001 C CNN
	1    5500 2750
	0    1    1    0   
$EndComp
Connection ~ 5350 2750
$Comp
L GND #PWR09
U 1 1 59973B71
P 4400 2450
F 0 "#PWR09" H 4400 2200 50  0001 C CNN
F 1 "GND" H 4400 2300 50  0000 C CNN
F 2 "" H 4400 2450 50  0001 C CNN
F 3 "" H 4400 2450 50  0001 C CNN
	1    4400 2450
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59973B98
P 4800 2450
F 0 "R1" V 4880 2450 50  0000 C CNN
F 1 "R10K" V 4800 2450 50  0000 C CNN
F 2 "" V 4730 2450 50  0001 C CNN
F 3 "" H 4800 2450 50  0001 C CNN
	1    4800 2450
	0    1    1    0   
$EndComp
Connection ~ 5250 2450
Wire Wire Line
	4650 2450 4400 2450
$Comp
L GND #PWR010
U 1 1 59973D69
P 5150 3650
F 0 "#PWR010" H 5150 3400 50  0001 C CNN
F 1 "GND" H 5150 3500 50  0000 C CNN
F 2 "" H 5150 3650 50  0001 C CNN
F 3 "" H 5150 3650 50  0001 C CNN
	1    5150 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	5450 3450 5450 3650
Connection ~ 5450 3450
Wire Wire Line
	1450 3800 6550 3800
Wire Wire Line
	6000 3800 6000 3450
Wire Wire Line
	6200 3050 6300 3050
Wire Wire Line
	5650 2750 6300 2750
Wire Wire Line
	6300 2750 6300 3050
Wire Wire Line
	6550 3800 6550 2450
Wire Wire Line
	6550 2450 6000 2450
Connection ~ 6000 3800
NoConn ~ 5600 2350
NoConn ~ 5100 3400
NoConn ~ 5100 2900
$EndSCHEMATC
