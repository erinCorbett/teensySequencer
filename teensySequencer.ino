#include "song1.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformModulated polyA;   //xy=306,972
AudioSynthWaveformModulated polyB; //xy=309,1020
AudioSynthWaveformModulated polyD; //xy=315,1132
AudioSynthWaveformModulated polyC; //xy=316,1062
AudioSynthWaveformModulated bass;   //xy=333,743
AudioSynthNoiseWhite     hat;         //xy=352,504
AudioSynthSimpleDrum     tom;          //xy=451,580
AudioEffectEnvelope      bass_env;      //xy=456,734
AudioSynthNoisePink      snare;          //xy=474,435
AudioFilterStateVariable hat_hpf;        //xy=477,499
AudioEffectEnvelope      polyA_env; //xy=478,965
AudioSynthSimpleDrum     kick;          //xy=481,308
AudioEffectEnvelope      polyC_env; //xy=485,1078
AudioEffectEnvelope      polyB_env; //xy=487,1019
AudioEffectEnvelope      polyD_env; //xy=495,1129
AudioAmplifier           kick_amp;           //xy=627,283
AudioEffectEnvelope      snare_env;      //xy=631,425
AudioEffectEnvelope      hat_env; //xy=634,501
AudioAmplifier           tom_amp;           //xy=634,579
AudioFilterStateVariable bass_filter;        //xy=644,726
AudioFilterStateVariable polyA_filter; //xy=667,958
AudioFilterStateVariable polyC_filter; //xy=673,1070
AudioFilterStateVariable polyB_filter; //xy=678,1013
AudioFilterStateVariable polyD_filter; //xy=683,1121
AudioMixer4              drumBus;         //xy=813,536
AudioMixer4              synthBus;         //xy=832,711
AudioMixer4              polyBus;         //xy=884,976
AudioMixer4              master;         //xy=1055,609
AudioOutputI2S           i2s1;           //xy=1268,508
AudioConnection          patchCord1(polyA, polyA_env);
AudioConnection          patchCord2(polyB, polyB_env);
AudioConnection          patchCord3(polyD, polyD_env);
AudioConnection          patchCord4(polyC, polyC_env);
AudioConnection          patchCord5(bass, bass_env);
AudioConnection          patchCord6(hat, 0, hat_hpf, 0);
AudioConnection          patchCord7(tom, tom_amp);
AudioConnection          patchCord8(bass_env, 0, bass_filter, 0);
AudioConnection          patchCord9(bass_env, 0, bass_filter, 1);
AudioConnection          patchCord10(snare, snare_env);
AudioConnection          patchCord11(hat_hpf, 2, hat_env, 0);
AudioConnection          patchCord12(polyA_env, 0, polyA_filter, 0);
AudioConnection          patchCord13(polyA_env, 0, polyA_filter, 1);
AudioConnection          patchCord14(kick, kick_amp);
AudioConnection          patchCord15(polyC_env, 0, polyC_filter, 0);
AudioConnection          patchCord16(polyC_env, 0, polyC_filter, 1);
AudioConnection          patchCord17(polyB_env, 0, polyB_filter, 0);
AudioConnection          patchCord18(polyB_env, 0, polyB_filter, 1);
AudioConnection          patchCord19(polyD_env, 0, polyD_filter, 0);
AudioConnection          patchCord20(polyD_env, 0, polyD_filter, 1);
AudioConnection          patchCord21(kick_amp, 0, drumBus, 0);
AudioConnection          patchCord22(snare_env, 0, drumBus, 1);
AudioConnection          patchCord23(hat_env, 0, drumBus, 2);
AudioConnection          patchCord24(tom_amp, 0, drumBus, 3);
AudioConnection          patchCord25(bass_filter, 0, synthBus, 0);
AudioConnection          patchCord26(polyA_filter, 0, polyBus, 0);
AudioConnection          patchCord27(polyC_filter, 0, polyBus, 2);
AudioConnection          patchCord28(polyB_filter, 0, polyBus, 1);
AudioConnection          patchCord29(polyD_filter, 0, polyBus, 3);
AudioConnection          patchCord30(drumBus, 0, master, 0);
AudioConnection          patchCord31(synthBus, 0, master, 1);
AudioConnection          patchCord32(polyBus, 0, master, 2);
AudioConnection          patchCord33(master, 0, i2s1, 0);
AudioConnection          patchCord34(master, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=419,837
// GUItool: end automatically generated code

#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11   // Teensy 4 ignores this, uses pin 11
#define SDCARD_SCK_PIN   13  // Teensy 4 ignores this, uses pin 13

//SET SCALE



void setup() {
  // audio library init
  //Sd2Card card;
  //boolean status;
  // wait for the Arduino Serial Monitor to open
  //while (!Serial) ;
  //delay(50);

  // Configure SPI
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);

  Serial.begin(9600);
  /*Serial.println("SD Card Test");
  Serial.println("------------");

  status = card.init(SPI_FULL_SPEED, SDCARD_CS_PIN);
  if (status) {
    Serial.println("SD card is connected :-)");
  } else {
    Serial.println("SD card is not connected or unusable :-(");
  }*/

  AudioMemory(15);

  AudioNoInterrupts();


  //INITIALIZE POLYSYNTH
  polyA.begin(1, scaleNote[0]*poly_octaveMod, WAVEFORM_TRIANGLE);
  polyB.begin(1, scaleNote[1]*poly_octaveMod, WAVEFORM_TRIANGLE);
  polyC.begin(1, scaleNote[2]*poly_octaveMod, WAVEFORM_TRIANGLE);
  polyD.begin(1, scaleNote[3]*poly_octaveMod, WAVEFORM_TRIANGLE);

  polyA_filter.frequency(poly_filterFreq);
  polyA_filter.resonance(poly_filterResonance);
  polyA_filter.octaveControl(poly_octaveControl);
  
  polyA_env.attack(poly_attack);
  polyA_env.decay(poly_decay);
  polyA_env.sustain(poly_sustain);
  polyA_env.release(poly_release);

  polyB_filter.frequency(poly_filterFreq);
  polyB_filter.resonance(poly_filterResonance);
  polyB_filter.octaveControl(poly_octaveControl);
  
  polyB_env.attack(poly_attack);
  polyB_env.decay(poly_decay);
  polyB_env.sustain(poly_sustain);
  polyB_env.release(poly_release);

  polyC_filter.frequency(poly_filterFreq);
  polyC_filter.resonance(poly_filterResonance);
  polyC_filter.octaveControl(poly_octaveControl);
  
  polyC_env.attack(poly_attack);
  polyC_env.decay(poly_decay);
  polyC_env.sustain(poly_sustain);
  polyC_env.release(poly_release);

  polyD_filter.frequency(poly_filterFreq);
  polyD_filter.resonance(poly_filterResonance);
  polyD_filter.octaveControl(poly_octaveControl);
  
  polyD_env.attack(poly_attack);
  polyD_env.decay(poly_decay);
  polyD_env.sustain(poly_sustain);
  polyD_env.release(poly_release);
  polyCLength = sizeof(polyChord)/sizeof(polyChord[0]);
  polyPLength = sizeof(polyPattern)/sizeof(polyPattern[0]);




  bass.begin(0.5, 400, WAVEFORM_SAWTOOTH);
  bass_filter.frequency(200);
  bass_filter.resonance(10);
  bass_filter.octaveControl(7);
  
  bass_env.attack(0);
  bass_env.decay(40);
  bass_env.sustain(0.5);
  bass_env.release(150);
  bpLength = sizeof(bassPitch)/sizeof(bassPitch[0]);
  bvLength = sizeof(bassVelocity)/sizeof(bassVelocity[0]);
  bsPLength = sizeof(bassPattern)/sizeof(bassPattern[0]);

  kick.frequency(50);
  kick.length(750);
  kick.secondMix(0.0);
  kick.pitchMod(0.6);
  kick_amp.gain(1);
  kpLength = sizeof(kickPitch) / sizeof(kickPitch[0]);
  kvLength = sizeof(kickVel) / sizeof(kickVel[0]);
  kkPLength = sizeof(kickPattern)/sizeof(kickPattern[0]);

  snare.amplitude(1);
  snare_env.attack(0);
  snare_env.decay(40);
  snare_env.sustain(0.1);
  snare_env.release(90);
  snPLength = sizeof(snarePattern)/sizeof(snarePattern[0]);

  hat.amplitude(1);
  hat_hpf.frequency(800);
  hat_env.attack(0);
  hat_env.decay(20);
  hat_env.sustain(0);
  hat_env.release(0);

  hatVelLength = (sizeof(hatVel) / sizeof(hatVel[0])-1);

  tom.frequency(1200);
  tom.length(150);
  tom.secondMix(0.0);
  tom.pitchMod(0.0);

  //kickGain
  drumBus.gain(0, 1);

  //snareGain
  drumBus.gain(1, 1);

  //hatGain
  drumBus.gain(2, 0.1);

  drumBus.gain(3, 0.8);

  synthBus.gain(0, 0.8);

  polyBus.gain(0, 0.5);
  polyBus.gain(1, 0.5);
  polyBus.gain(2, 0.5);
  polyBus.gain(3, 0.5);

  master.gain(0, 1);
  master.gain(1, 0.5);
  master.gain(2, 0.5);
  
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.4);

  AudioInterrupts();

}

