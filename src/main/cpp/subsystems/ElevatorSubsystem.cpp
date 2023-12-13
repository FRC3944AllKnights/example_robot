// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ElevatorSubsystem.h"

ElevatorSubsystem::ElevatorSubsystem() {
  // Implementation of subsystem constructor goes here.
}

void ElevatorSubsystem::Init() {

}



double ElevatorSubsystem::DeadBandFilter(double raw_value){
if (0.1 >=raw_value and raw_value>= -0.1 ) return 0;
return raw_value;
}

void ElevatorSubsystem::Periodic() {
}
  // Implementation of subsystem periodic method goes here.

void ElevatorSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
