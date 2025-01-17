//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - 
//Global symbols

/////////
//max time of any servo or esc used
#define MAX_SERVO_CYCLE_SHIM "426,\0"



/////////
//prompt with times, states, and other useful messages
#define DEBUG_LEVEL_0
//warnings from the code about corrections, roll-overs, and limits
#define DEBUG_LEVEL_1

/////////
//To read status witout the LCD lid open:
//Note: on a Eee G2 it will consume 2% CPU time.
//every 5 seconds report robot and laptop power status using the speaker
//to install run> sudo apt-get flite
//to enable uncomment the next line:
//#define fliteTTSvoiceEnable

//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
//Profile: Duratrax (a.k.a. Quartz)
//Drive: Duratrax Sprint2 ESC w/reverse
//NOTE: Auto-set feature for ESC programming (there is no [Set] button on the unit). 
//   When Sprint2 ESC is powered on it activates an auto-setting mode for 2 seconds 
//   (Green light will blink while waiting.)
//   Therefore one must send the SERVO STOP signal for at least 2 seconds to
//   finish the ESC setup.	
#if defined(duratrax)
#define ROBOT_ID_NAME "duratrax"

//Battery pack installed on robot
#define BATTERY_TYPE VENOM_4600 

//after one module is found abort scan
#define HALT_PROBE_AFTER_FIRST_MODULE_FOUND

//Duratrax has an automatic setup and MUST run the auto-config
#define MOTOR_DRIVE_SERVO_ESC_CONFIG 1
//Duratrax has an automatic ESC setup and will NEVER use the manual config
#define MOTOR_DRIVE_SERVO_ESC_MANUAL_CONFIG_SWEEP 0
/////////
//This offset prevents some of the the ESC from locking the brakes (no remote is this precise)
//*** ONE MUST ALWAYS BRING THE ESC TO THE SERVO_STOP MODE BEFORE CHANGING DIRECTION ***
#define MOTOR_DRIVE_SERVO_BRAKE_SHIM 4


#define MOTOR_DRIVE_SERVO_STOP 241
#define MOTOR_DRIVE_SERVO_MAX_FWD 340
#define MOTOR_DRIVE_SERVO_MAX_REV 190 

//Steer Servo: TACTIC TSX200
#define MOTOR_STEER_SERVO_CENTER 300
#define MOTOR_STEER_SERVO_MAX_RIGHT 380
#define MOTOR_STEER_SERVO_MAX_LEFT 230 
//abstract input for steering should NOT be inverted  (1)
#define STEER_ANGLE_INVERTED 1
#define THROTTLE_CONTROL_INVERTED 1

//Steer  Servo: Hobbico CS-60 HCAM0149 Command CS-60 Standard Sport Servo
//#define MOTOR_STEER_SERVO_CENTER 250
//#define MOTOR_STEER_SERVO_MAX_RIGHT 190
//#define MOTOR_STEER_SERVO_MAX_LEFT  340 

///////////////////////////////////////////////////////////
//The IR grade system angles in degreees:
#define IR_distances_top_angle_center_deviation_Theta 30.0
#define IR_distances_top_angle_center_deviation_Theta_Not 30.0
#define IR_distances_vertical_angle_difference_Ef 15.0

///////////////////////////////////////////////////////////
//Sonar BUS ID are configured for the Physical IO divice, and not the abstract device IDs.
//NOTE: MAKE SURE ONLY 1 SONAR IS PLUGGED IN to the i2c bus when assigning (17-33)
// 1-16 are valid IDs   (0 is disabled)
#define FURIOUS_SONAR_PING_FRONT_LEFT_BUSID 14
#define FURIOUS_SONAR_PING_FRONT_RIGHT_BUSID 15
#define FURIOUS_SONAR_PING_FRONT_MID_BUSID 16
#define FURIOUS_SONAR_PING_REAR_BUSID 13

///////////////////////////////////////////////////////////
//Physical guides
#define MAX_VELOCITY_IN_METERS_PER_SECOND 1.0
#define MAX_ACCELERATION_IN_METERS_PER_SECOND_PER_SECOND 1.0
#define TIRE_ROTATIONS_PER_METER 4.0

