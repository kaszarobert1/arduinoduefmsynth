//Arduino Due fm polyphonic synthesizer 2019-2020 by Robert Laszlo Kasza
/*
  #pragma GCC push_options
  #pragma GCC optimize("Os")
*/
#include <Audio.h>
#include <MIDI.h>
//#include <MIDIUSB.h>
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI2);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long starttime, stoptime, eltelttime, eltelttime2 ;

//audio
long portamento = 0;
byte mosthang = 0;
byte elozohang = 0;
uint32_t maxminta = 65535;
const uint16_t audiobuffersize = 32;
uint16_t buffermeret = audiobuffersize;
long bufferbe;
long bufferbe1;
uint16_t bufferindex;
short oldbufferbeLeft = 0;
short oldbufferbeLeft2 = 0;
short oldbufferbeRight = 0;
short oldbufferbeRight2 = 0;
uint32_t mintavetelifreqstereo = 88200;
int kitoltes0 = 1;
int kitoltes1 = 1;
int kitoltes2 = 1;
int kitoltes3 = 1;
int kitoltes4 = 1;
int kitoltes5 = 1;
//effect
long delaybuffer[3000];
uint16_t elozodelaybufferindex;
uint16_t elozodelaybufferindex2;
uint16_t delaybufferindex = 0;
uint16_t delaybufferindex2 = 1;
uint16_t reverblevel = 32;
uint16_t reverblevel2 = 32;
byte choruslevel = 3;
byte chorusfreq = 0;
uint16_t chorusalg = 64;
uint16_t chorustime = 3000;
uint16_t reverbtime = 1000;
uint16_t reverbtime2 = 3000;
uint16_t level = 4;
long y;
long y2;
long y3;
long y4;
int freq1 = 0;
int freq2 = 10000;
uint16_t eqvalue = 12177;
long limitgain = 65535;
byte revalg = 8;
//tva
int gorbetime[8] = { -1, -1, -1, -1, -1, -1, -1, -1};
uint16_t maxrelease = 0;
uint16_t maxtime = 0;
uint16_t maxrelease0 = 0;
uint16_t maxrelease1 = 0;
uint16_t maxrelease2 = 0;
uint16_t maxrelease3 = 0;
uint16_t maxrelease4 = 0;
uint16_t maxrelease5 = 0;
uint16_t maxtime0 = 0;
uint16_t maxtime1 = 0;
uint16_t maxtime2 = 0;
uint16_t maxtime3 = 0;
uint16_t maxtime4 = 0;
uint16_t maxtime5 = 0;
byte gorbeszorzo = 2;
byte released = 2;
//controll
byte analogPin0 = A0;
byte analogPin1 = A1;
byte analogPin2 = A2;
byte analogPin3 = A3;
byte analogPin4 = A4;
byte analogPin5 = A5;
byte gomb1 = 2;
byte gomb2 = 3;
byte gomb3 = 4;
byte gomb4 = 5;
byte gomb5 = 6;
byte gomb6 = 7;
byte gomb7 = 8;
byte gomb8 = 9;
byte stepprogchanged = 0;
bool inc = false;
bool dec = false;
byte menuoldal = 1;
byte opmenuoldal = 1;
//feedback
long old0[8];
long old1[8];
int16_t feedback_level = 1;
long  average = 0;
//midi
byte generatornumber = 1;
uint32_t noteertek[128];
byte midichan = 1;

//initprogramparameter
byte program = 8;
byte alg = 1;
byte alg2 = 1;
#define GORBE_SIZE  2048
//const uint16_t  GORBE_SIZE =16284;
uint16_t op1gorbe[GORBE_SIZE];
uint16_t op2gorbe[GORBE_SIZE];
uint16_t op3gorbe[GORBE_SIZE];
uint16_t op5gorbe[GORBE_SIZE];
uint16_t op4gorbe[GORBE_SIZE];
uint16_t op6gorbe[GORBE_SIZE];
int16_t pichgorbe[GORBE_SIZE];
uint16_t op1level[8];
uint16_t op2level[8];
uint16_t op3level[8];
uint16_t op4level[8];
uint16_t op5level[8];
uint16_t op6level[8];
uint16_t op1veloc = 64;
uint16_t op2veloc = 64;
uint16_t op3veloc = 64;
uint16_t op4veloc = 64;
uint16_t op5veloc = 64;
uint16_t op6veloc = 64;
uint16_t  waveveloc[8] = {64, 64, 64, 64, 64, 64, 64, 64};
//byte opwaweform[6];
byte  op1waveform = 1;
byte  op2waveform = 1;
byte  op3waveform = 1;
byte  op5waveform = 1;
byte  op4waveform = 1;
byte  op6waveform = 1;
byte szorzo = 10;
uint16_t op1al = 40;
uint16_t op1ar = 1;
uint16_t op1d1l = 20;
uint16_t op1d1r = 2;
uint16_t op1d2l = 30;
uint16_t op1d2r = 10;
uint16_t op1rl = 30;
uint16_t op1rr = 39;
uint16_t op2al = 40;
uint16_t op2ar = 20;
uint16_t op2d1l = 20;
uint16_t op2d1r = 2;
uint16_t op2d2l = 30;
uint16_t op2d2r = 10;
uint16_t op2rl = 0;
uint16_t op2rr = 20;
uint16_t op3al = 40;
uint16_t op3ar = 20;
uint16_t op3d1l = 20;
uint16_t op3d1r = 2;
uint16_t op3d2l = 30;
uint16_t op3d2r = 10;
uint16_t op3rl = 0;
uint16_t op3rr = 20;
uint16_t op5al = 40;
uint16_t op5ar = 20;
uint16_t op5d1l = 20;
uint16_t op5d1r = 2;
uint16_t op5d2l = 30;
uint16_t op5d2r = 10;
uint16_t op5rl = 0;
uint16_t op5rr = 20;
uint16_t op4al = 40;
uint16_t op4ar = 0;
uint16_t op4d1l = 20;
uint16_t op4d1r = 2;
uint16_t op4d2l = 30;
uint16_t op4d2r = 10;
uint16_t op4rl = 0;
uint16_t op4rr = 10;
uint16_t op6al = 40;
uint16_t op6ar = 0;
uint16_t op6d1l = 20;
uint16_t op6d1r = 2;
uint16_t op6d2l = 30;
uint16_t op6d2r = 10;
uint16_t op6rl = 0;
uint16_t op6rr = 10;
int16_t pichkezd = 63;
int16_t pichal = 6;
int16_t pichar = 10;
int16_t pichd1l = 20;
int16_t pichd1r = 2;
int16_t pichd2l = 30;
int16_t pichd2r = 10;
int16_t pichrl = 1;
int16_t pichrr = 30;
bool notefixedop1 = true;
bool notefixedop2 = true;
bool notefixedop3 = true;
bool notefixedop4 = true;
bool notefixedop5 = true;
bool notefixedop6 = true;
uint32_t op1generatorfreqfix = 40000;
uint32_t op2generatorfreqfix = 40000;
uint32_t op3generatorfreqfix = 40000;
uint32_t op5generatorfreqfix = 40000;
uint32_t op4generatorfreqfix = 40000;
uint32_t op6generatorfreqfix = 40000;
uint16_t op1volume;
uint16_t op1volumeorig;
uint16_t op2volume;
uint16_t op2volumeorig;
uint16_t op3volume;
uint16_t op3volumeorig;
uint16_t op4volume;
uint16_t op4volumeorig;
uint16_t op5volume;
uint16_t op5volumeorig;
uint16_t op6volume;
uint16_t op6volumeorig;
byte op1generatorfreq;
byte op1generatorfreqorig;
byte op2generatorfreq;
byte op2generatorfreqorig;
byte op3generatorfreq;
byte op3generatorfreqorig;
byte op4generatorfreq;
byte op4generatorfreqorig;
byte op5generatorfreq;
byte op5generatorfreqorig;
byte op6generatorfreq;
byte op6generatorfreqorig;
String pachname;
uint16_t frame = 8;
byte modulation = 0;
unsigned long ido;
unsigned long elozoido = 0;
unsigned long elozoinit = 0;
byte commandByte;
byte noteByte;
byte velocityByte;
byte oldnoteByte[8];
#define FG_SIZE  1024
#define FG_SIZE_I  FG_SIZE - 1
int16_t sinusfg[FG_SIZE];
int16_t fmsinusfg[FG_SIZE];
int16_t haromszogfg[FG_SIZE];
int16_t fureszfg[FG_SIZE];
int16_t negyszogfg[FG_SIZE];
int16_t zajfg[FG_SIZE];
int16_t fmharomszogfg[FG_SIZE];
int16_t fmfureszfg[FG_SIZE];
int16_t fmnegyszogfg[FG_SIZE];
//int16_t fmzajfg[FG_SIZE];
int16_t douplafg[FG_SIZE];
int16_t triplafg[FG_SIZE];
int16_t generator1[FG_SIZE];
int16_t generator2[FG_SIZE];
int16_t generator3[FG_SIZE];
int16_t generator4[FG_SIZE];
int16_t generator5[FG_SIZE];
int16_t generator6[FG_SIZE];
int16_t pwmfg[FG_SIZE];

//int16_t pwmfg2[FG_SIZE];

