#pragma once

#include <cmath>
#include "Constants.h"

/**
*Simple Hard Clipping function based on min/max and preClip Gain
*@param Sample the input sample
*@param Drive the gain factor
*/
static float BrickwallClip(float Sample, float Drive) {
  return fmin(1.f, fmax(-1.f, Sample * Drive));
}

/**
*Simpl Soft Clipping function based on arctan and preClip Gain
*@param Sample the input sample
*@param Drive the gain factor
*/
static float BasicSoftClip(float Sample, float Drive) {
  return (2.f / PI) * atan(Sample * Drive);
}