//create a standard throttle translation (0-100% -> some servo value)
	#if (MOTOR_DRIVE_SERVO_STOP > MOTOR_DRIVE_SERVO_MAX_FWD)
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_FWD)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_REV-MOTOR_DRIVE_SERVO_STOP)/100.0)
	#else
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_FWD-MOTOR_DRIVE_SERVO_STOP)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_REV)/100.0)
	#endif

///////////////////////////////////////////////////////////////
//Camera PAN/YAW and TILT/PITCH turret config
#define TURRET_ENABLED "trossenrobotics.com::RK-PT-400"

//YAW servo=Deluxe Hitec HS-322HD 
#define TURRET_SERVO_MAX_YAW 425
#define TURRET_YAW_SERVO_CENTER 260
#define TURRET_SERVO_MIN_YAW 105
//
//PITCH servo=Deluxe Hitec HS-322HD  (will be some skew for each robot's turret)
#define TURRET_SERVO_MAX_PITCH 425
#define TURRET_PITCH_SERVO_CENTER 270
#define TURRET_SERVO_MIN_PITCH 105
//note the true min 105 needs offset to prevent robot scraping the deck with turret
//
//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define TURRET_YAW_FORDWARD_INDEX ((TURRET_SERVO_MAX_YAW-TURRET_YAW_SERVO_CENTER)/100.0)
#define TURRET_YAW_BACKWARD_INDEX ((TURRET_YAW_SERVO_CENTER-TURRET_SERVO_MIN_YAW)/100.0)
#define TURRET_PITCH_FORDWARD_INDEX ((TURRET_SERVO_MAX_PITCH-TURRET_PITCH_SERVO_CENTER)/100.0)
#define TURRET_PITCH_BACKWARD_INDEX ((TURRET_PITCH_SERVO_CENTER-TURRET_SERVO_MIN_PITCH)/100.0)


///////////////////////////////////////////////////////////////
//Optics filter arm
#define OPTICS_FILTER_ARM_SERVO_MIN 97
#define OPTICS_FILTER_ARM_SERVO_MAX 340
#define OPTICS_FILTER_ARM_SERVO_CENTER 150

//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define OPTICS_FILTER_ARM_FORDWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_MAX-OPTICS_FILTER_ARM_SERVO_CENTER)/100.0)
#define OPTICS_FILTER_ARM_BACKWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_CENTER-OPTICS_FILTER_ARM_SERVO_MIN)/100.0) 
//--------------------- 

//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
//Profile: Traxxas 
//Drive: Traxxas XL5 ESC (Press button on ESC until green light blinks once, and then off)
#elif defined(traxxas) 
#define ROBOT_ID_NAME "traxxas"

//Battery pack installed on robot
#define BATTERY_TYPE VENOM_4600  

//after one module is found abort scan
#define HALT_PROBE_AFTER_FIRST_MODULE_FOUND

//Seems to work without this setup init
#define MOTOR_DRIVE_SERVO_ESC_CONFIG 1
//ESC is setup to defaults (may be needed if a new unit is used)
#define MOTOR_DRIVE_SERVO_ESC_MANUAL_CONFIG_SWEEP 0
/////////
//This offset prevents some of the the ESC from locking the brakes (no remote is this precise)
//*** ONE MUST ALWAYS BRING THE ESC TO THE SERVO_STOP MODE BEFORE CHANGING DIRECTION ***
#define MOTOR_DRIVE_SERVO_BRAKE_SHIM 4

//BlackThrottle: 300A ESC  (98A hexfet brushed driver from china)
#define MOTOR_DRIVE_SERVO_STOP 250
#define MOTOR_DRIVE_SERVO_MAX_FWD  160
#define MOTOR_DRIVE_SERVO_MAX_REV  360

//#define MOTOR_DRIVE_SERVO_MAX_FWD  210
//#define MOTOR_DRIVE_SERVO_MAX_REV  310


