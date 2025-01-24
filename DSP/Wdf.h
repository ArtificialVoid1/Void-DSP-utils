#pragma once

#include "chowdsp_wdf.h" //locate this file
#include "Constants.h"

using chowdsp::wdft;

// ---------------------------------------------------------------------

template<typename SampleType>
class RC_Lowpass {

private:
    ResistorT<SampleType> r1 {KILO}; // 1 kOhm
    CapacitorT<SampleType> c1 {MICRO * 5.0f}; //5 uf

    WDFSeriesT<SampleType, decltype(r1), decltype(c1)> s1 {r1, c1};
    IdealVoltageSourceT<SampleType, decltype(s1)> vs {s1};

public:
    RC_Lowpass(SampleType SampleRate) {
        c1.prepare(SampleRate); 
    }

    void setCutoff(SampleType frequency) {
        float Cap = MICRO * 5.0f;
        float Res = 1.0f / (TAU * frequency * Cap);

        c1.setCapacitanceValue(Cap);
        r1.setResistanceValue(Res);
    }

    inline SampleType Process(SampleType Sample) {

        vs.setVoltage(Sample);

        vs.incident(c1.reflected());
        c1.incident(vs.reflected());

        return voltage(c1);
    }
}

// ---------------------------------------------------------------------

template<typename SampleType>
class RC_Highpass {

private:
    ResistorT<SampleType> r1 {KILO}; // 1 kOhm
    CapacitorT<SampleType> c1 {MICRO * 5.0f}; //5 uf

    WDFSeriesT<SampleType, decltype(r1), decltype(c1)> s1 {r1, c1};
    IdealVoltageSourceT<SampleType, decltype(s1)> vs {s1};

public:
    RC_Lowpass(SampleType SampleRate) {
        c1.prepare(SampleRate); 
    }

    void setCutoff(SampleType frequency) {
        float Cap = MICRO * 5.0f;
        float Res = 1.0f / (TAU * frequency * Cap);

        c1.setCapacitanceValue(Cap);
        r1.setResistanceValue(Res);
    }

    inline SampleType Process(SampleType Sample) {

        vs.setVoltage(Sample);

        vs.incident(r1.reflected());
        r1.incident(vs.reflected());

        return voltage(r1);
    }
}

// ------------------------------------------------------------------