//int16_t generator7[FG_SIZE];
//int16_t generator8[FG_SIZE];
//byte lfoarray[64] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,};
byte lfoarray[256] =  {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 228, 232, 236, 240, 244, 248, 252, 255, 252, 248, 244, 240, 236, 232, 228, 224, 220, 216, 212, 208, 204, 200, 196, 192, 188, 184, 180, 176, 172, 168, 164, 160, 156, 152, 148, 144, 140, 136, 132, 128, 124, 120, 116, 112, 108, 104, 100, 96, 92, 88, 84, 80, 76, 72, 68, 64, 60, 56, 52, 48, 44, 40, 36, 32, 28, 24, 20, 16, 12, 8, 4, 0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 228, 232, 236, 240, 244, 248, 252, 255, 252, 248, 244, 240, 236, 232, 228, 224, 220, 216, 212, 208, 204, 200, 196, 192, 188, 184, 180, 176, 172, 168, 164, 160, 156, 152, 148, 144, 140, 136, 132, 128, 124, 120, 116, 112, 108, 104, 100, 96, 92, 88, 84, 80, 76, 72, 68, 64, 60, 56, 52, 48, 44, 40, 36, 32, 28, 24, 20, 16, 12, 8, 4 };
//byte lfoarray[1024] ={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
byte lfoarrayindex = 0;
byte lfovolume = 0;
byte lfo2arrayindex = 0;
uint32_t lfo2freq = 0;
byte lfo2volume = 0;
int16_t lfo2value=0;

int16_t fixfreqstep;
uint16_t volume = 1024;
int32_t pich[54] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint32_t sinewaveptr[54] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint32_t sinewave1freq;
uint32_t sinewave2freq;
uint32_t sinewave3freq;
uint32_t sinewave4freq;
uint32_t sinewave5freq;
uint32_t sinewave6freq;
uint32_t sinewave7freq;
uint32_t sinewave8freq;
uint32_t sinewave9freq;
uint32_t sinewave10freq;
uint32_t sinewave11freq;
uint32_t sinewave12freq;
uint32_t sinewave13freq;
uint32_t sinewave14freq;
uint32_t sinewave15freq;
uint32_t sinewave16freq;
uint32_t sinewave17freq;
uint32_t sinewave18freq;
uint32_t sinewave19freq;
uint32_t sinewave20freq;
uint32_t sinewave21freq;
uint32_t sinewave22freq;
uint32_t sinewave23freq;
uint32_t sinewave24freq;
uint32_t sinewave25freq;
uint32_t sinewave26freq;
uint32_t sinewave27freq;
uint32_t sinewave28freq;
uint32_t sinewave29freq;
uint32_t sinewave30freq;
uint32_t sinewave31freq;
uint32_t sinewave32freq;
uint32_t sinewave33freq;
uint32_t sinewave34freq;
uint32_t sinewave35freq;
uint32_t sinewave36freq;
uint32_t sinewave37freq;
uint32_t sinewave38freq;
uint32_t sinewave39freq;
uint32_t sinewave40freq;
uint32_t sinewave41freq;
uint32_t sinewave42freq;
uint32_t sinewave43freq;
uint32_t sinewave44freq;
uint32_t sinewave45freq;
uint32_t sinewave46freq;
uint32_t sinewave47freq;
uint32_t sinewave48freq;
uint32_t sinewave49freq;
uint32_t sinewave50freq;
uint32_t sinewave51freq;
uint32_t sinewave52freq;
uint32_t sinewave53freq;
uint32_t sinewave54freq;
uint32_t wavefreq[8];
uint32_t picheglevel = 16384;
byte pichop1 = 0;
byte pichop2 = 0;
byte pichop3 = 0;
byte pichop4 = 0;
byte pichop5 = 0;
byte pichop6 = 0;
//nullátmenet
bool signwaveop1 = false;
bool signwaveop1last = false;
uint16_t lastop1level[8];
//lfo
int szamlalo = 0;
byte oplfo = 1;
byte lfo1max = 10;
byte lfo1min = 0;
byte lfo1step = 2;
byte lfo1volume = 0;
byte invlfo1volume = 127;
bool lfo1fel = true;
byte oplfo2max = 127;
byte oplfo2min = 0;
byte lfo2step = 1;
byte oplfo4max = 127;
byte oplfo4min = 0;
byte lfo4step = 1;
byte oplfo6max = 127;
byte oplfo6min = 0;
byte lfo6step = 1;

bool op2lfofel = true;
bool op4lfofel = true;
bool op6lfofel = true;
byte lfo4volume = 0;
byte lcdfreq = 8;
//opgenerator A B C D E F
#define egyopgenA(freqmutato1,op1level,lep)  (generator1[freqmutato1 >> lep] *op1level)
#define egyopgenB(freqmutato2,op2level,lep)  (generator2[freqmutato2 >> lep] *op2level)
#define egyopgenC(freqmutato3,op3level,lep)  (generator3[freqmutato3 >> lep] *op3level)
#define egyopgenD(freqmutato4,op4level,lep)  (generator4[freqmutato4 >> lep] *op4level)
#define egyopgenE(freqmutato5,op5level,lep)  (generator5[freqmutato5 >> lep] *op5level)
#define egyopgenF(freqmutato6,op6level,lep)  (generator6[freqmutato6 >> lep] *op6level)

//bufferbe = y + delaybuffer[(delaybufferindex + lfo1volume) % reverbtime];
#define yadddelay(bufferbe,delaybufferindex,lfovolume,reverbtime) (bufferbe + delaybuffer[(delaybufferindex + lfo1volume) % reverbtime])
#define yadddelay2(bufferbe,delaybufferindex2,lfovolume,reverbtime2) (bufferbe + delaybuffer[(delaybufferindex2 + lfo1volume) % reverbtime2])
// y = (freq1 * y + freq2 * bufferbe) >> 14;
#define equalizer(y, freq1, freq2, bufferbe)((freq1 * y + freq2 * bufferbe)/10000)
#define equalizer2(y2, freq1, freq2, bufferbe)((freq1 * y2 + freq2 * bufferbe)/10000)
//(reverblevel2 - 1) * bufferbe / reverblevel2
#define reverblevel1gain(reverblevel, bufferbe)((reverblevel - 1) * bufferbe / reverblevel)
#define reverblevel2gain(reverblevel2, bufferbe)((reverblevel2 - 1) * bufferbe / reverblevel2)
#define equqlizerdelay1(y3,freq1,freq2,elozodelaybufferindex) ((freq1 * y3 + freq2 * delaybuffer[elozodelaybufferindex])/11500)
#define equqlizerdelay2(y4,freq1,freq2,elozodelaybufferindex2) ((freq1 * y4 + freq2 * delaybuffer[elozodelaybufferindex2])/11500)
uint16_t op0gorbeteszt[GORBE_SIZE];
uint16_t tesztmutato = 0;
//1+2modulator
bool fagy = true;
byte lep1 = 22;
byte lep2 = 22;
byte lep3 = 22;
byte lep4 = 22;
byte lep5 = 22;
byte lep6 = 22;

