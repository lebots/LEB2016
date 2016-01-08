#ifndef AUTON1_H
#define AUTON1_H

void auton1()
{
	motor[launcherL1] = 60;
	motor[launcherL2] = 60;
	motor[launcherR1] = 60;
	motor[launcherR2] = 60;
	wait1Msec(3000);

	motor[intakeMotor] = 50;
	motor[liftMotor] = -50;
}

#endif
