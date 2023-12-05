// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() {
  // Implementation of subsystem constructor goes here.
}

void DriveSubsystem::Init() {

}

void DriveSubsystem::ArcadeDrive( double translation , ? ) {
  //do drive stuff
  m_front_left.Set(0);
  m_front_right.Set(0);
  m_back_left.Set(0);
  m_back_right.Set(0);
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
