#pragma config(Sensor, dgtl12, piston,         sensorDigitalOut)
#pragma config(Motor,  port1,           liftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           launcherL1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           launcherL2,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           launcherR1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           launcherR2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           frMotor,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           blMotor,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           flMotor,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           brMotor,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          intakeMotor,   tmotorVex393_HBridge, openLoop, reversed)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

void pre_auton()
{
	motor[launcherL1] = 72;
	motor[launcherL2] = 72;
	motor[launcherR1] = 72;
	motor[launcherR2] = 72;
	motor[intakeMotor] = 127;
	motor[liftMotor] = -127;
	wait1Msec(60000);
}

task autonomous()
{

	AutonomousCodePlaceholderForTesting();
}

task usercontrol()
{


	while (true)
	{
	  UserControlCodePlaceholderForTesting();
	}
}
