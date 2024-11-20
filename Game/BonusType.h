#pragma once

enum class BonusType
{
  SLOW_GHOSTS=1,
  SPEED_GHOSTS,
  STOP_GHOSTS,  
  EAT_ALL_GHOSTS,
};

std::ostream& operator<<(std::ostream& out, const BonusType& bonusType);