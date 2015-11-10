#define __SHOOTER__

int sLeft1, sLeft2, sRight1, sRight2;
bool shooterOn = false;
int shooterSpeed = 0;

void CreateShooter(int left1m, int left2m, int right1m, int right2m) {
	sLeft1 = left1m;
	sLeft2 = left2m;
	sRight1 = right1m;
	sRight2 = right2m;

	return;
}

void SwitchShooter(bool onButton, bool offButton, int targetSpeed) {
	if (onButton)
		shooterOn = true;
	if (offButton)
		shooterOn = false;

	if (shooterOn && shooterSpeed < targetSpeed)
		shooterSpeed++;
	else if (shooterOn && !(shooterSpeed < targetSpeed))
		shooterSpeed = 127;
	else if (!shooterOn && shooterSpeed > 0)
		shooterSpeed--;
	else
		shooterSpeed = 0;

	return;
}

void UpdateShooter() {
	SetMotor(motor[sLeft1], shooterOn * shooterSpeed);
	SetMotor(motor[sLeft2], shooterOn * shooterSpeed);
	SetMotor(motor[sRight1], shooterOn * shooterSpeed);
	SetMotor(motor[sRight2], shooterOn * shooterSpeed);

	return;
}
