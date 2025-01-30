#pragma once

#include <cmath>
#inlcude "Envelope.h"

template<typename SampleType>
static bool Threshold(SampleType Limit, SampleType Sample) {
  return Limit >= Sample;
}

template<typename SampleType>
static SampleType BasicCompress(SampleType Sample, SampleType threshold, SampleType ratio) {
  if Threshold(threshold, Sample) {
    return threshold + ((abs(Sample)-threshold) / ratio);
  }
  else {
    return Sample;
  }
}

template<typename SampleType>
class Compressor {
private:
  SampleType Sample;
  SampleType Threshold;
  SampleType Ratio;
  SampleType AttackTime;
  SampleType ReleaseTime;

  EnvType AttackType;
  EnvType ReleaseType;

public:
  Compressor(EnvType _attackType, EnvType _releaseType) {
    AttackType = _attackType;
    ReleaseType = _releaseType;
  }

  inline void SetThreshold(SampleType _Threshold) {
    Threshold = _Threshold;
  }
  inline void SetRatio(SampleType _Ratio) {
    Ratio = _Ratio;
  }
  inline void SetAttack(float _AttackTime) {
    AttackTime = _AttackTime;
  }
  inline void SetRelease(float _ReleaseTime) {
    ReleaseTime = _ReleaseTime
  }

  inline SampleType Process(SampleType Sample) {
    //proccess since transient with envelope
  }
}