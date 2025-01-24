#pragma once

#include <cmath>

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