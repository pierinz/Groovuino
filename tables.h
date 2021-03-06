#ifndef SAMPLE_RATE
#define SAMPLE_RATE 44100.0
#endif
#define SAMPLES_PER_CYCLE 600
#define SAMPLES_PER_CYCLE_FIXEDPOINT (SAMPLES_PER_CYCLE<<20)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)

#define WAVE_SAMPLES 600
int16_t nSineTable[WAVE_SAMPLES];
int16_t nSawTable[WAVE_SAMPLES];
int16_t nSqTable[WAVE_SAMPLES];

#define MIDI_NOTES 128
uint32_t nMidiPhaseIncrement[MIDI_NOTES];


void createSineTable()
{ 
  for(uint32_t nIndex = 0;nIndex  < WAVE_SAMPLES;nIndex++) 
  { 
    // normalised to 12 bit range 0-4095 
    nSineTable[nIndex] = (int16_t)  ((sin(((2.0*PI)/WAVE_SAMPLES)*nIndex))*2048.0);
  } 
} 

void createSawTable() 
{ 
  for(uint32_t nIndex = 0;nIndex  < WAVE_SAMPLES;nIndex++) 
  { 
    nSawTable[nIndex] = (uint16_t)  (nIndex*(4095.0/600)-2048); 
  } 
} 

void createSqTable() 
{ 
  for(uint32_t nIndex = 0; nIndex  < WAVE_SAMPLES; nIndex++) 
  { 
    if(nIndex<(WAVE_SAMPLES/2)) nSqTable[nIndex] = -2048;
    if(nIndex>=(WAVE_SAMPLES/2)) nSqTable[nIndex] = 2047; 
  } 
} 
