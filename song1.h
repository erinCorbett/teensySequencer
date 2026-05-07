#ifndef SONG1
#define SONG1

float scaleNote[] = {
  100,                //0 = first
  105.9463,           //1 ==           minor second
  112.2462,           //2 == second
  118.9207,           //3 ==          minor third
  125.9921,           //4 == majthird
  133.484,            //5 == fourth
  141.4214,           //6 ==          t  r i to n  e 
  149.8307,           //7 == fifth
  158.7401,           //8 ==           minor sixth
  168.1793,           //9 == majsixth
  178.1797,           //10 ==         minor seventh
  188.7749,            //11 == major seventh
  200
};



int chords[][4] = {
  {0, 4, 7, 11},
  {2, 4, 11, 7},
  {2, 5, 9, 11}
};


//Velocity Steps (0-1: Normal Range, 1+: High-Amp APPROACH WITH CAUTION)
float kickVel[] = {2};
int kvLength;
float snareVel[1];

float hatVel[] =   {
  1.0, 0.8, 0.6, 1.0, 
  0.7, 0.5, 0.4, 1.0, 
  0.9, 0.8, 0.7, 0.6, 
  0.5, 0.4, 0.3, 0.2,
  0.7, 0.5, 0.4, 1.0, 
  0.9, 0.8, 0.7, 0.6, 
  0.5, 0.4, 0.3, 0.2
};
int hatVelLength;

float bassVelocity[] =   {
  1.0, 0.8, 0.7, 1.6, 
  6.0, 5.0, 1.0, 6.0
};
int bvLength;

float tomVel[1];

//Sequence Bank
int sequences[32][16] {
  {1,0,0,0,  0,0,0,0,  0,0,1,0,  0,0,0,0}, //Pattern: 0 (original Kick)
  {0,0,0,0,  1,0,0,0,  0,0,0,0,  1,0,0,0}, //Pattern: 1 (original Snare)
  {1,1,1,1,  1,1,1,1,  1,1,1,1,  1,1,1,1}, //Pattern: 2 (original Hat)
  {1,0,0,0,  0,0,0,1,  0,0,1,0,  0,0,0,0}, //Pattern: 3 (original Tom)

  {1,0,0,0,  0,0,1,0,  0,0,1,1,  0,1,1,1}, //Pattern: 4 ()
  {1,0,0,1,  0,0,1,0,  1,0,0,1,  0,0,1,0}, //Pattern: 5 ()
  {1,1,0,1,  1,1,0,1,  1,1,0,1,  1,0,1,1}, //Pattern: 6 ()
  {1,1,0,0,  1,0,1,1,  0,0,1,0,  1,1,1,1}, //Pattern: 7 ()

  {0,0,0,0,  1,0,0,0,  0,0,0,0,  0,0,0,2}, //Pattern: 8 ()
  {0,0,0,0,  1,0,0,0,  0,0,0,2,  0,0,1,0}, //Pattern: 9 ()
  {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0}, //Pattern: 10()
  {1,0,0,0,  0,0,0,0,  0,0,0,2,  0,0,0,0}  //Pattern: 11()
};

int kickPattern[] {
  0,
  0,
  0,
  0,
  
  0,
  0,
  0,
  4

};
int kkPLength;

int snarePattern[] {
  1,
  5,
  1,
  7,
  1,
  5,
  1,
  6,
  1,
  5,
  1,
  7,
  1,
  5,
  1,
  0
};
int snPLength;

int polyPattern[] {
  8, 8, 
  8, 8,
  8, 8,
  8, 9
};
int polyPLength;


int bassPattern[] {
  6, 7, 6, 7, 5
};
int bsPLength;

//Frequency Steps
float kickPitch[] = {40, 40, 50};
int kpLength;

int polyChord[] = {0, 1, 0, 1, 0, 1, 0, 2};
int polyCLength;

/*float bassPitch[] = {
  100, 120, 100, 150,
  100, 200, 100, 150,
  100, 200, 160, 150,
  100, 200, 100, 150,

  100, 220, 100, 150,
  100, 200, 140, 150,
  100, 200, 160, 150,
  100, 200, 120, 110,
  

  100, 220, 100, 150,
  100, 200, 140, 150,
  100, 200, 160, 150,
  70, 80, 90, 110
  
  };*/

  int bassPitch[] = {
  0, 12, 0, 7,
  0, 12, 0, 7,
  0, 12, 9, 7,
  0, 12, 0, 7,

  0, 12, 100, 7,
  0, 12, 140, 7,
  0, 12, 160, 7,
  0, 12, 120, 7,  

  0, 12, 0, 7,
  0, 12, 3, 4,
  0, 12, 9, 7,
  0, 12, 6, 7
  
  };


int bpLength;

float poly_filterFreq = 600, 
      poly_filterResonance = 7, 
      poly_octaveControl = 7,

      poly_attack = 00,
      poly_decay = 300,
      poly_sustain = 0.4,
      poly_release = 500,

      poly_octaveMod = 4;

#endif