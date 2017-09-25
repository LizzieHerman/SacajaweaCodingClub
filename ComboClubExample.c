#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  upLimitSwitch,  sensorTouch)
#pragma config(Motor,  port1,           leftmotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           clawmotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           cranemotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightmotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task bump_off(){
	while(true){
		if(SensorValue(bumpSwitch) == 1){ //check if bumpswitch is pressed
			stopAllTasks();
		}
	}
}

task armDownStop(){
	while(true){
		if(SensorValue(limitSwitch) == 1){ // check if bottom limit switch is pressed
			stopMotor(cranemotor);
		}
	}
}

task armUpStop(){
	while(true){
		if(SensorValue(upLimitSwitch) == 1){ // check if top limit switch is pressed
			stopMotor(cranemotor);
		}
	}
}

task armUp(){
	// make crane rise up when bottom limit switch is pressed
	while(true){
		if(SensorValue(limitSwitch) == 1){ // check if bottom limit switch is pressed
			startMotor(cranemotor, -30);
		}
	}
}

task main()
{
	startTask(bump_off);
	startTask(armDownStop);
	startTask(armUpStop);
	startTask(armUp);
	
	while(true){
		startMotor(leftmotor, -50); //Set the left motor to start going at -50
		startMotor(rightmotor,50); //Set the right motor to start going at 50
		startMotor(cranemotor,30);
		wait10Msec(100); //Let the robot run for 1 second

		//Both the motors stop now
		stopMotor(leftmotor);
		stopMotor(rightmotor);
		stopMotor(cranemotor);

		wait10Msec(100); //wait 1 second
	}
/*bool bob = true;
	int gary = 0;
	while(bob){
	 	gary++;
	 	bob = (gary <= 10000000);
	 	startMotor(leftmotor, -50);
	 	startMotor(rightmotor,50);
	 	//wait1Msec(1);
 }
 	startMotor(leftmotor, -50); //Set the left motor to start going at -50
	startMotor(rightmotor,50); //Set the right motor to start going at 50
	wait10Msec(100); //Let the robot run for 1 second

	//Both the motors stop now
	stopMotor(leftmotor);
	stopMotor(rightmotor);

	startMotor(clawmotor,50); // Start the claw motor at 50
	wait10Msec(50);// Let the robot run for .5 seconds
	stopMotor(clawmotor); // Stop the claw motor


	for(int i = 0; i < 10; i++){ //loop runs 10 times
		startMotor(leftmotor, -50); //Set the left motor to start going at -50
		startMotor(rightmotor,50); //Set the right motor to start going at 50
		wait10Msec(100); //Let the robot run for 1 second

		//Both the motors stop now
		stopMotor(leftmotor);
		stopMotor(rightmotor);

		wait10Msec(100); //wait 1 second
	}

	int i = 0;
	while(i < 10){ // i less than 10
		i++; // i increases by one
		startMotor(rightmotor,50); //Set the right motor to start going at 50
		wait10Msec(100); //Let the robot run for 1 second
		stopMotor(rightmotor); //the right motor stop now
		wait10Msec(100); //wait 1 second
	}*/	
}