int frame  = 0;
int count = 0;
int speed = 85;
int bar = 0;


int kvc = 0;
int kpc = 0;
int kkPC = 0;

int pvc, ppc, poPC = 0;
int hvc, hpc, hhPC = 0;

int bvc, bpc, bbPC = 0;

int snPC = 0;

float tempoMult = 1.0;
float stutterButton = 0;

int tick;

//LOOP -------------------------------------------------------------------||

void loop() {

  Serial.print("Tick: ");
  Serial.print(tick);
  Serial.print(" Step: ");
  Serial.println(count);
  //tempoMult = floor(mapfloat(analogRead(A0), 0, 1023, 2.0, 0.1)*10)/10;
  //float bassFiltDec = map(analogRead(A2), 0, 1023, 0, 20000);
  //float stutterButton = analogRead(A3);

  //bass_filter.frequency(bassFiltDec);


  
if(tick%100==0) {
  if(count<15 && stutterButton<1000) {
    //polyNoteOn();
    resetStep();
    count++;
  } else {
    count = 0;
    if(bar<3) {
      bar++;
      resetPatterns();
    } else {
      resetPatterns();
      resetBar();
    }
  }
  
  if(sequences[kickPattern[kkPC]][count]) {
    triggerKick(stutterButton);
  }
  if(sequences[bassPattern[bbPC]][count]) {
    triggerBass(stutterButton);
  }

  switch(sequences[polyPattern[poPC]][count]) {
    case 0:
    break;
    case 1: triggerPoly(stutterButton);
    break;
    case 2: polyNoteOff();
    break;
    
  }
  if (sequences[snarePattern[snPC]][count]) {
    triggerSnare(stutterButton);
  }

  if(sequences[2][count]) {
    //hat.amplitude(hatSeq[count]);
    //hat_env.noteOn();
    triggerHat(count);
  }

  if(sequences[3][count]) {
    //tom.noteOn();
  }

  
}

  delayMicroseconds(1000);
  if(tick<999999) {
    tick++;
  } else {
    tick = 0;
  }
  
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
//TRIGGER KICK DRUM

void triggerKick(float stutterButton) {
  kick_amp.gain(kickVel[kvc]);
  kick.frequency(kickPitch[kpc]);
  kick.noteOn();
  if (stutterButton<1000) {
  if(kvc<kvLength-1) {
    kvc++;
  } else {
    kvc = 0;
  }

  if(kpc<kpLength-1) {
    kpc++;
  } else {
    kpc = 0;
  }
  }
}

//TRIGGER BASS
void triggerBass(float stutterButton) {
  bass.amplitude(bassVelocity[bvc]);
  //bass.frequency(bassPitch[bpc]*1.5);
  bass.frequency(scaleNote[bassPitch[bpc]]);
  bass_env.noteOn();

  if (stutterButton<1000) {
  if(bvc<bvLength-1) {
    bvc++;
  } else {
    bvc = 0;
  }

  if(bpc<bpLength-1) {
    bpc++;
  } else {
    bpc = 0;
  }
  }
}


//TRIGGER SNARE
void triggerSnare(float stutterButton) {
    snare_env.noteOn();
    //bass_env.noteOn();
}

//TRIGGER HI-HAT
void triggerHat(float stutterButton) {
  hat.amplitude(hatVel[hvc]);
  hat_env.noteOn();
  if (stutterButton<1000) {
  if(hvc<hatVelLength) {
    hvc++;
  } else {
    hvc = 0;
  }
  }
}

void triggerPoly(float stutterButton) {
  //bass.amplitude(bassVelocity[bvc]);
  //bass.frequency(bassPitch[bpc]*1.5);


  polyA.frequency(scaleNote[chords[polyChord[ppc]][0]]);
  polyB.frequency(scaleNote[chords[polyChord[ppc]][1]]*2);
  polyC.frequency(scaleNote[chords[polyChord[ppc]][2]]);
  polyD.frequency(scaleNote[chords[polyChord[ppc]][3]]*2);

  polyNoteOn();
  /*if(bvc<bvLength-1) {
    bvc++;
  } else {
    bvc = 0;
  }*/
  if (stutterButton<1000) {
  if(ppc<polyCLength-1) {
    ppc++;
  } else {
    ppc = 0;
  }
  }
}

void resetStep() {
  snare_env.noteOff();
  hat_env.noteOff();
  bass_env.noteOff();

}

void resetPatterns() {

  polyNoteOff();
    if(kkPC<kkPLength-1) {
      kkPC++;
    } else {
      kkPC = 0;
    }

    if(snPC<snPLength-1) {
      snPC++;
    } else {
      snPC = 0;
    }

    if(bbPC<bsPLength-1) {
      bbPC++;
    } else {
      bbPC = 0;
    }
    if(poPC<polyPLength-1) {
      poPC++;
    } else {
      poPC = 0;
    }
}

void resetBar() {
    bar = 0;



}

void polyNoteOn() {
  polyA_env.noteOn();
  polyB_env.noteOn();
  polyC_env.noteOn();
  polyD_env.noteOn();
}

void polyNoteOff() {
  polyA_env.noteOff();
  polyB_env.noteOff();
  polyC_env.noteOff();
  polyD_env.noteOff();
}