//OEM yellow Throttle: Stampede XL-5 2055 ESC
//#define MOTOR_DRIVE_SERVO_STOP 300
//#define MOTOR_DRIVE_SERVO_MAX_FWD 370
//#define MOTOR_DRIVE_SERVO_MAX_REV 250 

/* These steering values are calibrated for Snowflurry 3.  To
   calibrate for your chassis, comment these out and add your
   own below.
*/
//Steer: Stampede XL-5 2055 Servo
#define MOTOR_STEER_SERVO_CENTER 270
#define MOTOR_STEER_SERVO_MAX_RIGHT 355 
#define MOTOR_STEER_SERVO_MAX_LEFT 185

//abstract input for steering should be inverted  (-1)
#define STEER_ANGLE_INVERTED 1
#define THROTTLE_CONTROL_INVERTED -1


/////////////////
//The IR grade system angles in degreees:
#define IR_distances_top_angle_center_deviation_Theta 30.0
#define IR_distances_top_angle_center_deviation_Theta_Not 30.0
#define IR_distances_vertical_angle_difference_Ef 15.0

/////////////////
//Physical guides
#define MAX_VELOCITY_IN_METERS_PER_SECOND 1.0
#define MAX_ACCELERATION_IN_METERS_PER_SECOND_PER_SECOND 1.0
#define TIRE_ROTATIONS_PER_METER 3.0

/////////////////
//Sonar BUS ID are configured for the Physical IO divice, and not the abstract device IDs.
//NOTE: MAKE SURE ONLY 1 SONAR IS PLUGGED IN to the i2c bus when assigning (17-33)
// 1-16 are valid IDs   (0 is disabled) 
#define FURIOUS_SONAR_PING_FRONT_LEFT_BUSID 8
#define FURIOUS_SONAR_PING_FRONT_RIGHT_BUSID 9
#define FURIOUS_SONAR_PING_FRONT_MID_BUSID 1
#define FURIOUS_SONAR_PING_REAR_BUSID 2


//create a standard throttle translation (0-100% -> some servo value)
	#if (MOTOR_DRIVE_SERVO_STOP > MOTOR_DRIVE_SERVO_MAX_FWD)
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_FWD)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_REV-MOTOR_DRIVE_SERVO_STOP)/100.0)
	#else
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_FWD-MOTOR_DRIVE_SERVO_STOP)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_REV)/100.0)
	#endif

/////////////////////
//Camera PAN/YAW and TILT/PITCH turret config
#define TURRET_ENABLED "trossenrobotics.com::RK-PT-400"

//YAW servo=Deluxe Hitec HS-322HD 
#define TURRET_SERVO_MAX_YAW 425
#define TURRET_YAW_SERVO_CENTER 250
#define TURRET_SERVO_MIN_YAW 105
//
//PITCH servo=Deluxe Hitec HS-322HD  (will be some skew for each robot's turret)
#define TURRET_SERVO_MAX_PITCH 425
#define TURRET_PITCH_SERVO_CENTER 380 
#define TURRET_SERVO_MIN_PITCH 370
//note the true min 105 needs offset to prevent robot scraping the deck with turret
//
//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define TURRET_YAW_FORDWARD_INDEX ((TURRET_SERVO_MAX_YAW-TURRET_YAW_SERVO_CENTER)/100.0)
#define TURRET_YAW_BACKWARD_INDEX ((TURRET_YAW_SERVO_CENTER-TURRET_SERVO_MIN_YAW)/100.0)
#define TURRET_PITCH_FORDWARD_INDEX ((TURRET_SERVO_MAX_PITCH-TURRET_PITCH_SERVO_CENTER)/100.0)
#define TURRET_PITCH_BACKWARD_INDEX ((TURRET_PITCH_SERVO_CENTER-TURRET_SERVO_MIN_PITCH)/100.0)
//--------------------- 

///////////////////////////////////////////////////////////////
//Optics filter arm
#define OPTICS_FILTER_ARM_SERVO_MIN 97
#define OPTICS_FILTER_ARM_SERVO_MAX 340
#define OPTICS_FILTER_ARM_SERVO_CENTER 150

