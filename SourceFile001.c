
#pragma config(Motor,  port6,           launcherL1,    tmotorVex393_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port7,           launcherL2,    tmotorVex393_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port8,           launcherR1,    tmotorVex393_MC29, openLoop, reversed, encoderPort, dgtl3)
#pragma config(Motor,  port9,           launcherR2,    tmotorVex393_MC29, openLoop, reversed, encoderPort, dgtl3)


task main()
{
	while (true) {
		if (vexRT[Btn8D]) {
			motor[launcherL1] = 127;
			motor[launcherL2] = 127;
			motor[launcherR1] = 127;
			motor[launcherR2] = 127;
		} else if (vexRT[Btn7D]) {
			motor[launcherL1] = 0;
			motor[launcherL2] = 0;
			motor[launcherR1] = 0;
			motor[launcherR2] = 0;
		}
	}
}
