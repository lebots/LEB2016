#ifndef AUTON1_H
#define AUTON1_H

void auton1()
{
	motor[launcherL1] = 72;
	motor[launcherL2] = 72;
	motor[launcherR1] = 72;
	motor[launcherR2] = 72;
	wait1Msec(3000);

	motor[intakeMotor] = 50;
	motor[liftMotor] = -50;
	wait1Msec(12000);
}

#endif