//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define OPTICS_FILTER_ARM_FORDWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_MAX-OPTICS_FILTER_ARM_SERVO_CENTER)/100.0)
#define OPTICS_FILTER_ARM_BACKWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_CENTER-OPTICS_FILTER_ARM_SERVO_MIN)/100.0) 
//--------------------- 

//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
//Profile: Snowtires (Matt's platform) 
//Drive: Traxxas XL5 ESC (Press button on ESC until green light blinks once, and then off)
#elif defined(snowtires) 
#define ROBOT_ID_NAME "snowtires"

//Battery pack installed on robot
#define BATTERY_TYPE VENOM_4600  

//after one module is found abort scan
#define HALT_PROBE_AFTER_FIRST_MODULE_FOUND

//Seems to work without this setup init
#define MOTOR_DRIVE_SERVO_ESC_CONFIG 1
//ESC is setup to defaults (may be needed if a new unit is used)
#define MOTOR_DRIVE_SERVO_ESC_MANUAL_CONFIG_SWEEP 0
/////////
//This offset prevents some of the the ESC from locking the brakes (no remote is this precise)
//*** ONE MUST ALWAYS BRING THE ESC TO THE SERVO_STOP MODE BEFORE CHANGING DIRECTION ***
#define MOTOR_DRIVE_SERVO_BRAKE_SHIM 4

//BlackThrottle: 300A ESC  (98A hexfet brushed driver from china)
//#define MOTOR_DRIVE_SERVO_STOP 250
//#define MOTOR_DRIVE_SERVO_MAX_FWD  160
//#define MOTOR_DRIVE_SERVO_MAX_REV  360

//#define MOTOR_DRIVE_SERVO_MAX_FWD  210
//#define MOTOR_DRIVE_SERVO_MAX_REV  310


//OEM yellow Throttle: Stampede XL-5 2055 ESC
#define MOTOR_DRIVE_SERVO_STOP 250
#define MOTOR_DRIVE_SERVO_MAX_FWD 300
#define MOTOR_DRIVE_SERVO_MAX_REV 105 

/* These steering values are calibrated for Snowflurry 3.  To
   calibrate for your chassis, comment these out and add your
   own below.
*/
//Steer: Futaba 3010 high Torque Servo SERVO LEFT = STEERING RIGHT!!!!
#define MOTOR_STEER_SERVO_CENTER 245
#define MOTOR_STEER_SERVO_MAX_RIGHT 290
#define MOTOR_STEER_SERVO_MAX_LEFT 190

//abstract input for steering should be inverted  (-1)
#define STEER_ANGLE_INVERTED -1
#define THROTTLE_CONTROL_INVERTED 1


/////////////////
//The IR grade system angles in degreees:
#define IR_distances_top_angle_center_deviation_Theta 30.0
#define IR_distances_top_angle_center_deviation_Theta_Not 30.0
#define IR_distances_vertical_angle_difference_Ef 15.0

/////////////////
//Physical guides
#define MAX_VELOCITY_IN_METERS_PER_SECOND 1.0
#define MAX_ACCELERATION_IN_METERS_PER_SECOND_PER_SECOND 1.0
#define TIRE_ROTATIONS_PER_METER 3.0

/////////////////
//Sonar BUS ID are configured for the Physical IO divice, and not the abstract device IDs.
//NOTE: MAKE SURE ONLY 1 SONAR IS PLUGGED IN to the i2c bus when assigning (17-33)
// 1-16 are valid IDs   (0 is disabled) 
#define FURIOUS_SONAR_PING_FRONT_LEFT_BUSID 0
#define FURIOUS_SONAR_PING_FRONT_RIGHT_BUSID 0
#define FURIOUS_SONAR_PING_FRONT_MID_BUSID 0
#define FURIOUS_SONAR_PING_REAR_BUSID 0


//create a standard throttle translation (0-100% -> some servo value)
	#if (MOTOR_DRIVE_SERVO_STOP > MOTOR_DRIVE_SERVO_MAX_FWD)
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_FWD)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_REV-MOTOR_DRIVE_SERVO_STOP)/100.0)
	#else
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_FWD-MOTOR_DRIVE_SERVO_STOP)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_REV)/100.0)
	#endif