void setup() {
  pinMode(gomb1, INPUT);
  pinMode(gomb2, INPUT);
  pinMode(gomb3, INPUT);
  pinMode(gomb4, INPUT);
  pinMode(gomb5, INPUT);
  pinMode(gomb6, INPUT);
  pinMode(gomb7, INPUT);
  pinMode(gomb8, INPUT);
  Wire.setClock(1000000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("   FM-DuoX7   ");
  delay(800);
  lcd.setCursor(0, 1);
  lcd.print("  DigitalSynth  ");
  delay(400);
  lcd.setCursor(0, 0);
  lcd.print(" Firmvare: 0.41 ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(800);
  MIDI2.begin(MIDI_CHANNEL_OMNI);
  MIDI2.turnThruOff();
  Serial.begin(115200);
  Serial.print("Start serial!");
  Serial2.begin(31250);
  // maxtime = maxtime;
  op1gorbeinit();
  op2gorbeinit();
  op3gorbeinit();
  op5gorbeinit();
  op4gorbeinit();
  op6gorbeinit();
  pichgorbeinit();
  hangokinit();
  sinusinit();
  fmsinusinit();
  haromszoginit();
  negyszoginit();
  fureszoginit();
  zajinit();
  fmharomszoginit();
  fmnegyszoginit();
  fmfureszoginit();
  duplafginit();
  triplafginit();
  pwminit();
  Audio.begin(mintavetelifreqstereo, buffermeret);
  programchange(program);
}
//----------loop----------------

/*
  #pragma GCC pop_options
  #pragma GCC push_options
  #pragma GCC optimize("Os")
*/
short buffer[audiobuffersize];
void loop() {
  while (true) {
    ido = micros();
    serialEvent();
    // serialEventUSB();
    if (ido - elozoido > frame << 9) {
      elozoido = ido;
      if (szamlalo >= lcdfreq) {
        vezerlok(); //read buttons and ptenciometers, controlled the button system
        initprog(); //Step initialize, and refrish lcd end controlled generator system!!!
        szamlalo = 0;
      } else {
        if (szamlalo == 1)
        {
          //lfo generator step:
          lfo1volume = (lfoarray[lfoarrayindex >> 1] >> choruslevel << 1) + 2;
          lfoarrayindex += chorusfreq;
      //  op3volume = op3volumeorig + lfoarray[lfo2arrayindex >> 1] >> lfo2volume;
          lfo2value=lfoarray[lfo2arrayindex >> 1] >> lfo2volume;
          pichband();
          lfo2arrayindex += lfo2freq;


        }
        szamlalo++;
      }
      //gorbe leptetese ill leallitasa
      if (gorbetime[0] == maxtime) {
        gorbetime[0] = -1;

      } else {
        if (gorbetime[0] >= 0) {
          if (gorbetime[0] != maxrelease - 1)  //what is the fuck :)
            gorbetime[0]++;
          op1level[0] = op1gorbe[gorbetime[0]] * op1volume;
          /* uint16_t kiir=op1level[0];
            Serial.print( kiir);
            Serial.print(" ");
          */
          op2level[0] = op2gorbe[gorbetime[0]] * op2volume ;
          op3level[0] = op3gorbe[gorbetime[0]] * op3volume ;
          op4level[0] = op4gorbe[gorbetime[0]] * op4volume ;
          op5level[0] = op5gorbe[gorbetime[0]] * op5volume ;
          op6level[0] = op6gorbe[gorbetime[0]] * op6volume  ;
        }
      }
      if (gorbetime[1] == maxtime) {
        gorbetime[1] = -1;
        //ptrnullaz(1);
      } else {
        if (gorbetime[1] >= 0) {

          if (gorbetime[1] != maxrelease - 1)
            gorbetime[1]++;
          op1level[1] = op1gorbe[gorbetime[1]] * op1volume ;
          op2level[1] = op2gorbe[gorbetime[1]] * op2volume ;
          op3level[1] = op3gorbe[gorbetime[1]] * op3volume ;
          op4level[1] = op4gorbe[gorbetime[1]] * op4volume ;
          op5level[1] = op5gorbe[gorbetime[1]] * op5volume ;
          op6level[1] = op6gorbe[gorbetime[1]] * op6volume ;
        }
      }
      if (gorbetime[2] == maxtime) {
        gorbetime[2] = -1;
        //ptrnullaz(2);
      } else {
        if (gorbetime[2] >= 0) {
          if (gorbetime[2] != maxrelease - 1)
            gorbetime[2]++;
          op1level[2] = op1gorbe[gorbetime[2]] * op1volume ;
          op2level[2] = op2gorbe[gorbetime[2]] * op2volume ;
          op3level[2] = op3gorbe[gorbetime[2]] * op3volume ;
          op4level[2] = op4gorbe[gorbetime[2]] * op4volume ;
          op5level[2] = op5gorbe[gorbetime[2]] * op5volume ;
          op6level[2] = op6gorbe[gorbetime[2]] * op6volume ;
        }
      }
      if (gorbetime[3] == maxtime) {
        gorbetime[3] = -1;
        // ptrnullaz(3);
      } else {
        if (gorbetime[3] >= 0) {
          if (gorbetime[3] != maxrelease - 1)
            gorbetime[3]++;
          op1level[3] = op1gorbe[gorbetime[3]] * op1volume ;
          op2level[3] = op2gorbe[gorbetime[3]] * op2volume ;
          op3level[3] = op3gorbe[gorbetime[3]] * op3volume ;
          op4level[3] = op4gorbe[gorbetime[3]] * op4volume ;
          op5level[3] = op5gorbe[gorbetime[3]] * op5volume ;
          op6level[3] = op6gorbe[gorbetime[3]] * op6volume ;
        }
      }
      if (gorbetime[4] == maxtime) {
        gorbetime[4] = -1;
        //ptrnullaz(4);
      } else {
        if (gorbetime[4] >= 0) {

          if (gorbetime[4] != maxrelease - 1)
            gorbetime[4]++;
          op1level[4] = op1gorbe[gorbetime[4]] * op1volume ;
          op2level[4] = op2gorbe[gorbetime[4]] * op2volume ;
          op3level[4] = op3gorbe[gorbetime[4]] * op3volume ;
          op4level[4] = op4gorbe[gorbetime[4]] * op4volume ;
          op5level[4] = op5gorbe[gorbetime[4]] * op5volume ;
          op6level[4] = op6gorbe[gorbetime[4]] * op6volume ;
        }
      }
      if (gorbetime[5] == maxtime) {
        gorbetime[5] = -1;
        // ptrnullaz(5);
      } else {
        if (gorbetime[5] >= 0) {
          if (gorbetime[5] != maxrelease - 1)
            gorbetime[5]++;
          op1level[5] = op1gorbe[gorbetime[5]] * op1volume  ;
          op2level[5] = op2gorbe[gorbetime[5]] * op2volume ;
          op3level[5] = op3gorbe[gorbetime[5]] * op3volume ;
          op4level[5] = op4gorbe[gorbetime[5]] * op4volume ;
          op5level[5] = op5gorbe[gorbetime[5]] * op5volume;
          op6level[5] = op6gorbe[gorbetime[5]] * op6volume ;
        }
      }

      if (notefixedop1) {
        sinewave1freq = wavefreq[0] * op1generatorfreq ;
        sinewave2freq = wavefreq[1] * op1generatorfreq ;
        sinewave3freq = wavefreq[2] * op1generatorfreq ;
        sinewave4freq = wavefreq[3] * op1generatorfreq ;
        sinewave5freq = wavefreq[4] * op1generatorfreq ;
        sinewave6freq = wavefreq[5] * op1generatorfreq ;
        //sinewave7freq = wavefreq[6] * op1generatorfreq;
        //sinewave8freq = wavefreq[7] * op1generatorfreq;
      } else {
        sinewave1freq = op1generatorfreqfix * op1generatorfreq;
        sinewave2freq = sinewave1freq;
        sinewave3freq = sinewave1freq;
        sinewave4freq = sinewave1freq;
        sinewave5freq = sinewave1freq;
        sinewave6freq = sinewave1freq;
        //sinewave7freq = sinewave1freq;
        //sinewave8freq = sinewave1freq;
      }
      if (notefixedop2) {
        sinewave9freq = wavefreq[0] * op2generatorfreq;
        sinewave10freq = wavefreq[1] * op2generatorfreq;
        sinewave11freq = wavefreq[2] * op2generatorfreq;
        sinewave12freq = wavefreq[3] * op2generatorfreq;
        sinewave13freq = wavefreq[4] * op2generatorfreq;
        sinewave14freq = wavefreq[5] * op2generatorfreq;
        //sinewave15freq = wavefreq[6] * op2generatorfreq;
        //sinewave16freq = wavefreq[7] * op2generatorfreq;
      } else {
        sinewave9freq = op2generatorfreqfix * op2generatorfreq;
        sinewave10freq = sinewave9freq;
        sinewave11freq = sinewave9freq;
        sinewave12freq = sinewave9freq;
        sinewave13freq = sinewave9freq;
        sinewave14freq = sinewave9freq;
        //sinewave15freq = sinewave9freq;
        //sinewave16freq = sinewave9freq;
      }
      if (notefixedop3) {
        sinewave17freq = wavefreq[0] * op3generatorfreq;
        sinewave18freq =  wavefreq[1] * op3generatorfreq;
        sinewave19freq =  wavefreq[2] * op3generatorfreq;
        sinewave20freq =  wavefreq[3] * op3generatorfreq;
        sinewave21freq =  wavefreq[4] * op3generatorfreq;
        sinewave22freq =  wavefreq[5] * op3generatorfreq;
        //sinewave23freq = wavefreq[6] * op3generatorfreq;
        //sinewave24freq = wavefreq[7] * op3generatorfreq;
      } else {
        sinewave17freq = op3generatorfreqfix * op3generatorfreq;
        sinewave18freq = sinewave17freq;
        sinewave19freq = sinewave17freq;
        sinewave20freq = sinewave17freq;
        sinewave21freq = sinewave17freq;
        sinewave22freq = sinewave17freq;
        //sinewave23freq = sinewave17freq;
        //sinewave24freq = sinewave17freq;
      }
      if (notefixedop4) {
        sinewave25freq = wavefreq[0] * op4generatorfreq;
        sinewave26freq = wavefreq[1] * op4generatorfreq;
        sinewave27freq = wavefreq[2] * op4generatorfreq;
        sinewave28freq = wavefreq[3] * op4generatorfreq;
        sinewave29freq = wavefreq[4] * op4generatorfreq;
        sinewave30freq = wavefreq[5] * op4generatorfreq;
        //sinewave31freq = wavefreq[6] * op4generatorfreq;
        //sinewave32freq = wavefreq[7] * op4generatorfreq;
      } else {
        sinewave25freq = op4generatorfreqfix * op4generatorfreq;
        sinewave26freq = sinewave25freq;
        sinewave27freq = sinewave25freq;
        sinewave28freq = sinewave25freq;
        sinewave29freq = sinewave25freq;
        sinewave30freq = sinewave25freq;
        //sinewave31freq = sinewave25freq;
        //sinewave32freq =  sinewave25freq;
      }
      if (notefixedop5) {
        sinewave33freq = wavefreq[0] * op5generatorfreq;
        sinewave34freq = wavefreq[1] * op5generatorfreq;
        sinewave35freq = wavefreq[2] * op5generatorfreq;
        sinewave36freq = wavefreq[3] * op5generatorfreq;
        sinewave37freq = wavefreq[4] * op5generatorfreq;
        sinewave38freq = wavefreq[5] * op5generatorfreq;
        // sinewave39freq = wavefreq[6] * op5generatorfreq;
        //sinewave40freq = wavefreq[7] * op5generatorfreq;
      } else {
        sinewave33freq = op5generatorfreqfix * op5generatorfreq;
        sinewave34freq =  sinewave33freq;
        sinewave35freq =  sinewave33freq;
        sinewave36freq =  sinewave33freq;
        sinewave37freq =  sinewave33freq;
        sinewave38freq =  sinewave33freq;
        //sinewave39freq = sinewave33freq;
        //sinewave40freq = sinewave33freq;
      }
      if (notefixedop6) {
        sinewave41freq = wavefreq[0] * op6generatorfreq;
        sinewave42freq = wavefreq[1] * op6generatorfreq;
        sinewave43freq = wavefreq[2] * op6generatorfreq;
        sinewave44freq = wavefreq[3] * op6generatorfreq;
        sinewave45freq = wavefreq[4] * op6generatorfreq;
        sinewave46freq = wavefreq[5] * op6generatorfreq;
        // sinewave47freq = wavefreq[6] * op6generatorfreq;
        // sinewave48freq = wavefreq[7] * op6generatorfreq;
      } else {
        sinewave41freq = op6generatorfreqfix * op6generatorfreq;
        sinewave42freq = sinewave41freq;
        sinewave43freq = sinewave41freq;
        sinewave44freq = sinewave41freq;
        sinewave45freq = sinewave41freq;
        sinewave46freq = sinewave41freq;
        // sinewave47freq = sinewave41freq;
        //sinewave48freq =  sinewave41freq;
      }
      //picheg
      switch (pichop1) {
        case 0:
          pich[1] = 0;
          pich[2] = 0;
          pich[3] = 0;
          pich[4] = 0;
          pich[5] = 0;
          pich[6] = 0;
          break;
        case 1:
          pich[1] = (pichgorbe[gorbetime[0]]) * picheglevel;
          pich[2] = (pichgorbe[gorbetime[1]]) * picheglevel;
          pich[3] = (pichgorbe[gorbetime[2]]) * picheglevel;
          pich[4] = (pichgorbe[gorbetime[3]]) * picheglevel;
          pich[5] = (pichgorbe[gorbetime[4]]) * picheglevel;
          pich[6] = (pichgorbe[gorbetime[5]]) * picheglevel;
          break;
        case 2:
          pich[1] = ~((pichgorbe[gorbetime[0]]) * picheglevel - 1);
          pich[2] = ~((pichgorbe[gorbetime[1]]) * picheglevel - 1);
          pich[3] = ~((pichgorbe[gorbetime[2]]) * picheglevel - 1);
          pich[4] = ~((pichgorbe[gorbetime[3]]) * picheglevel - 1);
          pich[5] = ~((pichgorbe[gorbetime[4]]) * picheglevel - 1);
          pich[6] = ~((pichgorbe[gorbetime[5]]) * picheglevel - 1);
          break;
      }
      switch (pichop2) {
        case 0:
          pich[9] = 0;
          pich[10] = 0;
          pich[11] = 0;
          pich[12] = 0;
          pich[13] = 0;
          pich[14] = 0;
          break;
        case 1:
          pich[9]  = ( pichgorbe[gorbetime[0]]) * picheglevel;
          pich[10] = (pichgorbe[gorbetime[1]]) * picheglevel;
          pich[11] = (pichgorbe[gorbetime[2]]) * picheglevel;
          pich[12] = (pichgorbe[gorbetime[3]]) * picheglevel;
          pich[13] = (pichgorbe[gorbetime[4]]) * picheglevel;
          pich[14] = (pichgorbe[gorbetime[5]]) * picheglevel;
          break;
        case 2:
          pich[9]  = ~((pichgorbe[gorbetime[0]]) * picheglevel - 1);
          pich[10] = ~((pichgorbe[gorbetime[1]]) * picheglevel - 1);
          pich[11] = ~((pichgorbe[gorbetime[2]]) * picheglevel - 1);
          pich[12] = ~((pichgorbe[gorbetime[3]]) * picheglevel - 1);
          pich[13] = ~((pichgorbe[gorbetime[4]]) * picheglevel - 1);
          pich[14] = ~((pichgorbe[gorbetime[5]]) * picheglevel - 1);
          break;
      }
      switch (pichop3) {
        case 0:
          pich[17] = 0;
          pich[18] = 0;
          pich[19] = 0;
          pich[20] = 0;
          pich[21] = 0;
          pich[22] = 0;
          break;
        case 1:
          pich[17] = (pichgorbe[gorbetime[0]]) * picheglevel;
          pich[18] = (pichgorbe[gorbetime[1]]) * picheglevel;
          pich[19] = (pichgorbe[gorbetime[2]]) * picheglevel;
          pich[20] = (pichgorbe[gorbetime[3]]) * picheglevel;
          pich[21] = (pichgorbe[gorbetime[4]]) * picheglevel;
          pich[22] = (pichgorbe[gorbetime[5]]) * picheglevel;
          break;
        case 2:
          pich[17] = ~((pichgorbe[gorbetime[0]]) * picheglevel - 1);
          pich[18] = ~((pichgorbe[gorbetime[1]]) * picheglevel - 1);
          pich[19] = ~((pichgorbe[gorbetime[2]]) * picheglevel - 1);
          pich[20] = ~((pichgorbe[gorbetime[3]]) * picheglevel - 1);
          pich[21] = ~((pichgorbe[gorbetime[4]]) * picheglevel - 1);
          pich[22] = ~((pichgorbe[gorbetime[5]]) * picheglevel - 1);
          break;
      }
      switch (pichop4) {
        case 0:
          pich[25] = 0;
          pich[26] = 0;
          pich[27] = 0;
          pich[28] = 0;
          pich[29] = 0;
          pich[30] = 0;
          break;
        case 1:
          pich[25] = (pichgorbe[gorbetime[0]]) * picheglevel;
          pich[26] = (pichgorbe[gorbetime[1]]) * picheglevel;
          pich[27] = (pichgorbe[gorbetime[2]]) * picheglevel;
          pich[28] = (pichgorbe[gorbetime[3]]) * picheglevel;
          pich[29] = (pichgorbe[gorbetime[4]]) * picheglevel;
          pich[30] = (pichgorbe[gorbetime[5]]) * picheglevel;
          break;
        case 2:
          pich[25] = ~((pichgorbe[gorbetime[0]]) * picheglevel - 1);
          pich[26] = ~((pichgorbe[gorbetime[1]]) * picheglevel - 1);
          pich[27] = ~((pichgorbe[gorbetime[2]]) * picheglevel - 1);
          pich[28] = ~((pichgorbe[gorbetime[3]]) * picheglevel - 1);
          pich[29] = ~((pichgorbe[gorbetime[4]]) * picheglevel - 1);
          pich[30] = ~((pichgorbe[gorbetime[5]]) * picheglevel - 1);
          break;
      }
      switch (pichop5) {
        case 0:
          pich[33] = 0;
          pich[34] = 0;
          pich[35] = 0;
          pich[36] = 0;
          pich[37] = 0;
          pich[38] = 0;
          break;
        case 1:
          pich[33] = (pichgorbe[gorbetime[0]]) * picheglevel;
          pich[34] = (pichgorbe[gorbetime[1]]) * picheglevel;
          pich[35] = (pichgorbe[gorbetime[2]]) * picheglevel;
          pich[36] = (pichgorbe[gorbetime[3]]) * picheglevel;
          pich[37] = (pichgorbe[gorbetime[4]]) * picheglevel;
          pich[38] = (pichgorbe[gorbetime[5]]) * picheglevel;
          break;
        case 2:
          pich[33] = ~((pichgorbe[gorbetime[0]]) * picheglevel - 1);
          pich[34] = ~((pichgorbe[gorbetime[1]]) * picheglevel - 1);
          pich[35] = ~((pichgorbe[gorbetime[2]]) * picheglevel - 1);
          pich[36] = ~((pichgorbe[gorbetime[3]]) * picheglevel - 1);
          pich[37] = ~((pichgorbe[gorbetime[4]]) * picheglevel - 1);
          pich[38] = ~((pichgorbe[gorbetime[5]]) * picheglevel - 1);
          break;
      }
      switch (pichop6) {
        case 0:
          pich[41] = 0;
          pich[42] = 0;
          pich[43] = 0;
          pich[44] = 0;
          pich[45] = 0;
          pich[46] = 0;
          break;
        case 1:
          pich[41] = (pichgorbe[gorbetime[0]]) * picheglevel;
          pich[42] = (pichgorbe[gorbetime[1]]) * picheglevel;
          pich[43] = (pichgorbe[gorbetime[2]]) * picheglevel;
          pich[44] = (pichgorbe[gorbetime[3]]) * picheglevel;
          pich[45] = (pichgorbe[gorbetime[4]]) * picheglevel;
          pich[46] = (pichgorbe[gorbetime[5]]) * picheglevel;
          break;
        case 2:
          pich[41] = ~((pichgorbe[gorbetime[0]]) * picheglevel - 1);
          pich[42] = ~((pichgorbe[gorbetime[1]]) * picheglevel - 1);
          pich[43] = ~((pichgorbe[gorbetime[2]]) * picheglevel - 1);
          pich[44] = ~((pichgorbe[gorbetime[3]]) * picheglevel - 1);
          pich[45] = ~((pichgorbe[gorbetime[4]]) * picheglevel - 1);
          pich[46] = ~((pichgorbe[gorbetime[5]]) * picheglevel - 1);
          break;
      }
    }
    for ( bufferindex = 0; bufferindex < buffermeret; bufferindex++) {
      bufferbe = 0;
      if ((bufferindex & 0x0001) == 1) {
        //Left
        switch (alg) {
          case 1:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenA(sinewaveptr[1] + egyopgenB(sinewaveptr[9] + egyopgenC(sinewaveptr[17] + egyopgenD(sinewaveptr[25], op4level[0], lep4), op3level[0], lep3), op2level[0], lep2), op1level[0], lep1);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[2] + egyopgenB(sinewaveptr[10] + egyopgenC(sinewaveptr[18] + egyopgenD(sinewaveptr[26], op4level[1], lep4), op3level[1], lep3), op2level[1], lep2), op1level[1], lep1);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[3] + egyopgenB(sinewaveptr[11] + egyopgenC(sinewaveptr[19] + egyopgenD(sinewaveptr[27], op4level[2], lep4), op3level[2], lep3), op2level[2], lep2), op1level[2], lep1);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[4] + egyopgenB(sinewaveptr[12] + egyopgenC(sinewaveptr[20] + egyopgenD(sinewaveptr[28], op4level[3], lep4), op3level[3], lep3), op2level[3], lep2), op1level[3], lep1);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[5] + egyopgenB(sinewaveptr[13] + egyopgenC(sinewaveptr[21] + egyopgenD(sinewaveptr[29], op4level[4], lep4), op3level[4], lep3), op2level[4], lep2), op1level[4], lep1);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[6] + egyopgenB(sinewaveptr[14] + egyopgenC(sinewaveptr[22] + egyopgenD(sinewaveptr[30], op4level[5], lep2), op3level[5], lep3), op2level[5], lep2), op1level[5], lep1);
            }
            break;
          //algoritmus1vege
          //algoritmus2
          case 2:
            if (gorbetime[0] > 0 ) {
              average = (old0[0] + old1[0]) >> 1;
              old1[0] = old0[0];
              //old0[0] = egyopgenB(sinewaveptr[9] + (average << feedback_level), op2level[0], lep2);
              old0[0] =  egyopgenA(sinewaveptr[1] + egyopgenB(sinewaveptr[9] + (average << feedback_level), op2level[0], lep2), op1level[0], lep1);
              bufferbe +=  old0[0];
              //   bufferbe +=   egyopgenA(sinewaveptr[1] + old0[0], op1level[0], lep1);
              // bufferbe +=   egyopgenA(sinewaveptr[1] + egyopgenB(sinewaveptr[9], op2level[0], lep2), op1level[0], lep1);
              bufferbe +=   egyopgenC(sinewaveptr[17] + egyopgenD(sinewaveptr[25], op4level[0], lep4), op3level[0], lep3);
            }
            
            if (gorbetime[1] > 0) {
              average = (old0[1] + old1[1]) >> 1;
              old1[1] = old0[1];
              // old0[1] = egyopgenB(sinewaveptr[10] + (average << feedback_level), op2level[1], lep2);
              old0[1] = egyopgenA(sinewaveptr[2] + egyopgenB(sinewaveptr[10] + (average << feedback_level), op2level[1], lep2), op1level[1], lep1);
              bufferbe +=  old0[1];
              //  bufferbe +=   egyopgenA(sinewaveptr[2] + old0[1], op1level[1], lep1);
              // bufferbe +=   egyopgenA(sinewaveptr[2] + egyopgenB(sinewaveptr[10], op2level[1], lep2), op1level[1], lep1);
              bufferbe +=   egyopgenC(sinewaveptr[18] + egyopgenD(sinewaveptr[26], op4level[1], lep4), op3level[1], lep3);
            }
            
            if (gorbetime[2] > 0) {
              average = (old0[2] + old1[2]) >> 1;
              old1[2] = old0[2];
              // old0[2] = egyopgenB(sinewaveptr[11] + (average << feedback_level), op2level[2], lep2);
              old0[2] = egyopgenA(sinewaveptr[3] + egyopgenB(sinewaveptr[11] + (average << feedback_level), op2level[2], lep2), op1level[2], lep1);
              bufferbe +=  old0[2];
              // bufferbe +=   egyopgenA(sinewaveptr[3] + old0[2], op1level[2], lep1);
              //    bufferbe +=   egyopgenA(sinewaveptr[3] + egyopgenB(sinewaveptr[11], op2level[2], lep2), op1level[2], lep1);
              bufferbe +=   egyopgenC(sinewaveptr[19] + egyopgenD(sinewaveptr[27], op4level[2], lep4), op3level[2], lep3);
            }
            
            if (gorbetime[3] > 0) {
              average = (old0[3] + old1[3]) >> 1;
              old1[3] = old0[3];
              //old0[3] = egyopgenB(sinewaveptr[12] + (average << feedback_level), op2level[3], lep2);
              old0[3] = egyopgenA(sinewaveptr[4] + egyopgenB(sinewaveptr[12] + (average << feedback_level), op2level[3], lep2), op1level[3], lep1);
              bufferbe +=  old0[3];
              // bufferbe +=   egyopgenA(sinewaveptr[4] + old0[3], op1level[3], lep1);
              // bufferbe +=   egyopgenA(sinewaveptr[4] + egyopgenB(sinewaveptr[12], op2level[3], lep2), op1level[3], lep1);
              bufferbe +=   egyopgenC(sinewaveptr[20] + egyopgenD(sinewaveptr[28], op4level[3], lep4), op3level[3], lep3);
            }
            
            if (gorbetime[4] > 0) {
              average = (old0[4] + old1[4]) >> 1;
              old1[4] = old0[4];
              // old0[4] = egyopgenB(sinewaveptr[13] + (average << feedback_level), op2level[4], lep2);
              old0[4] = egyopgenA(sinewaveptr[5] + egyopgenB(sinewaveptr[13] + (average << feedback_level), op2level[4], lep2), op1level[4], lep1);
              bufferbe +=  old0[4];
              // bufferbe +=   egyopgenA(sinewaveptr[5] + old0[4], op1level[4], lep1);
              // bufferbe +=   egyopgenA(sinewaveptr[5] + egyopgenB(sinewaveptr[13], op2level[4], lep2), op1level[4], lep1);
              bufferbe +=   egyopgenC(sinewaveptr[21] + egyopgenD(sinewaveptr[29], op4level[4], lep4), op3level[4], lep3);
            }
            
            if (gorbetime[5] > 0) {
              average = (old0[5] + old1[5]) >> 1;
              old1[5] = old0[5];
              // old0[5] = egyopgenB(sinewaveptr[14] + (average << feedback_level), op2level[5], lep2);
              old0[5] =  egyopgenA(sinewaveptr[6] + egyopgenB(sinewaveptr[14] + (average << feedback_level), op2level[5], lep2), op1level[5], lep1);
               bufferbe +=  old0[5];
            // bufferbe +=   egyopgenA(sinewaveptr[6] + old0[5], op1level[5], lep1);
            // bufferbe +=   egyopgenA(sinewaveptr[6] + egyopgenB(sinewaveptr[14], op2level[5], lep2), op1level[5], lep1);
            bufferbe +=   egyopgenC(sinewaveptr[22] + egyopgenD(sinewaveptr[30], op4level[5], lep4), op3level[5], lep3);
            }
            
                       break;
          //algoritmus3
          case 3:
            //this is fantastic!!!! very good quality clear sound!!!
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenA(sinewaveptr[1] + egyopgenB(sinewaveptr[9] + egyopgenC(sinewaveptr[17], op3level[0], lep3), op2level[0], lep2), op1level[0], lep1);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[2] + egyopgenB(sinewaveptr[10] + egyopgenC(sinewaveptr[18], op3level[1], lep3), op2level[1], lep2), op1level[1], lep1);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[3] + egyopgenB(sinewaveptr[11] + egyopgenC(sinewaveptr[19], op3level[2], lep3), op2level[2], lep2), op1level[2], lep1);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[4] + egyopgenB(sinewaveptr[12] + egyopgenC(sinewaveptr[20], op3level[3], lep3), op2level[3], lep2), op1level[3], lep1);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[5] + egyopgenB(sinewaveptr[13] + egyopgenC(sinewaveptr[21], op3level[4], lep3), op2level[4], lep2), op1level[4], lep1);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[6] + egyopgenB(sinewaveptr[14] + egyopgenC(sinewaveptr[22], op3level[5], lep3), op2level[5], lep2), op1level[5], lep1);
            }
            break;
          //algoritmus4
          case 4:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenA(sinewaveptr[1] + egyopgenB(sinewaveptr[9] , op2level[0], lep2) + egyopgenC(sinewaveptr[17], op3level[0], lep3), op1level[0], lep1);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[2] + egyopgenB(sinewaveptr[10] , op2level[1], lep2) + egyopgenC(sinewaveptr[18], op3level[1], lep3), op1level[1], lep1);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[3] + egyopgenB(sinewaveptr[11] , op2level[2], lep2) + egyopgenC(sinewaveptr[19], op3level[2], lep3), op1level[2], lep1);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[4] + egyopgenB(sinewaveptr[12] , op2level[3], lep2) + egyopgenC(sinewaveptr[20], op3level[3], lep3), op1level[3], lep1);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[5] + egyopgenB(sinewaveptr[13] , op2level[4], lep2) + egyopgenC(sinewaveptr[21], op3level[4], lep3), op1level[4], lep1);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[6] + egyopgenB(sinewaveptr[14] , op2level[5], lep2) + egyopgenC(sinewaveptr[22], op3level[5], lep3), op1level[5], lep1);
            }
            break;
          case 5:
            //algoritmus5 pwm
            if (gorbetime[0] > 0 ) {
              kitoltes0 = (op1gorbe[gorbetime[0]] >> 3) + 22;
              if (kitoltes0 > 40) {
                kitoltes0 = 40;
              }
              {
                if (kitoltes0 >= 31) {
                  if (sinewaveptr[1] >> kitoltes0 - ((kitoltes0 - 31) << 1) == 0)
                  {
                    bufferbe -= op1level[0] >> 3;
                  }
                  else
                  {
                    bufferbe += op1level[0] >> 3;
                  }
                }
                else
                {
                  if (sinewaveptr[1] >> kitoltes0 == 0)
                  {
                    bufferbe += op1level[0] >> 3;
                  }
                  else
                  {
                    bufferbe -= op1level[0] >> 3;
                  }
                }
                //Serial.print( String(kitoltes0) + " buf: ");
                //   Serial.println( String(bufferbe) + " ");
              }
            }
            if (gorbetime[1] > 0 ) {
              kitoltes1 = (op1gorbe[gorbetime[1]] >> 3) + 22;
              if (kitoltes1 > 40) {
                kitoltes1 = 40;
              }
              if (kitoltes1 >= 31) {
                if (sinewaveptr[2] >> kitoltes1 - ((kitoltes1 - 31) << 1) == 0)
                {
                  bufferbe -= op1level[1] >> 3;
                }
                else
                {
                  bufferbe += op1level[1] >> 3;
                }
              }
              else
              {
                if (sinewaveptr[2] >> kitoltes1 == 0)
                {
                  bufferbe += op1level[1] >> 3;
                }
                else
                {
                  bufferbe -= op1level[1] >> 3;
                }
              }
            }
            if (gorbetime[2] > 0 ) {
              kitoltes2 = (op1gorbe[gorbetime[2]] >> 3) + 22;
              if (kitoltes2 > 40) {
                kitoltes2 = 40;
              }
              if (kitoltes2 >= 31) {
                if (sinewaveptr[3] >> kitoltes2 - ((kitoltes2 - 31) << 1) == 0)
                {
                  bufferbe -= op1level[2] >> 3;
                }
                else
                {
                  bufferbe += op1level[2] >> 3;
                }
              }
              else
              {
                if (sinewaveptr[3] >> kitoltes2 == 0)
                {
                  bufferbe += op1level[2] >> 3;
                }
                else
                {
                  bufferbe += op1level[2] >> 3;
                }
              }
            }
            if (gorbetime[3] >= 0 ) {
              kitoltes3 = (op1gorbe[gorbetime[3]] >> 3) + 22;
              if (kitoltes3 > 40) {
                kitoltes3 = 40;
              }
              if (kitoltes3 > 31) {
                if (sinewaveptr[4] >> kitoltes3 - ((kitoltes3 - 31) << 1) == 0)
                {
                  bufferbe -= op1level[3] >> 3;
                }
                else
                {
                  bufferbe +=  op1level[3] >> 3;
                }
              }
              else
              {
                if (sinewaveptr[4] >> kitoltes3 == 0)
                {
                  bufferbe += op1level[3] >> 3;
                }
                else
                {
                  bufferbe -=  op1level[3] >> 3;
                }
              }
            }
            if (gorbetime[4] > 0 ) {
              int kitoltes4 = (op1gorbe[gorbetime[4]] >> 3) + 22;

              if (kitoltes4 > 40) {
                kitoltes4 = 40;
              }
              if (kitoltes4 >= 31) {
                if (sinewaveptr[5] >> kitoltes4 - ((kitoltes4 - 31) << 1) == 0)
                {
                  bufferbe -= op1level[4] >> 3;
                }
                else
                {
                  bufferbe +=  op1level[4] >> 3;
                }
              }
              else
              {
                if (sinewaveptr[5] >> kitoltes4 == 0)
                {
                  bufferbe +=  op1level[4] >> 3;
                }
                else
                {
                  bufferbe -=   op1level[4] >> 3;
                }
              }
            }
            if (gorbetime[5] > 0 ) {
              kitoltes5 = (op1gorbe[gorbetime[5]] >> 3) + 22;
              if (kitoltes5 > 40) {
                kitoltes5 = 40;
              }

              if (kitoltes5 >= 31) {

                if (sinewaveptr[6] >> kitoltes5 - ((kitoltes5 - 31) << 1) == 0)
                {
                  bufferbe -= op1level[5] >> 3;
                }
                else
                {
                  bufferbe += op1level[5] >> 3;
                }

              }
              else
              {
                if (sinewaveptr[6] >> kitoltes5 == 0)
                {
                  bufferbe += op1level[5] >> 3;
                }
                else
                {
                  bufferbe -= op1level[5] >> 3;
                }
              }
            }
            //   bufferbe-=10000;
            break;
          case 6:
            if (gorbetime[0] > 0 ) {
              average = (old0[0] + old1[0]) >> 1;
              old1[0] = old0[0];
              old0[0] = egyopgenA(sinewaveptr[1] + (average << feedback_level), op1level[0], lep1);
              bufferbe +=  old0[0];
              // bufferbe +=   egyopgenA(sinewaveptr[1], op1level[0], lep1);
              bufferbe +=   egyopgenB(sinewaveptr[9], op2level[0], lep2);
              bufferbe +=   egyopgenC(sinewaveptr[17], op3level[0], lep3);
            }
            if (gorbetime[1] > 0) {
              average = (old0[1] + old1[1]) >> 1;
              old1[1] = old0[1];
              old0[1] = egyopgenA(sinewaveptr[2] + (average << feedback_level), op1level[1], lep1);
              bufferbe +=  old0[1];

              //bufferbe +=   egyopgenA(sinewaveptr[2] , op1level[1], lep1);
              bufferbe +=   egyopgenB(sinewaveptr[10], op2level[1], lep2);
              bufferbe +=   egyopgenC(sinewaveptr[18], op3level[1], lep3);
            }
            if (gorbetime[2] > 0) {
              average = (old0[2] + old1[2]) >> 1;
              old1[2] = old0[2];
              old0[2] = egyopgenA(sinewaveptr[3] + (average << feedback_level), op1level[2], lep1);
              bufferbe +=  old0[2];
              //  bufferbe +=   egyopgenA(sinewaveptr[3] , op1level[2], lep1);
              bufferbe +=   egyopgenB(sinewaveptr[11], op2level[2], lep2);
              bufferbe +=   egyopgenC(sinewaveptr[19], op3level[2], lep3);

            }
            if (gorbetime[3] > 0) {
              average = (old0[3] + old1[3]) >> 1;
              old1[3] = old0[3];
              old0[3] = egyopgenA(sinewaveptr[4] + (average << feedback_level), op1level[3], lep1);
              bufferbe +=  old0[3];
              //   bufferbe +=   egyopgenA(sinewaveptr[4] , op1level[3], lep1);
              bufferbe +=   egyopgenB(sinewaveptr[12], op2level[3], lep2);
              bufferbe +=   egyopgenC(sinewaveptr[20], op3level[3], lep3);
            }
            if (gorbetime[4] > 0) {
              average = (old0[4] + old1[4]) >> 1;
              old1[4] = old0[4];
              old0[4] = egyopgenA(sinewaveptr[5] + (average << feedback_level), op1level[4], lep1);
              bufferbe +=  old0[4];
              //  bufferbe +=   egyopgenA(sinewaveptr[5] , op1level[4], lep1);
              bufferbe +=   egyopgenB(sinewaveptr[13], op2level[4], lep2);
              bufferbe +=   egyopgenC(sinewaveptr[21], op3level[4], lep3);
            }
            if (gorbetime[5] > 0) {
              average = (old0[5] + old1[5]) >> 1;
              old1[5] = old0[5];
              old0[5] = egyopgenA(sinewaveptr[6] + (average << feedback_level), op1level[5], lep1);
              bufferbe +=  old0[5];
              //  bufferbe +=   egyopgenA(sinewaveptr[6] , op1level[5], lep1);
              bufferbe +=   egyopgenB(sinewaveptr[14], op2level[5], lep2);
              bufferbe +=   egyopgenC(sinewaveptr[22], op3level[5], lep3);
            }
            break;
        }
        sinewaveptr[1] += sinewave1freq + pich[1];
        sinewaveptr[2] += sinewave2freq + pich[2];
        sinewaveptr[3] += sinewave3freq + pich[3];
        sinewaveptr[4] += sinewave4freq + pich[4];
        sinewaveptr[5] += sinewave5freq + pich[5];
        sinewaveptr[6] += sinewave6freq + pich[6];
        //   sinewaveptr[7] += sinewave7freq + pich[7];
        //   sinewaveptr[8] += sinewave8freq + pich[8];
        sinewaveptr[9] += sinewave9freq + pich[9];
        sinewaveptr[10] += sinewave10freq + pich[10];
        sinewaveptr[11] += sinewave11freq + pich[11];
        sinewaveptr[12] += sinewave12freq + pich[12];
        sinewaveptr[13] += sinewave13freq + pich[13];
        sinewaveptr[14] += sinewave14freq + pich[14];
        //    sinewaveptr[15] += sinewave15freq + pich[15];
        //     sinewaveptr[16] += sinewave16freq + pich[16];
        sinewaveptr[17] += sinewave17freq + pich[17];
        sinewaveptr[18] += sinewave18freq + pich[18];
        sinewaveptr[19] += sinewave19freq + pich[19];
        sinewaveptr[20] += sinewave20freq + pich[20];
        sinewaveptr[21] += sinewave21freq + pich[21];
        sinewaveptr[22] += sinewave22freq + pich[22];
        //   sinewaveptr[23] += sinewave23freq + pich[23];
        //   sinewaveptr[24] += sinewave24freq + pich[24];
        sinewaveptr[25] += sinewave25freq + pich[25];
        sinewaveptr[26] += sinewave26freq + pich[26];
        sinewaveptr[27] += sinewave27freq + pich[27] ;
        sinewaveptr[28] += sinewave28freq + pich[28];
        sinewaveptr[29] += sinewave29freq + pich[29];
        sinewaveptr[30] += sinewave30freq + pich[30] ;
        //      sinewaveptr[31] += sinewave31freq + pich[31];
        //      sinewaveptr[32] += sinewave32freq + pich[32];
        sinewaveptr[33] += sinewave33freq + pich[33];
        sinewaveptr[34] += sinewave34freq + pich[34];
        sinewaveptr[35] += sinewave35freq + pich[35];
        sinewaveptr[36] += sinewave36freq + pich[36];
        sinewaveptr[37] += sinewave37freq + pich[37];
        sinewaveptr[38] += sinewave38freq + pich[38];
        //     sinewaveptr[39] += sinewave39freq + pich[39];
        //     sinewaveptr[40] += sinewave40freq + pich[40];
        sinewaveptr[41] += sinewave41freq + pich[41];
        sinewaveptr[42] += sinewave42freq + pich[42];
        sinewaveptr[43] += sinewave43freq + pich[43];
        sinewaveptr[44] += sinewave44freq + pich[44];
        sinewaveptr[45] += sinewave45freq + pich[45];
        sinewaveptr[46] += sinewave46freq + pich[46];
        //     sinewaveptr[47] += sinewave47freq + pich[47];
        //     sinewaveptr[48] += sinewave48freq + pich[48];
        //     sinewaveptr[49] += sinewave49freq + pich[49];
        //     sinewaveptr[50] += sinewave50freq + pich[50];
        //     sinewaveptr[51] += sinewave51freq + pich[51] ;
        //      sinewaveptr[52] += sinewave52freq + pich[52];
        //     sinewaveptr[53] += sinewave53freq + pich[53];
        //      sinewaveptr[54] += sinewave54freq + pich[54] ;


        bufferbe = bufferbe >> level;
        //EQ +REVERB Left
        //y3= equqlizerdelay1(y3,freq1,freq2,elozodelaybufferindex);
        y3 = (freq1 * y3 + freq2 * delaybuffer[elozodelaybufferindex]) / 11500;
        delaybuffer[elozodelaybufferindex] = y3;

        //y = equalizer(y, freq1, freq2, bufferbe);
        bufferbe =   yadddelay(bufferbe, elozodelaybufferindex, lfo1volume, reverbtime);
        delaybuffer[delaybufferindex] = reverblevel1gain(reverblevel, bufferbe);
        elozodelaybufferindex = delaybufferindex;
        delaybufferindex += 2;
        if (delaybufferindex >= reverbtime) {
          delaybufferindex = 0;
        }
        buffer[ bufferindex] = bufferbe;
      }
      else {
        //Right
        switch (alg) {
          case 1:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenE(sinewaveptr[33] + egyopgenF(sinewaveptr[41], op6level[0], lep6), op5level[0], lep5);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[34] + egyopgenF(sinewaveptr[42], op6level[1], lep6), op5level[1], lep5);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[35] + egyopgenF(sinewaveptr[43], op6level[2], lep6), op5level[2], lep5);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[36] + egyopgenF(sinewaveptr[44], op6level[3], lep6), op5level[3], lep5);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[37] + egyopgenF(sinewaveptr[45], op6level[4], lep6), op5level[4], lep5);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[38] + egyopgenF(sinewaveptr[46], op6level[5], lep6), op5level[5], lep5);
            }
            break;
          case 2:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenE(sinewaveptr[33] + egyopgenF(sinewaveptr[41], op6level[0], lep6), op5level[0], lep5);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[34] + egyopgenF(sinewaveptr[42], op6level[1], lep6), op5level[1], lep5);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[35] + egyopgenF(sinewaveptr[43], op6level[2], lep6), op5level[2], lep5);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[36] + egyopgenF(sinewaveptr[44], op6level[3], lep6), op5level[3], lep5);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[37] + egyopgenF(sinewaveptr[45], op6level[4], lep6), op5level[4], lep5);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[38] + egyopgenF(sinewaveptr[46], op6level[5], lep6), op5level[5], lep5);
            }
            break;
          case 3:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenD(sinewaveptr[25] + egyopgenE(sinewaveptr[33] + egyopgenF(sinewaveptr[41], op6level[0], lep6), op5level[0], lep5), op4level[0], lep4);
              //bufferbe +=   egyopgenE(sinewaveptr[33], op5level[0], lep5);
              //bufferbe +=   egyopgenF(sinewaveptr[41], op6level[0], lep6);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[26] + egyopgenE(sinewaveptr[34] + egyopgenF(sinewaveptr[42], op6level[1], lep6), op5level[1], lep5), op4level[1], lep4);
              // bufferbe +=   egyopgenE(sinewaveptr[34], op5level[1], lep5);
              // bufferbe +=   egyopgenF(sinewaveptr[42], op6level[1], lep6);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[27] + egyopgenE(sinewaveptr[35] + egyopgenF(sinewaveptr[43], op6level[2], lep6), op5level[2], lep5), op4level[2], lep4);
              // bufferbe +=   egyopgenE(sinewaveptr[35], op5level[2], lep5);
              // bufferbe +=   egyopgenF(sinewaveptr[43], op6level[2], lep6);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[28] + egyopgenE(sinewaveptr[36] + egyopgenF(sinewaveptr[44], op6level[3], lep6), op5level[3], lep5), op4level[3], lep4);
              //   bufferbe +=   egyopgenE(sinewaveptr[36], op5level[3], lep5);
              //  bufferbe +=   egyopgenF(sinewaveptr[44], op6level[3], lep6);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[29] + egyopgenE(sinewaveptr[37] + egyopgenF(sinewaveptr[45], op6level[4], lep6), op5level[4], lep5), op4level[4], lep4);
              // bufferbe +=   egyopgenE(sinewaveptr[37], op5level[4], lep5);
              // bufferbe +=   egyopgenF(sinewaveptr[45], op6level[4], lep6);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[30] + egyopgenE(sinewaveptr[38] + egyopgenF(sinewaveptr[46], op6level[5], lep6), op5level[5], lep5), op4level[5], lep4);
              //  bufferbe +=   egyopgenE(sinewaveptr[38], op5level[5], lep5);
              //  bufferbe +=   egyopgenF(sinewaveptr[46], op6level[5], lep6);
            }
            break;
          case 4:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenD(sinewaveptr[25] + egyopgenE(sinewaveptr[33] , op5level[0], lep5) + egyopgenF(sinewaveptr[41], op6level[0], lep6), op4level[0], lep4);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[26] + egyopgenE(sinewaveptr[34] , op5level[1], lep5) + egyopgenF(sinewaveptr[42], op6level[1], lep6), op4level[1], lep4);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[27] + egyopgenE(sinewaveptr[35] , op5level[2], lep5) + egyopgenF(sinewaveptr[43], op6level[2], lep6), op4level[2], lep4);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[28] + egyopgenE(sinewaveptr[36] , op5level[3], lep5) + egyopgenF(sinewaveptr[44], op6level[3], lep6), op4level[3], lep4);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[29] + egyopgenE(sinewaveptr[37] , op5level[4], lep5) + egyopgenF(sinewaveptr[45], op6level[4], lep6), op4level[4], lep4);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[30] + egyopgenE(sinewaveptr[38] , op5level[5], lep5) + egyopgenF(sinewaveptr[46], op6level[5], lep6), op4level[5], lep4);
            }
            break;
          //algoritmus5 pwm
          case 5:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenE(sinewaveptr[33] + egyopgenF(sinewaveptr[41], op6level[0], lep6), op5level[0], lep5);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[34] + egyopgenF(sinewaveptr[42], op6level[1], lep6), op5level[1], lep5);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[35] + egyopgenF(sinewaveptr[43], op6level[2], lep6), op5level[2], lep5);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[36] + egyopgenF(sinewaveptr[44], op6level[3], lep6), op5level[3], lep5);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[37] + egyopgenF(sinewaveptr[45], op6level[4], lep6), op5level[4], lep5);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenE(sinewaveptr[38] + egyopgenF(sinewaveptr[46], op6level[5], lep6), op5level[5], lep5);
            }
            break;
          case 6:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenD(sinewaveptr[25], op4level[0], lep4);
              bufferbe +=   egyopgenE(sinewaveptr[33] + egyopgenF(sinewaveptr[41], op6level[0], lep6), op5level[0], lep5);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[26], op4level[1], lep4);
              bufferbe +=   egyopgenE(sinewaveptr[34] + egyopgenF(sinewaveptr[42], op6level[1], lep6), op5level[1], lep5);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[27], op4level[2], lep4);
              bufferbe +=   egyopgenE(sinewaveptr[35] + egyopgenF(sinewaveptr[43], op6level[2], lep6), op5level[2], lep5);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[28], op4level[3], lep4);
              bufferbe +=   egyopgenE(sinewaveptr[36] + egyopgenF(sinewaveptr[44], op6level[3], lep6), op5level[3], lep5);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[29], op4level[4], lep4);
              bufferbe +=   egyopgenE(sinewaveptr[37] + egyopgenF(sinewaveptr[45], op6level[4], lep6), op5level[4], lep5);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[30], op4level[5], lep4);
              bufferbe +=   egyopgenE(sinewaveptr[38] + egyopgenF(sinewaveptr[46], op6level[5], lep6), op5level[5], lep5);
            }
            break;
        }
        //EQ +REVERB Right
        bufferbe = bufferbe >> level;
        // y4= equqlizerdelay2(y4,freq1,freq2,elozodelaybufferindex);
        y4 = (freq1 * y4 + freq2 * delaybuffer[elozodelaybufferindex]) / 11500;
        delaybuffer[elozodelaybufferindex] = y4;
        //  y2 = equalizer2(y2, freq1, freq2, bufferbe);
        // bufferbe = y2 + delaybuffer[delaybufferindex];
        bufferbe =   yadddelay(bufferbe, elozodelaybufferindex, lfo1volume, reverbtime);
        delaybuffer[delaybufferindex2] = reverblevel2gain(reverblevel2, bufferbe);
        elozodelaybufferindex = delaybufferindex2;
        delaybufferindex2 += 2;
        if (delaybufferindex2 >= reverbtime2) {
          delaybufferindex2 = 1;
        }


        //uint16_t *ubuffer = (uint16_t*) bufferbe;
        // set volume amplitude (signed multiply)
        //  buffer[i] = buffer[i] * volume / 1024;
        // convert from signed 16 bit to unsigned 12 bit for DAC.
        // buffer[i] += 0x8000;
        //  buffer[i] >>= 4;
        //    bufferbe += 0x8000;
        //    bufferbe/=16;



        //mono mode

        if (bufferindex != 0)
        {
          buffer[bufferindex] = bufferbe + buffer[bufferindex - 1];
        }
        else
        {
          buffer[ bufferindex] = bufferbe + buffer[buffermeret ];
        }
        /*
          //stereo mode
          buffer[bufferindex] = bufferbe;
        */
      }
    }

    //13bit
    /*
      for (int i = 0; i < buffermeret; i += 2) {
      long audiosignal = buffer[i] + buffer[i + 1];
      if (audiosignal < 0) {
        buffer[i] = audiosignal;
      }
      else {
        buffer[i + 1] = audiosignal;
      }
      }
    */
    //dac++
    /*
      for (int i = 0; i < buffermeret; i += 2) {
      long audiosignal = buffer[i] + buffer[i + 1];
      if (audiosignal < 0) {
        buffer[i] = audiosignal/4096;
      }
      else {
        buffer[i + 1] = audiosignal%4096;
      }
      }
    */
    /*
      for (int i = 0; i < buffermeret; i ++) {
        buffer[i]=buffer[i]%1000;
      }
    */

    //Audio.prepare
    uint16_t *ubuffer = (uint16_t*) buffer;
    for (int i = 0; i < buffermeret; i++) {
      ubuffer[i] += 0x8000;
      ubuffer[i] >>= 4;
    }

    //Audio.prepare(buffer, buffermeret, volume);

    //for (int i = 0; i < buffermeret; i++) {
    // set volume amplitude (signed multiply)
    //  buffer[i] = buffer[i] * volume / 1024;
    // convert from signed 16 bit to unsigned 12 bit for DAC.
    // ubuffer[i] += 0x8000;
    // ubuffer[i] >>= 4;
    //}

    // Feed samples to audio
    Audio.write(buffer, buffermeret);
  }
}

