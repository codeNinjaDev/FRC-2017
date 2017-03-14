#include <WPILib.h>

class Robot: public IterativeRobot
{
private:
	RobotDrive *myDrive;
	Spark *frontLeft, *frontRight, *rearLeft, *rearRight;
	Joystick *joystick = new Joystick(0);

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		frontLeft = new Spark(0);
		frontRight = new Spark(2);
		rearLeft = new Spark(1);
		rearRight = new Spark(3);
		myDrive = new RobotDrive(frontLeft,frontRight,rearLeft,rearRight);
	}

	void TeleopPeriodic() {
	    myDrive->ArcadeDrive(-(joystick->GetY()), joystick->GetX(), true);
	}
};