/////////////////////
//Camera PAN/YAW and TILT/PITCH turret config
#define TURRET_ENABLED "trossenrobotics.com::RK-PT-400"

//YAW servo=Deluxe Hitec HS-322HD 
#define TURRET_SERVO_MAX_YAW 420
#define TURRET_YAW_SERVO_CENTER 255
#define TURRET_SERVO_MIN_YAW 120
//
//PITCH servo=Deluxe Hitec HS-322HD  (will be some skew for each robot's turret)
#define TURRET_SERVO_MAX_PITCH 420
#define TURRET_PITCH_SERVO_CENTER 240 
#define TURRET_SERVO_MIN_PITCH 230
//note the true min 105 needs offset to prevent robot scraping the deck with turret
//
//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define TURRET_YAW_FORDWARD_INDEX ((TURRET_SERVO_MAX_YAW-TURRET_YAW_SERVO_CENTER)/100.0)
#define TURRET_YAW_BACKWARD_INDEX ((TURRET_YAW_SERVO_CENTER-TURRET_SERVO_MIN_YAW)/100.0)
#define TURRET_PITCH_FORDWARD_INDEX ((TURRET_SERVO_MAX_PITCH-TURRET_PITCH_SERVO_CENTER)/100.0)
#define TURRET_PITCH_BACKWARD_INDEX ((TURRET_PITCH_SERVO_CENTER-TURRET_SERVO_MIN_PITCH)/100.0)
//--------------------- 

///////////////////////////////////////////////////////////////
//Optics filter arm
#define OPTICS_FILTER_ARM_SERVO_MIN 97
#define OPTICS_FILTER_ARM_SERVO_MAX 340
#define OPTICS_FILTER_ARM_SERVO_CENTER 150

//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define OPTICS_FILTER_ARM_FORDWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_MAX-OPTICS_FILTER_ARM_SERVO_CENTER)/100.0)
#define OPTICS_FILTER_ARM_BACKWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_CENTER-OPTICS_FILTER_ARM_SERVO_MIN)/100.0) 
//--------------------- 

//-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
//Profile: Snowfury 
//Drive: TAMIYA  TEU-101BK FET Speed control
#elif defined(snowfury)
#define ROBOT_ID_NAME "snowfury"



//Battery pack installed on robot
#define BATTERY_TYPE VENOM_4600 


//after one module is found abort scan
#define HALT_PROBE_AFTER_FIRST_MODULE_FOUND

//This sets the platform into a default mode
#define MOTOR_DRIVE_SERVO_ESC_CONFIG 1
//The Snowfury ESC may need a MANUAL-setup... set to 1 to set a new configuration
#define MOTOR_DRIVE_SERVO_ESC_MANUAL_CONFIG_SWEEP 0
/////////
//This offset prevents some of the the ESC from locking the brakes (no remote is this precise)
//*** ONE MUST ALWAYS BRING THE ESC TO THE SERVO_STOP MODE BEFORE CHANGING DIRECTION ***
#define MOTOR_DRIVE_SERVO_BRAKE_SHIM 4

//#define MOTOR_DRIVE_SERVO_STOP 285
//#define MOTOR_DRIVE_SERVO_MAX_FWD 370 
//#define MOTOR_DRIVE_SERVO_MAX_REV 235

#define MOTOR_DRIVE_SERVO_STOP 275
#define MOTOR_DRIVE_SERVO_MAX_FWD 370 
#define MOTOR_DRIVE_SERVO_MAX_REV 180


//Steer: Futaba S3003 OLD-STYLE Servo
#define MOTOR_STEER_SERVO_CENTER 302
#define MOTOR_STEER_SERVO_MAX_LEFT 235
#define MOTOR_STEER_SERVO_MAX_RIGHT 352

//abstract input for steering should NOT be inverted  (1)
#define STEER_ANGLE_INVERTED 1
#define THROTTLE_CONTROL_INVERTED -1


