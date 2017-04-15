#include "DriveEncodersPIDSource.h"
#include "WPILib.h"

DriveEncodersPIDSource::DriveEncodersPIDSource(RobotModel* robot) {
	this->robot = robot;
}
double DriveEncodersPIDSource::PIDGet() {
  if (robot->leftDriveEncoder->StatusIsFatal()) return 0.0;
  if (robot->rightDriveEncoder->StatusIsFatal()) return 0.0;
  switch (GetPIDSourceType()) {
    case PIDSourceType::kDisplacement:
      return GetAverageDistance();
    case PIDSourceType::kRate:
      return 0.0;
    default:
      return 0.0;
  }
}

double DriveEncodersPIDSource::GetAverageDistance() {
	return ((robot->leftDriveEncoder->GetDistance()) + (robot->rightDriveEncoder->GetDistance())) / 2.0;
}

