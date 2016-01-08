#ifndef __SHOOTER__
#define __SHOOTER__

int sLeft1, sLeft2, sRight1, sRight2;
bool shooterOn = false;
int shooterSpeed = 0;

task CreateShooter(int left1m, int left2m, int right1m, int right2m) {
	sLeft1 = left1m;
	sLeft2 = left2m;
	sRight1 = right1m;
	sRight2 = right2m;

	return;
}

task SwitchShooter(bool onButton, bool offButton) {
	if (onButton)
		shooterOn = true;
	if (offButton)
		shooterOff = false;

	if (shooterOn && shooterSpeed < 127)
		shooterSpeed++;
	else if (shooterOn && !(shooterSpeed < 127))
		shooterSpeed = 127;
	else if (!shooterOn && shooterSpeed > 0)
		shooterSpeed--;
	else
		shooterSpeed = 0;

	return;
}

task UpdateShooter() {
	SetMotor(motor[sLeft1], shooterOn * shooterSpeed);
	SetMotor(motor[sLeft2], shooterOn * shooterSpeed);
	SetMotor(motor[sRight1], shooterOn * shooterSpeed);
	SetMotor(motor[sRight2], shooterOn * shooterSpeed);

	return;
}

#endif
