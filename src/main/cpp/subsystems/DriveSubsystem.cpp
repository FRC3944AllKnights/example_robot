// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() {
  // Implementation of subsystem constructor goes here.
}

void DriveSubsystem::Init() {

}

void DriveSubsystem::ArcadeDrive( double translation, double rotation  ) {
  //do drive stuff
  double regular_translation = DeadBandFilter(translation);
  double regular_rotation = DeadBandFilter(rotation);
  double right_side = (regular_rotation + regular_translation)*0.2;
  double left_side = (regular_translation - regular_rotation)*0.2;
  m_front_left.Set(-left_side);
  m_back_left.Set(-left_side);

  m_front_right.Set(right_side);
  m_back_right.Set(right_side);
}

double DriveSubsystem::DeadBandFilter(double raw_value){
if (0.1 >=raw_value and raw_value>= -0.1 ) return 0;
return raw_value;
}

void DriveSubsystem::Periodic() {
}
  // Implementation of subsystem periodic method goes here.

void DriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
