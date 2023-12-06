// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();

  //set the default command for the drive subsystem to always schedule
  drive_subsystem.SetDefaultCommand(frc2::RunCommand(
      [this] {
        drive_subsystem.ArcadeDrive(xbox.GetLeftY(), xbox.GetRightX() );
      },
      {&drive_subsystem}));
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // schedule a new command when the B button is pressed to init drive subsystem.
  xbox.B().OnTrue(new frc2::InstantCommand([this] { drive_subsystem.Init(); }, {&drive_subsystem}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&drive_subsystem);
}
