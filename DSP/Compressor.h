#include <cmath>
#include "Constants.h"

static bool Threshold(float Limit, float Sample) {
  return Limit >= Sample;
}

static float BasicCompress(float Sample, float threshold, float ratio) {
  if Threshold(threshold, Sample) {
    return threshold + ((abs(Sample)-threshold) / ratio);
  }
  else {
    return Sample;
  }
}
