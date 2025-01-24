#pragma once

#include <cmath>
#include "Constants.h"

/*

In clipping there are generally two ways to beef up a signal with distortion

Thesse are adding Even and Odd Harmonics

Even harmonics such as 2f 6f 8f so on add octaves and beef up the tone with no dissonance 
Odd harmonics such as 1f 3f 5f 9f so on add non octave frequencies and beef up the tone with dissonance

if we imagine a basic clipping function, we can see clipping a sine wave harshly leads to a square wave
this adds even harmonics

if we add some sort of envelope (ASDR) then we can modify how the clipping happens
if we clip a sine wave into a sort of saw wave, this adds odd harmonics
odd harmonics are more gentle feeling like a overdrive pedal

*/




/**
*Simple Hard Clipping function based on min/max and preClip Gain
*@param Sample the input sample
*@param Drive the gain factor
*/
template<typename SampleType>
static SampleType BrickwallClip(SampleType Sample, SampleType Drive) {
  return fmin(1.f, fmax(-1.f, Sample * Drive));
}

/**
*Simpl Soft Clipping function based on arctan and preClip Gain
*@param Sample the input sample
*@param Drive the gain factor
*/
template<typename SampleType>
static SampleType BasicSoftClip(SampleType Sample, SampleType Drive) {
  return (2.f / PI) * atan(Sample * Drive);
}