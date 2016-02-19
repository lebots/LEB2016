#ifndef LAUNCHER_H
#define LAUNCHER_H

bool shooterBool = false;
int shootSpeed = 0;
float shotMultiplier;
long finalSpeed;

float kP = 100;


void launcher(int targetRPM, int shooterBool) {

	short leftError = targetRPM - getMotorVelocity(launcherL2);
	short rightError = targetRPM - getMotorVelocity(launcherR1);

	finalSpeed = targetRPM + (leftError * kP);

	/*// Flywheel rampup logic
	if (shooterBool && shootSpeed < 127)
		shootSpeed = shootSpeed + 5;
	else if (shooterBool && !(shootSpeed < 127))
		shootSpeed = (shotMultipler * 127);
	else if (!shooterBool && shootSpeed > 0)
		shootSpeed--;
	else
		shootSpeed = 0;

	// Reset timer for ball launch
	if (SensorValue(deeznutz) < 2000)
		clearTimer(timer1);

	// Ramp up speed once ball goes through flywheels
	if (time1[timer1] >= 200 && time1[timer1] < 750)
		finalSpeed = shooterBool * shootSpeed * shotMultiplier * 1.1;
	else
		finalSpeed = shooterBool * shootSpeed * shotMultiplier;

	*/

	// Set motor powers
	motor[launcherL1] = finalSpeed;
	motor[launcherL2] = finalSpeed;
	motor[launcherR1] = finalSpeed;
	motor[launcherR2] = finalSpeed;

}

#endif