void ptrnullaz(byte gorbe) {
  switch (gorbe) {
    case 0:
    
      sinewaveptr[1] =  0- sinewave1freq + pich[1];
      sinewaveptr[9] =  0- sinewave9freq + pich[1];
      sinewaveptr[17] = 0- sinewave17freq + pich[1];
      sinewaveptr[25] = 0- sinewave25freq + pich[1];
      sinewaveptr[33] = 0- sinewave33freq + pich[1];
      sinewaveptr[41] = 0- sinewave41freq + pich[1];
      break;
    case 1:
      sinewaveptr[2] =  0- sinewave2freq + pich[2];
      sinewaveptr[10] = 0- sinewave10freq + pich[2];
      sinewaveptr[18] = 0- sinewave18freq + pich[2];
      sinewaveptr[26] = 0- sinewave26freq + pich[2];
      sinewaveptr[34] = 0- sinewave34freq + pich[2];
      sinewaveptr[42] = 0- sinewave42freq + pich[2];
      break;
    case 2:
      sinewaveptr[3] =  0- sinewave3freq + pich[3];
      sinewaveptr[11] = 0- sinewave11freq + pich[3];
      sinewaveptr[19] = 0- sinewave19freq + pich[3];
      sinewaveptr[27] = 0- sinewave27freq + pich[3];
      sinewaveptr[35] = 0- sinewave35freq + pich[3];
      sinewaveptr[43] = 0- sinewave43freq + pich[3];
      break;
    case 3:
      sinewaveptr[4] = 0- sinewave4freq + pich[4];
      sinewaveptr[12] = 0- sinewave12freq + pich[4];
      sinewaveptr[20] = 0- sinewave20freq + pich[4];
      sinewaveptr[28] = 0- sinewave28freq + pich[4];
      sinewaveptr[36] = 0- sinewave36freq + pich[4];
      sinewaveptr[44] = 0- sinewave44freq + pich[4];
      break;
    case 4:
      sinewaveptr[5] = 0- sinewave5freq + pich[5];
      sinewaveptr[13] = 0- sinewave13freq + pich[5];
      sinewaveptr[21] = 0- sinewave21freq + pich[5];
      sinewaveptr[29] = 0- sinewave29freq + pich[5];
      sinewaveptr[37] = 0- sinewave37freq + pich[5];
      sinewaveptr[45] = 0- sinewave45freq + pich[5];
      break;
    case 5:
      sinewaveptr[6] = 0- sinewave6freq + pich[6];
      sinewaveptr[14] = 0- sinewave14freq + pich[6];
      sinewaveptr[22] = 0- sinewave22freq + pich[6];
      sinewaveptr[30] = 0- sinewave30freq + pich[6];
      sinewaveptr[38] = 0- sinewave38freq + pich[6];
      sinewaveptr[46] = 0- sinewave46freq + pich[6];
      break;
  }
}
/*
  void korrekcio2() {
  op1generatorfreqfix = op1generatorfreqfix * 40000;
  op2generatorfreqfix = op2generatorfreqfix * 40000;
  op3generatorfreqfix = op3generatorfreqfix * 40000;
  op4generatorfreqfix = op4generatorfreqfix * 40000;
  op5generatorfreqfix = op5generatorfreqfix * 40000;
  op6generatorfreqfix = op6generatorfreqfix * 40000;
  volume = volume * 9;
  chorustime = chorustime * 26;
  arpeggiotime = arpeggiotime * 5;
  freq1 = freq1 * 100;
  freq2 = freq2 * 100;
  fixfreqstep = fixfreqstep * 40;
  picheglevel = picheglevel * 200;
  }
*/
//---------------------------TUNE----------------------------------
void hangokinit() {
  //oldhangolas
  /*
    int h = 10784;//10782,77
    int b = 10176;//10177,56
    int a = 9616;//9606,42
    int gisz = 9072;//9067,26
    int g = 8560;//8558,33
    int fisz = 8080;//8078,01
    int f = 7632;//7624,66
    int e = 7200;// 7196,73
    int disz = 6800; //6792,72
    int d = 6416;//6411,52
    int cisz = 6048; //5942,55
    int c = 5712;
    //int oszto2 = 10;
    //7-es
    int h = 10783;//10782,77
    int b = 10178;//10177,56
    int a = 9606;//9606,42
    int gisz = 9067;//9067,26
    int g = 8558;//8558,33
    int fisz = 8078;//8078,01
    int f = 7625;//7624,66
    int e = 7197;// 7196,73
    int disz = 6793; //6792,72
    int d = 6412;//6411,52
    int cisz = 6052; //6051,651716040021
    int c = 5712;
    //21,83272584945816
  */
  //6os
  int h = 10435;
  int b = 9850;
  int a = 9297;
  int gisz = 8775;
  int g = 8283;
  int fisz = 7818;
  int f = 7379;
  int e = 6965;
  int disz = 6574;
  int d = 6205;
  int cisz = 5857;
  int c = 5528;
  //21,83272584945816
  //5712->5528
  /*
    uint32_t c = 5712;
    int lepes = c / 12;
    uint32_t cisz = c * 25 / 24;
    uint32_t d = c * 9 / 8;
    uint32_t disz = c * 6/ 5 ;
    uint32_t e = c * 5/ 4 ;
    uint32_t f = c * 4/ 3 ;
    uint32_t fisz = c * 25/ 18 ;
    uint32_t g = c * 3/ 2 ;
    uint32_t gisz = c * 8/ 5 ;
    uint32_t a = c * 5/ 3 ;
    uint32_t b = c * 9/ 5 ;
    uint32_t h = c * 15/ 8 ;
  */
  //Tune global pitch
  int szorzo2 = szorzo;
  for (int i = 0; i < 127; i += 12)
  {
    noteertek[i] = round(c * szorzo2);
    noteertek[i + 1] = round(cisz * szorzo2);
    noteertek[i + 2] = round(d * szorzo2);
    noteertek[i + 3] = round(disz * szorzo2);
    noteertek[i + 4] = round(e * szorzo2);
    noteertek[i + 5] = round(f * szorzo2);
    noteertek[i + 6] = round(fisz * szorzo2);
    noteertek[i + 7] = round(g * szorzo2);
    noteertek[i + 8] = round(gisz * szorzo2);
    noteertek[i + 9] = round(a * szorzo2);
    noteertek[i + 10] = round(b * szorzo2);
    noteertek[i + 11] = round(h * szorzo2);
    szorzo2 *= 2;
  }
}

//-------------------------------------PICH-------------------------------------
//-------------------------AUDIORESTART---------------------------------------

void audiorestart() {
  Audio.end();
  Audio.begin(mintavetelifreqstereo, buffermeret);
}

#pragma GCC pop_options
// END Arduino Due fm polyphonic synthesizer by Robert Laszlo Kasza
