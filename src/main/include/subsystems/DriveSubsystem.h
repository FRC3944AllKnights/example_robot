// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   *  method for driving the robot
   * @param translation forward and backward speed
   * @param rotation left and right turning speed
   */
  void ArcadeDrive(double translation, double rotation);

  /**
   * initialization method for the drivebase.
  */
  void Init();

  /**
   * given a raw value of range -1 to 1, removes numbers close to zero.
   * @param raw_value the value to be filtered. Expects -1 to 1.
   * @return the filtered value. Will be zero if raw value was close to zero.
  */
  double DeadBandFilter(double raw_value);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax m_front_left{1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_front_right{2, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_back_left{4, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_back_right{3, rev::CANSparkMax::MotorType::kBrushless};
};
