#ifndef AUTON1_H
#define AUTON1_H

void auton1()
{
	motor[launcherL1] = 75;
	motor[launcherL2] = 75;
	motor[launcherR1] = 75;
	motor[launcherR2] = 75;
	wait1Msec(1500);

	motor[intakeMotor] = 50;
	motor[liftMotor] = -55;
	wait1Msec(12000);
}

#endif