/////////////////
//The IR grade system angles in degreees:
#define IR_distances_top_angle_center_deviation_Theta 30.0
#define IR_distances_top_angle_center_deviation_Theta_Not 30.0
#define IR_distances_vertical_angle_difference_Ef 15.0

/////////////////
//Sonar BUS ID are configured for the Physical IO divice, and not the abstract device IDs.
//NOTE: MAKE SURE ONLY 1 SONAR IS PLUGGED IN to the i2c bus when assigning (17-33)
// 1-16 are valid IDs   (0 is disabled) 
#define FURIOUS_SONAR_PING_FRONT_LEFT_BUSID 1
#define FURIOUS_SONAR_PING_FRONT_RIGHT_BUSID 2
#define FURIOUS_SONAR_PING_FRONT_MID_BUSID 3
#define FURIOUS_SONAR_PING_REAR_BUSID 4

/////////////////
//Physical guides
#define MAX_VELOCITY_IN_METERS_PER_SECOND 1.0
#define MAX_ACCELERATION_IN_METERS_PER_SECOND_PER_SECOND 1.0
#define TIRE_ROTATIONS_PER_METER 5.0

//create a standard throttle translation (0-100% -> some servo value)
	#if (MOTOR_DRIVE_SERVO_STOP > MOTOR_DRIVE_SERVO_MAX_FWD)
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_FWD)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_REV-MOTOR_DRIVE_SERVO_STOP)/100.0)
	#else
		#define THROTTLE_FORDWARD_INDEX ((MOTOR_DRIVE_SERVO_MAX_FWD-MOTOR_DRIVE_SERVO_STOP)/100.0)
		#define THROTTLE_BACKWARD_INDEX ((MOTOR_DRIVE_SERVO_STOP-MOTOR_DRIVE_SERVO_MAX_REV)/100.0)
	#endif
	
/////////////////////
//Camera PAN/YAW and TILT/PITCH turret config
#define TURRET_ENABLED "trossenrobotics.com::RK-PT-400"

//YAW servo=Deluxe Hitec HS-322HD 
#define TURRET_SERVO_MAX_YAW 425
#define TURRET_YAW_SERVO_CENTER 250
#define TURRET_SERVO_MIN_YAW 105
//
//PITCH servo=Deluxe Hitec HS-322HD  (will be some skew for each robot's turret)
#define TURRET_SERVO_MAX_PITCH 425
#define TURRET_PITCH_SERVO_CENTER 380 
#define TURRET_SERVO_MIN_PITCH 370
//note the true min 105 needs offset to prevent robot scraping the deck with turret
//
//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define TURRET_YAW_FORDWARD_INDEX ((TURRET_SERVO_MAX_YAW-TURRET_YAW_SERVO_CENTER)/100.0)
#define TURRET_YAW_BACKWARD_INDEX ((TURRET_YAW_SERVO_CENTER-TURRET_SERVO_MIN_YAW)/100.0)
#define TURRET_PITCH_FORDWARD_INDEX ((TURRET_SERVO_MAX_PITCH-TURRET_PITCH_SERVO_CENTER)/100.0)
#define TURRET_PITCH_BACKWARD_INDEX ((TURRET_PITCH_SERVO_CENTER-TURRET_SERVO_MIN_PITCH)/100.0)
//--------------------- 
	
///////////////////////////////////////////////////////////////
//Optics filter arm
#define OPTICS_FILTER_ARM_SERVO_MIN 97
#define OPTICS_FILTER_ARM_SERVO_MAX 340
#define OPTICS_FILTER_ARM_SERVO_CENTER 150

//create a standard translation (0-100% -> some servo value)
//Note: true settings for min, max, and center will show servo is non-linear
#define OPTICS_FILTER_ARM_FORDWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_MAX-OPTICS_FILTER_ARM_SERVO_CENTER)/100.0)
#define OPTICS_FILTER_ARM_BACKWARD_INDEX ((OPTICS_FILTER_ARM_SERVO_CENTER-OPTICS_FILTER_ARM_SERVO_MIN)/100.0) 
//--------------------- 
	
#endif
