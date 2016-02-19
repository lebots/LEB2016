#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    deeznutz,       sensorLineFollower)
#pragma config(Sensor, dgtl2,  leftShooter,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightShooter,   sensorQuadEncoder)
#pragma config(Sensor, dgtl12, piston,         sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           liftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           launcherL1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           launcherL2,    tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port4,           launcherR1,    tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port5,           launcherR2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           frMotor,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           blMotor,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           flMotor,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           brMotor,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          intakeMotor,   tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Competition stuff
#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(115)
#include "Vex_Competition_Includes.c"

// Include auton files
#include ".\auton\auton1.h"

bool shooterBool = false;
int shootSpeed = 0;
float driveMultiplier = 1;
float shotMultiplier;
long leftSpeed;
long rightSpeed;

float kP = 2;


void launcher(int targetRPM, int shooterBool) {

	int leftError = targetRPM - (getMotorVelocity(launcherL2) * 1);
	int rightError = targetRPM - (getMotorVelocity(launcherR1) * 1);

	if (abs(leftError) < 5) leftError = 0;
	if (abs(rightError) < 5) leftError = 0;

	leftSpeed = targetRPM + (leftError * kP);
	rightSpeed = targetRPM + (rightError * kP);

	if (leftSpeed < 0) leftSpeed = 0;
	if (leftSpeed > 127) leftSpeed = 127;
	if (rightSpeed < 0) rightSpeed = 0;
	if (rightSpeed > 127) rightSpeed = 127;

	leftSpeed = (leftSpeed + rightSpeed) / 2;

	// Reset timer for ball launch
	if (SensorValue(deeznutz) < 2000)
		clearTimer(timer1);

	// Ramp up speed once ball goes through flywheels
	if (time1[timer1] >= 200 && time1[timer1] < 750)
		leftSpeed = leftSpeed * 1.1;
	else
		leftSpeed = leftSpeed;

	// Set motor powers
	motor[launcherL1] = leftSpeed * shooterBool;
	motor[launcherL2] = leftSpeed * shooterBool;
	motor[launcherR1] = leftSpeed * shooterBool;
	motor[launcherR2] = leftSpeed * shooterBool;

}

void pre_auton() {

}

task autonomous() {
	auton1();
}

task usercontrol() {
	while (true) { // Btn6U = slow, Btn5U = super slow
		driveMultiplier = vexRT[Btn6U] ? 0.4 : (vexRT[Btn5U] ? 0.25 : 1);

		motor[flMotor] = driveMultiplier * vexRT[Ch3];
		motor[blMotor] = driveMultiplier * vexRT[Ch3];
		motor[frMotor] = driveMultiplier * vexRT[Ch2];
		motor[brMotor] = driveMultiplier * vexRT[Ch2];

		if (vexRT[Btn7LXmtr2]) { // Full court
			shooterBool = true;
			shotMultiplier = 100;
		}
		if (vexRT[Btn8RXmtr2]) { // 3/4 court
			shooterBool = true;
			shotMultiplier = 47.5;
		}
		if (vexRT[Btn7UXmtr2]) { // Half court
			shooterBool = true;
			shotMultiplier = 35;
		}
		if (vexRT[Btn8UXmtr2]) { // Quarter court
			shooterBool = true;
			shotMultiplier = 33;
		}
		if (vexRT[Btn7DXmtr2] || vexRT[Btn8DXmtr2]) // Stop flywheels
			shooterBool = false;

		launcher(shotMultiplier, shooterBool);

		// Lift motor and intake motor
		motor[liftMotor] = 127 * (vexRT[Btn5UXmtr2] - vexRT[Btn5DXmtr2]);
		motor[intakeMotor] = 127 * (vexRT[Btn6DXmtr2] - vexRT[Btn6UXmtr2]);

		// Piston to keep balls from flywheels
		SensorValue(piston) = vexRT[Btn7RXmtr2] || vexRT[Btn8LXmtr2];

		//wait1Msec(5);
	}
}
