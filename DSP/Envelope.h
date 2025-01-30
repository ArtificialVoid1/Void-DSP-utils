#pragma once

//--------------------------------------------------------------------
// Simple attack functions
static float Linear(float Sample, float Time) {
    float Gain = Time; //between 0 and 1
    return Sample * Gain;
}
static float Quadratic(float Sample, float Time) {
    float Gain = powf(Time, 2.0f);//between 0 and 1
    return Sample * Gain;
}
static float Cubic(float Sample, float Time) {
    float Gain = powf(Time, 3.0f);//between 0 and 1
    return Sample * Gain;
}

// --------------------------------------------------------------------

enum EnvType {
    eLinear = 0,

    eQuad = 10,
    eCubic = 11,
}




//--------------------------------------------------------------------

class BaseEnvelope {
protected:
    float TotalTime;
}

//--------------------------------------------------------------------

template<typename SampleType>
class Envelope_AR : BaseEnvelope {

private:
    float AttackTime;
    float ReleaseTime;
    SampleType(*Attackfunc)(SampleType, float)
    SampleType(*Releasefunc)(SampleType, float)

public:
    Envelope_AR(
        float _AttackTime, 
        float _ReleaseTime, 
        SampleType (*_Attackfunc)(SampleType, float), 
        SampleType (*_Releasefunc)(SampleType, float)
        ) 
    {
        AttackTime = _AttackTime;
        ReleaseTime = _ReleaseTime;
        TotalTime = _AttackTime + _ReleaseTime;

        Attackfunc = _Attackfunc;
        Releasefunc = _Releasefunc;
    }

    inline void SetValues(float _AttackTime, float _ReleaseTime) {
        AttackTime = _AttackTime;
        ReleaseTime = _ReleaseTime;
        TotalTime = _AttackTime + _ReleaseTime;
    }

    SampleType Process(SampleType Sample, float Time) {
        if (Time <= AttackTime) {
            float DeltaAttack = Time / AttackTime;
            return Attackfunc(Sample, DeltaAttack);
        }
        else if (Time > AttackTime && Time <= ReleaseTime) {
            float DeltaRelease = ReleaseTime - (Time - AttackTime) / ReleaseTime;
            return Releasefunc(Sample, DeltaRelease);
        } 
        else {
            return (SampleType)0.0f;
        }
    }
}

//--------------------------------------------------------------------