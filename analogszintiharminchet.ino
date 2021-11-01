//Arduino Due fm polyphonic synthesizer 2019-2020 by Robert Laszlo Kasza
/*
  #pragma GCC push_options
  #pragma GCC optimize("Os")
*/
#include <Audio.h>
#include <MIDI.h>
//#include <MIDIUSB.h>
MIDI_CREATE_INSTANCE(HardwareSerial, Serial3, MIDI2);
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
byte chorusfreq = 2;
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
//uint16_t maxrelease = 0;
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

//midi
byte generatornumber = 1;
uint32_t noteertek[128];
byte midichan = 1;

//initprogramparameter
byte program = 8;
byte alg = 1;
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
uint16_t op2volume;
uint16_t op3volume;
uint16_t op5volume;
uint16_t op4volume;
uint16_t op6volume;
String pachname;
uint16_t frame = 8;
byte modulation = 1;
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
byte lfoarray[128] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//  byte lfoarray[64] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,22,23,24,25,26,27,28,29,30,31,32,31,30,29,28,27,26,25,24,23,22,21,20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
byte lfoarray2[64] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10, 11, 13, 15, 18, 22, 26, 30, 34, 39, 44, 39, 34, 30, 26, 27, 26, 22, 18, 15, 13, 11, 10, 9, 8, 7, 6, 6, 5, 5, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1 };
byte lfoarray3[64] = { 1, 5, 3, 8, 2, 2, 32, 21, 3, 18, 25, 27, 21, 5, 9, 1, 6, 7, 18, 30, 24, 26, 10, 1, 5, 27, 19, 22, 6, 30, 34, 39, 17, 16, 19, 2, 26, 27, 2, 22, 18, 15, 13, 3, 15, 9, 8, 17, 26, 6, 15, 25, 4, 4, 33, 3, 3, 12, 24, 2, 11, 1, 19, 13 };
byte lfoarrayindex = 0;
byte lfofreq = 14;
byte lfovolume = 0;
byte lfo2arrayindex = 0;
byte lfo2freq = 14;
byte lfo2volume = 0;


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
byte op1generatorfreq;
byte op2generatorfreq;
byte op3generatorfreq;
byte op4generatorfreq;
byte op5generatorfreq;
byte op6generatorfreq;
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
byte lcdfreq = 5;
//bufferbe += sinusfg[((sinewaveptr[1] >> 22) + fmsinusfg[sinewaveptr[9] >> 22] * op2gorbe[gorbetime[0]] / op2volume) % 1024] * op1gorbe[gorbetime[0]] / ALVOLUME;
#define ketop(freqmutato1, freqmutato2,op1gorbelevel,op1level,op2gorbelevel, op2level) (sinusfg[((freqmutato1 >> 22) + fmsinusfg[freqmutato2 >> 22] * op2gorbelevel / op2level) % FG_SIZE ] * op1gorbelevel / op1level)
//#define ketoplow(freqmutato1, freqmutato2,op1gorbetime,op1level,op2gorbetime, op2level) (fmsinusfg[((freqmutato1 >> 22) + fmsinusfg[freqmutato2 >> 22] * op2gorbetime / op2level) % FG_SIZE ] * op1gorbetime / op1level)
//#define haromop(freqmutato1, freqmutato2,freqmutato3,op1gorbelevel,op1level,op2gorbelevel, op2level,op3gorbelevel, op3level)  (sinusfg[((freqmutato1 >> 22) + fmsinusfg[((freqmutato2 >> 22)+fmsinusfg[freqmutato3 >> 22]* op3gorbelevel / op3level)% FG_SIZE ] * op2gorbelevel / op2level) % FG_SIZE ] * op1gorbelevel / op1level)
#define negyopgenA(freqmutato1, freqmutato2,freqmutato3,freqmutato4,op1level,op2level,op3level,op4level)  (generator1[((freqmutato1 >> 22) + generator2[((freqmutato2 >> 22)+generator3[((freqmutato3 >> 22)+generator4[freqmutato4 >> 22]*op4level/4096)%FG_SIZE ]    * op3level/4096)% FG_SIZE ] * op2level/4096) % FG_SIZE ] *op1level>>12)
#define haromopgenA(freqmutato1, freqmutato2,freqmutato3,op1level,op2level,op3level)  (generator1[((freqmutato1 >> 22) + generator2[((freqmutato2 >> 22)+generator3[freqmutato3 >> 22]* op3level/4096)% FG_SIZE ] * op2level/4096) % FG_SIZE ] *op1level>>12)
#define haromopgenB(freqmutato1, freqmutato2,freqmutato3,op4level,op5level,op6level)  (generator4[((freqmutato1 >> 22) + generator5[((freqmutato2 >> 22)+generator6[freqmutato3 >> 22]* op6level/4096)% FG_SIZE ] * op5level/4096) % FG_SIZE ] * op4level>>12)
#define ketopgenA(freqmutato1, freqmutato2,op1level,op2level)  (generator1[((freqmutato1 >> 22) + generator2[freqmutato2 >> 22] * op2level/4096) % FG_SIZE ] *op1level>>12)
#define ketopgenB(freqmutato3, freqmutato4,op3level,op4level)  (generator3[((freqmutato3 >> 22) + generator4[freqmutato4 >> 22] * op4level/4096) % FG_SIZE ] *op3level>>12)
#define ketopgenC(freqmutato5, freqmutato6,op5level,op6level)  (generator5[((freqmutato5 >> 22) + generator6[freqmutato6 >> 22] * op6level/4096) % FG_SIZE ] *op5level>>12)
#define ketopgenA2(freqmutato1, freqmutato2,op1level,op2level)  (generator1[((freqmutato1 >> 22)+generator2[freqmutato2 >> 22]* op2level/4096)% FG_SIZE ] * op1level/4096)
#define egyopgenA(freqmutato1,op1level)  (generator1[freqmutato1 >> 22] *op1level>>12)
#define egyopgenB(freqmutato2,op2level)  (generator2[freqmutato2 >> 22] *op2level>>12)
#define egyopgenC(freqmutato3,op3level)  (generator3[freqmutato3 >> 22] *op3level>>12)
#define egyopgenD(freqmutato4,op4level)  (generator4[freqmutato4 >> 22] *op4level>>12)
#define egyopgenE(freqmutato5,op5level)  (generator5[freqmutato5 >> 22] *op5level>>12)
#define egyopgenF(freqmutato6,op6level)  (generator6[freqmutato6 >> 22] *op6level>>12)
//#define haromop(freqmutato1, freqmutato2,freqmutato3,op1gorbelevel,op1level,op2gorbelevel, op2level,op3gorbelevel, op3level)  (fmsinusfg[((freqmutato1 >> 22) + fmsinusfg[((freqmutato2 >> 22)+fmsinusfg[freqmutato3 >> 22]*op3gorbelevel )% 1024] * op2gorbelevel ) % 1024] * op1gorbelevel/ op1level)
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
    if (ido - elozoido > frame*1000) {

      //
        
      //
      elozoido = ido;
      if (szamlalo >= lcdfreq) {
        vezerlok();
        initprog();
        szamlalo = 0;
      } else {
        szamlalo++;
      }
      //lfo
      lfo1volume = (lfoarray[lfoarrayindex >> 1] >> choruslevel << 1) + 2;
      lfoarrayindex += chorusfreq;
      lfo2volume = lfoarray[lfo2arrayindex >> 1] << 1;
      lfo2arrayindex += lfo2freq;
      pichband(0, lfo2volume);
      // picheglevel=picheglevel+lfo2volume*2000;

      // Serial.println(String(lcdprint3( lfo2volume)) + " ");


      //gorbe leptetese ill leallitasa
      if (gorbetime[0] == maxtime0) {
        gorbetime[0] = -1;
        ptrnullaz(0);
      } else {
        if (gorbetime[0] >= 0) {

          if (gorbetime[0] != maxrelease0 - 1)  //what is the fuck :)
            gorbetime[0]++;
          op1level[0] = op1gorbe[gorbetime[0]] * op1volume * (waveveloc[0] / op1veloc);
          op2level[0] = op2gorbe[gorbetime[0]] * op2volume * (waveveloc[0] / op2veloc);
          op3level[0] = op3gorbe[gorbetime[0]] * op3volume * (waveveloc[0] / op3veloc);
          op4level[0] = op4gorbe[gorbetime[0]] * op4volume * (waveveloc[0] / op4veloc);
          op5level[0] = op5gorbe[gorbetime[0]] * op5volume * (waveveloc[0] / op5veloc);
          op6level[0] = op6gorbe[gorbetime[0]] * op6volume * (waveveloc[0] / op6veloc);
        }
      }

      if (gorbetime[1] == maxtime1) {
        gorbetime[1] = -1;
        ptrnullaz(1);
      } else {
        if (gorbetime[1] >= 0) {

          if (gorbetime[1] != maxrelease1 - 1)
            gorbetime[1]++;
          op1level[1] = op1gorbe[gorbetime[1]] * op1volume * (waveveloc[1] / op1veloc);
          op2level[1] = op2gorbe[gorbetime[1]] * op2volume * (waveveloc[1] / op2veloc);
          op3level[1] = op3gorbe[gorbetime[1]] * op3volume * (waveveloc[1] / op3veloc);
          op4level[1] = op4gorbe[gorbetime[1]] * op4volume * (waveveloc[1] / op4veloc);
          op5level[1] = op5gorbe[gorbetime[1]] * op5volume * (waveveloc[1] / op5veloc);
          op6level[1] = op6gorbe[gorbetime[1]] * op6volume * (waveveloc[1] / op6veloc);
        }
      }

      if (gorbetime[2] == maxtime2) {
        gorbetime[2] = -1;
        ptrnullaz(2);
      } else {
        if (gorbetime[2] >= 0) {

          if (gorbetime[2] != maxrelease2 - 1)
            gorbetime[2]++;
          op1level[2] = op1gorbe[gorbetime[2]] * op1volume * (waveveloc[2] / op1veloc);
          op2level[2] = op2gorbe[gorbetime[2]] * op2volume * (waveveloc[2] / op2veloc);
          op3level[2] = op3gorbe[gorbetime[2]] * op3volume * (waveveloc[2] / op3veloc);
          op4level[2] = op4gorbe[gorbetime[2]] * op4volume * (waveveloc[2] / op4veloc);
          op5level[2] = op5gorbe[gorbetime[2]] * op5volume * (waveveloc[2] / op5veloc);
          op6level[2] = op6gorbe[gorbetime[2]] * op6volume * (waveveloc[2] / op6veloc);
        }
      }
      if (gorbetime[3] == maxtime3) {
        gorbetime[3] = -1;
        ptrnullaz(3);
      } else {
        if (gorbetime[3] >= 0) {

          if (gorbetime[3] != maxrelease3 - 1)
            gorbetime[3]++;
          op1level[3] = op1gorbe[gorbetime[3]] * op1volume * (waveveloc[3] / op1veloc);
          op2level[3] = op2gorbe[gorbetime[3]] * op2volume * (waveveloc[3] / op2veloc);
          op3level[3] = op3gorbe[gorbetime[3]] * op3volume * (waveveloc[3] / op3veloc);
          op4level[3] = op4gorbe[gorbetime[3]] * op4volume * (waveveloc[3] / op4veloc);
          op5level[3] = op5gorbe[gorbetime[3]] * op5volume * (waveveloc[3] / op5veloc);
          op6level[3] = op6gorbe[gorbetime[3]] * op6volume * (waveveloc[3] / op6veloc);
        }
      }

      if (gorbetime[4] == maxtime4) {
        gorbetime[4] = -1;
        ptrnullaz(4);
      } else {
        if (gorbetime[4] >= 0) {

          if (gorbetime[4] != maxrelease4 - 1)
            gorbetime[4]++;
          op1level[4] = op1gorbe[gorbetime[4]] * op1volume * (waveveloc[4] / op1veloc);
          op2level[4] = op2gorbe[gorbetime[4]] * op2volume * (waveveloc[4] / op2veloc);
          op3level[4] = op3gorbe[gorbetime[4]] * op3volume * (waveveloc[4] / op3veloc);
          op4level[4] = op4gorbe[gorbetime[4]] * op4volume * (waveveloc[4] / op4veloc);
          op5level[4] = op5gorbe[gorbetime[4]] * op5volume * (waveveloc[4] / op5veloc);
          op6level[4] = op6gorbe[gorbetime[4]] * op6volume * (waveveloc[4] / op6veloc);
        }
      }
      if (gorbetime[5] == maxtime5) {
        gorbetime[5] = -1;
        ptrnullaz(5);
      } else {
        if (gorbetime[5] >= 0) {

          if (gorbetime[5] != maxrelease5 - 1)
            gorbetime[5]++;
          op1level[5] = op1gorbe[gorbetime[5]] * op1volume * (waveveloc[5] / op1veloc);
          op2level[5] = op2gorbe[gorbetime[5]] * op2volume * (waveveloc[5] / op2veloc);
          op3level[5] = op3gorbe[gorbetime[5]] * op3volume * (waveveloc[5] / op3veloc);
          op4level[5] = op4gorbe[gorbetime[5]] * op4volume * (waveveloc[5] / op4veloc);
          op5level[5] = op5gorbe[gorbetime[5]] * op5volume * (waveveloc[5] / op5veloc);
          op6level[5] = op6gorbe[gorbetime[5]] * op6volume * (waveveloc[5] / op6veloc);
        }
      }

     
   
      
     
        
      

      if (notefixedop1) {
        sinewave1freq = wavefreq[0] * op1generatorfreq;
        sinewave2freq = wavefreq[1] * op1generatorfreq;
        sinewave3freq = wavefreq[2] * op1generatorfreq;
        sinewave4freq = wavefreq[3] * op1generatorfreq;
        sinewave5freq = wavefreq[4] * op1generatorfreq;
        sinewave6freq = wavefreq[5] * op1generatorfreq;
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
          /*
            for (int i=1;i<7;i++){
            pich[i] = 0;
            }
          */
          pich[1] = 0;
          pich[2] = 0;
          pich[3] = 0;
          pich[4] = 0;
          pich[5] = 0;
          pich[6] = 0;
          break;
        case 1:
          /*
            for (int i=0;i<6;i++){
            pich[i+1] = (pichgorbe[gorbetime[i]] - 50) * picheglevel;
            }
          */
          pich[1] = (pichgorbe[gorbetime[0]] - 50) * picheglevel;
          pich[2] = (pichgorbe[gorbetime[1]] - 50) * picheglevel;
          pich[3] = (pichgorbe[gorbetime[2]] - 50) * picheglevel;
          pich[4] = (pichgorbe[gorbetime[3]] - 50) * picheglevel;
          pich[5] = (pichgorbe[gorbetime[4]] - 50) * picheglevel;
          pich[6] = (pichgorbe[gorbetime[5]] - 50) * picheglevel;
          break;
        case 2:
          /*
               for (int i=0;i<6;i++){
                  pich[i+1] = ~((pichgorbe[gorbetime[i]] - 50) * picheglevel - 1);
                 }
          */

          pich[1] = ~((pichgorbe[gorbetime[0]] - 50) * picheglevel - 1);
          pich[2] = ~((pichgorbe[gorbetime[1]] - 50) * picheglevel - 1);
          pich[3] = ~((pichgorbe[gorbetime[2]] - 50) * picheglevel - 1);
          pich[4] = ~((pichgorbe[gorbetime[3]] - 50) * picheglevel - 1);
          pich[5] = ~((pichgorbe[gorbetime[4]] - 50) * picheglevel - 1);
          pich[6] = ~((pichgorbe[gorbetime[5]] - 50) * picheglevel - 1);
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
          pich[9] = (pichgorbe[gorbetime[0]] - 50) * picheglevel;
          pich[10] = (pichgorbe[gorbetime[1]] - 50) * picheglevel;
          pich[11] = (pichgorbe[gorbetime[2]] - 50) * picheglevel;
          pich[12] = (pichgorbe[gorbetime[3]] - 50) * picheglevel;
          pich[13] = (pichgorbe[gorbetime[4]] - 50) * picheglevel;
          pich[14] = (pichgorbe[gorbetime[5]] - 50) * picheglevel;
          break;
        case 2:
          pich[9] = ~((pichgorbe[gorbetime[0]] - 50) * picheglevel - 1);
          pich[10] = ~((pichgorbe[gorbetime[1]] - 50) * picheglevel - 1);
          pich[11] = ~((pichgorbe[gorbetime[2]] - 50) * picheglevel - 1);
          pich[12] = ~((pichgorbe[gorbetime[3]] - 50) * picheglevel - 1);
          pich[13] = ~((pichgorbe[gorbetime[4]] - 50) * picheglevel - 1);
          pich[14] = ~((pichgorbe[gorbetime[5]] - 50) * picheglevel - 1);
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
          pich[17] = (pichgorbe[gorbetime[0]] - 50) * picheglevel;
          pich[18] = (pichgorbe[gorbetime[1]] - 50) * picheglevel;
          pich[19] = (pichgorbe[gorbetime[2]] - 50) * picheglevel;
          pich[20] = (pichgorbe[gorbetime[3]] - 50) * picheglevel;
          pich[21] = (pichgorbe[gorbetime[4]] - 50) * picheglevel;
          pich[22] = (pichgorbe[gorbetime[5]] - 50) * picheglevel;
          break;
        case 2:
          pich[17] = ~((pichgorbe[gorbetime[0]] - 50) * picheglevel - 1);
          pich[18] = ~((pichgorbe[gorbetime[1]] - 50) * picheglevel - 1);
          pich[19] = ~((pichgorbe[gorbetime[2]] - 50) * picheglevel - 1);
          pich[20] = ~((pichgorbe[gorbetime[3]] - 50) * picheglevel - 1);
          pich[21] = ~((pichgorbe[gorbetime[4]] - 50) * picheglevel - 1);
          pich[22] = ~((pichgorbe[gorbetime[5]] - 50) * picheglevel - 1);
          break;
      }

      switch (pichop4) {
        case 0: break;
          pich[25] = 0;
          pich[26] = 0;
          pich[27] = 0;
          pich[28] = 0;
          pich[29] = 0;
          pich[30] = 0;
        case 1:
          pich[25] = (pichgorbe[gorbetime[0]] - 50) * picheglevel;
          pich[26] = (pichgorbe[gorbetime[1]] - 50) * picheglevel;
          pich[27] = (pichgorbe[gorbetime[2]] - 50) * picheglevel;
          pich[28] = (pichgorbe[gorbetime[3]] - 50) * picheglevel;
          pich[29] = (pichgorbe[gorbetime[4]] - 50) * picheglevel;
          pich[30] = (pichgorbe[gorbetime[5]] - 50) * picheglevel;
          break;
        case 2:
          pich[25] = ~((pichgorbe[gorbetime[0]] - 50) * picheglevel - 1);
          pich[26] = ~((pichgorbe[gorbetime[1]] - 50) * picheglevel - 1);
          pich[27] = ~((pichgorbe[gorbetime[2]] - 50) * picheglevel - 1);
          pich[28] = ~((pichgorbe[gorbetime[3]] - 50) * picheglevel - 1);
          pich[29] = ~((pichgorbe[gorbetime[4]] - 50) * picheglevel - 1);
          pich[30] = ~((pichgorbe[gorbetime[5]] - 50) * picheglevel - 1);
          break;
      }
      switch (pichop5) {
        case 0:
          pich[33] = 0;
          pich[34] = 0;
          pich[35] = 0;
          pich[36] = 0;
          pich[37] = 0;
          pich[38] = 0; break;
        case 1:
          pich[33] = (pichgorbe[gorbetime[0]] - 50) * picheglevel;
          pich[34] = (pichgorbe[gorbetime[1]] - 50) * picheglevel;
          pich[35] = (pichgorbe[gorbetime[2]] - 50) * picheglevel;
          pich[36] = (pichgorbe[gorbetime[3]] - 50) * picheglevel;
          pich[37] = (pichgorbe[gorbetime[4]] - 50) * picheglevel;
          pich[38] = (pichgorbe[gorbetime[5]] - 50) * picheglevel;
          break;
        case 2:
          pich[33] = ~((pichgorbe[gorbetime[0]] - 50) * picheglevel - 1);
          pich[34] = ~((pichgorbe[gorbetime[1]] - 50) * picheglevel - 1);
          pich[35] = ~((pichgorbe[gorbetime[2]] - 50) * picheglevel - 1);
          pich[36] = ~((pichgorbe[gorbetime[3]] - 50) * picheglevel - 1);
          pich[37] = ~((pichgorbe[gorbetime[4]] - 50) * picheglevel - 1);
          pich[38] = ~((pichgorbe[gorbetime[5]] - 50) * picheglevel - 1);
          break;
      }
      switch (pichop6) {
        case 0: break;
          pich[41] = 0;
          pich[42] = 0;
          pich[43] = 0;
          pich[44] = 0;
          pich[45] = 0;
          pich[46] = 0;
        case 1: break;
          pich[41] = (pichgorbe[gorbetime[0]] - 50) * picheglevel;
          pich[42] = (pichgorbe[gorbetime[1]] - 50) * picheglevel;
          pich[43] = (pichgorbe[gorbetime[2]] - 50) * picheglevel;
          pich[44] = (pichgorbe[gorbetime[3]] - 50) * picheglevel;
          pich[45] = (pichgorbe[gorbetime[4]] - 50) * picheglevel;
          pich[46] = (pichgorbe[gorbetime[5]] - 50) * picheglevel;
        case 2:
          pich[41] = ~((pichgorbe[gorbetime[0]] - 50) * picheglevel - 1);
          pich[42] = ~((pichgorbe[gorbetime[1]] - 50) * picheglevel - 1);
          pich[43] = ~((pichgorbe[gorbetime[2]] - 50) * picheglevel - 1);
          pich[44] = ~((pichgorbe[gorbetime[3]] - 50) * picheglevel - 1);
          pich[45] = ~((pichgorbe[gorbetime[4]] - 50) * picheglevel - 1);
          pich[46] = ~((pichgorbe[gorbetime[5]] - 50) * picheglevel - 1);
          break;
      }
      //picheglevel=picheglevel-lfo2volume*2000;
    }
    for ( bufferindex = 0; bufferindex < buffermeret; bufferindex++) {
      bufferbe = 0;
      if ((bufferindex & 0x0001) == 1) {
        //Left
        switch (alg) {
          case 1:
            if (gorbetime[0] > 0 ) {
              bufferbe += haromopgenA(sinewaveptr[1], sinewaveptr[9], sinewaveptr[17], op1level[0], op2level[0], op3level[0]);
              //bufferbe += haromopgenA(sinewaveptr[17], sinewaveptr[9], sinewaveptr[1], op3level[0], op2level[0], op1level[0]);
              //  bufferbe +=   ketop(sinewaveptr[1], sinewaveptr[33], op1gorbe[gorbetime[0]], ALVOLUME, op5gorbe[gorbetime[0]], op5volume);
            }
            if (gorbetime[1] > 0) {
              bufferbe += haromopgenA(sinewaveptr[2], sinewaveptr[10], sinewaveptr[18], op1level[1], op2level[1], op3level[1]);
              //bufferbe += haromopgenA(sinewaveptr[18], sinewaveptr[10], sinewaveptr[2], op3level[1], op2level[1], op1level[1]);
              //   bufferbe +=   ketop(sinewaveptr[2], sinewaveptr[34], op2gorbe[gorbetime[1]],  op2volume, op5gorbe[gorbetime[1]], op5volume);
            }
            if (gorbetime[2] > 0) {
              bufferbe += haromopgenA(sinewaveptr[3], sinewaveptr[11], sinewaveptr[19], op1level[2], op2level[2], op3level[2]);
              //bufferbe += haromopgenA(sinewaveptr[17], sinewaveptr[11], sinewaveptr[3], op3level[2], op2level[2], op1level[2]);
              //  bufferbe +=   ketop(sinewaveptr[3], sinewaveptr[35], op2gorbe[gorbetime[2]],  op2volume, op5gorbe[gorbetime[2]], op5volume);
            }
            if (gorbetime[3] > 0) {
              bufferbe += haromopgenA(sinewaveptr[4], sinewaveptr[12], sinewaveptr[20], op1level[3], op2level[3], op3level[3]);
              //bufferbe += haromopgenA(sinewaveptr[17], sinewaveptr[12], sinewaveptr[4], op3level[3], op2level[3], op1level[3]);
              //  bufferbe +=   ketop(sinewaveptr[4], sinewaveptr[36], op2gorbe[gorbetime[3]],  op2volume, op5gorbe[gorbetime[3]], op5volume);
            }
            if (gorbetime[4] > 0) {
              bufferbe += haromopgenA(sinewaveptr[5], sinewaveptr[13], sinewaveptr[21], op1level[4], op2level[4], op3level[4]);
              //bufferbe += haromopgenA(sinewaveptr[17], sinewaveptr[13], sinewaveptr[5], op3level[4], op2level[4], op1level[4]);
              // bufferbe +=   ketop(sinewaveptr[5], sinewaveptr[37], op2gorbe[gorbetime[4]],  op2volume, op5gorbe[gorbetime[4]], op5volume);
            }
            if (gorbetime[5] > 0) {
              bufferbe += haromopgenA(sinewaveptr[6], sinewaveptr[14], sinewaveptr[22], op1level[5], op2level[5], op3level[5]);
              //     bufferbe += haromopgenA(sinewaveptr[17], sinewaveptr[14], sinewaveptr[6], op3level[5], op2level[5], op1level[5]);
              //   bufferbe +=   ketop(sinewaveptr[6], sinewaveptr[38], op2gorbe[gorbetime[5]],  op2volume, op5gorbe[gorbetime[5]], op5volume);
            }
            break;
          //algoritmus1vege
          //algoritmus2
          case 2:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   ketopgenA(sinewaveptr[1], sinewaveptr[9], op1level[0], op2level[0]);
              bufferbe +=   ketopgenB(sinewaveptr[17], sinewaveptr[25], op3level[0], op4level[0]);

            }
            if (gorbetime[1] > 0) {
              bufferbe +=   ketopgenA(sinewaveptr[2], sinewaveptr[10], op1level[1], op2level[1]);
              bufferbe +=   ketopgenB(sinewaveptr[18], sinewaveptr[26], op3level[1], op4level[1]);

            }
            if (gorbetime[2] > 0) {
              bufferbe +=   ketopgenA(sinewaveptr[3], sinewaveptr[11], op1level[2], op2level[2]);
              bufferbe +=   ketopgenB(sinewaveptr[19], sinewaveptr[27], op3level[2], op4level[2]);

            }
            if (gorbetime[3] > 0) {
              bufferbe +=   ketopgenA(sinewaveptr[4], sinewaveptr[12], op1level[3], op2level[3]);
              bufferbe +=   ketopgenB(sinewaveptr[20], sinewaveptr[28], op3level[3], op4level[3]);

            }
            if (gorbetime[4] > 0) {
              bufferbe +=   ketopgenA(sinewaveptr[5], sinewaveptr[13], op1level[4], op2level[4]);
              bufferbe +=   ketopgenB(sinewaveptr[21], sinewaveptr[29], op3level[4], op4level[4]);

            }
            if (gorbetime[5] > 0) {
              bufferbe +=   ketopgenA(sinewaveptr[6], sinewaveptr[14], op1level[5], op2level[5]);
              bufferbe +=   ketopgenB(sinewaveptr[22], sinewaveptr[30], op3level[5], op4level[5]);

            }
            break;
          //algoritmus3
          case 3:


            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenA(sinewaveptr[1], op1level[0]);
              bufferbe +=   egyopgenB(sinewaveptr[9], op2level[0]);
              bufferbe +=   egyopgenC(sinewaveptr[17], op3level[0]);

            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[2], op1level[1]);
              bufferbe +=   egyopgenB(sinewaveptr[10], op2level[1]);
              bufferbe +=   egyopgenC(sinewaveptr[18], op3level[1]);

            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[3], op1level[2]);
              bufferbe +=   egyopgenB(sinewaveptr[11], op2level[2]);
              bufferbe +=   egyopgenC(sinewaveptr[19], op3level[2]);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[4], op1level[3]);
              bufferbe +=   egyopgenB(sinewaveptr[12], op2level[3]);
              bufferbe +=   egyopgenC(sinewaveptr[20], op3level[3]);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[5], op1level[4]);
              bufferbe +=   egyopgenB(sinewaveptr[13], op2level[4]);
              bufferbe +=   egyopgenC(sinewaveptr[21], op3level[4]);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenA(sinewaveptr[6], op1level[5]);
              bufferbe +=   egyopgenB(sinewaveptr[14], op2level[5]);
              bufferbe +=   egyopgenC(sinewaveptr[22], op3level[5]);
            }
            break;
          //algoritmus4
          case 4:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   negyopgenA(sinewaveptr[1], sinewaveptr[9], sinewaveptr[17], sinewaveptr[25], op1level[0], op2level[0], op3level[0], op4level[0]);

            }
            if (gorbetime[1] > 0) {
              bufferbe +=   negyopgenA(sinewaveptr[2], sinewaveptr[10], sinewaveptr[18], sinewaveptr[26], op1level[1], op2level[1], op3level[1], op4level[1]);

            }
            if (gorbetime[2] > 0) {
              bufferbe +=   negyopgenA(sinewaveptr[3], sinewaveptr[11], sinewaveptr[19], sinewaveptr[27], op1level[2], op2level[2], op3level[2], op4level[2]);

            }
            if (gorbetime[3] > 0) {
              bufferbe +=   negyopgenA(sinewaveptr[4], sinewaveptr[12], sinewaveptr[20], sinewaveptr[28], op1level[3], op2level[3], op3level[3], op4level[3]);

            }
            if (gorbetime[4] > 0) {
              bufferbe +=   negyopgenA(sinewaveptr[5], sinewaveptr[13], sinewaveptr[21], sinewaveptr[29], op1level[4], op2level[4], op3level[4], op4level[4]);

            }
            if (gorbetime[5] > 0) {
              bufferbe +=   negyopgenA(sinewaveptr[6], sinewaveptr[14], sinewaveptr[22], sinewaveptr[30], op1level[5], op2level[5], op3level[5], op4level[5]);
            }
            break;

          //algoritmus5 pwm
          case 5:

            if (gorbetime[0] > 0 ) {
              kitoltes0 = (op1gorbe[gorbetime[0]] >> 3) + 22;
              if (kitoltes0 > 40) {
                kitoltes0 = 40;
              }
              {
                if (kitoltes0 >= 31) {
                  if (sinewaveptr[1] >> kitoltes0 - ((kitoltes0 - 31) << 1) == 0)
                  {
                    bufferbe += -1 * (op1level[0] >> 3);
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
                    bufferbe += -1 * (op1level[0] >> 3);
                  }


                  //
                }
                //Serial.print( String(kitoltes0) + " buf: ");
                //  Serial.println( String(bufferbe) + " ");
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
                  bufferbe += -1 * (op1level[1] >> 3);
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
                  bufferbe += -1 * (op1level[1] >> 3);
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
                  bufferbe += -1 * (op1level[2] >> 3);
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
                  bufferbe += -1 * (op1level[2] >> 3);
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
                  bufferbe += -(1 * op1level[3] >> 3);
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
                  bufferbe += -(1 * op1level[3] >> 3);
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
                  bufferbe += -(1 * op1level[4] >> 3);
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
                  bufferbe += -1 *  op1level[4] >> 3;
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
                  bufferbe += -1 * (op1level[5] >> 3);
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
                  bufferbe += -1 * (op1level[5] >> 3);
                }
              }
            }

            break;
          case 6:

            byte kapcsolo;
            if (generatornumber == 0) {
              kapcsolo = 5;
            }
            else {
              kapcsolo = generatornumber - 1;
            }
            //   Serial.println( String(kapcsolo) + " ");
            switch (kapcsolo) {
              case 0:
                if (gorbetime[5] > 0 ) {
                  bufferbe +=   negyopgenA(sinewaveptr[1], sinewaveptr[9], sinewaveptr[17], sinewaveptr[25], op1level[0], op2level[0], op3level[0], op4level[0]);
                  bufferbe +=   ketopgenC(sinewaveptr[33], sinewaveptr[41], op5level[0], op6level[0]);
                }
                break;
              case 1:
                if (gorbetime[0] > 0 ) {

                  bufferbe +=   negyopgenA(sinewaveptr[2], sinewaveptr[10], sinewaveptr[18], sinewaveptr[26], op1level[1], op2level[1], op3level[1], op4level[1]);
                  bufferbe +=   ketopgenC(sinewaveptr[34], sinewaveptr[42], op5level[1], op6level[1]);
                }
                break;
              case 2:
                if (gorbetime[1] > 0 ) {
                  bufferbe +=   negyopgenA(sinewaveptr[3], sinewaveptr[11], sinewaveptr[19], sinewaveptr[27], op1level[2], op2level[2], op3level[2], op4level[2]);
                  bufferbe +=   ketopgenC(sinewaveptr[35], sinewaveptr[43], op5level[2], op6level[2]);
                }
                break;
              case 3:
                if (gorbetime[2] > 0 ) {
                  bufferbe +=   negyopgenA(sinewaveptr[4], sinewaveptr[12], sinewaveptr[20], sinewaveptr[28], op1level[3], op2level[3], op3level[3], op4level[3]);
                  bufferbe +=   ketopgenC(sinewaveptr[36], sinewaveptr[44], op5level[3], op6level[3]);
                }
                break;
              case 4:
                if (gorbetime[3] > 0 ) {
                  bufferbe +=   negyopgenA(sinewaveptr[5], sinewaveptr[13], sinewaveptr[21], sinewaveptr[29], op1level[4], op2level[4], op3level[4], op4level[4]);
                  bufferbe +=   ketopgenC(sinewaveptr[37], sinewaveptr[45], op5level[4], op6level[4]);
                }
                break;
              case 5:
                if (gorbetime[4] > 0 ) {
                  bufferbe +=   negyopgenA(sinewaveptr[6], sinewaveptr[14], sinewaveptr[22], sinewaveptr[30], op1level[5], op2level[5], op3level[5], op4level[5]);
                  bufferbe +=   ketopgenC(sinewaveptr[38], sinewaveptr[46], op5level[5], op6level[5]);
                }
                break;
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
              bufferbe += haromopgenB(sinewaveptr[25], sinewaveptr[33], sinewaveptr[41], op4level[0], op5level[0], op6level[0]);
            }
            if (gorbetime[1] > 0) {
              bufferbe += haromopgenB(sinewaveptr[26], sinewaveptr[34], sinewaveptr[42], op4level[1], op5level[1], op6level[1]);
            }
            if (gorbetime[2] > 0) {
              bufferbe += haromopgenB(sinewaveptr[27], sinewaveptr[35], sinewaveptr[43],  op4level[2], op5level[2], op6level[2]);
            }
            if (gorbetime[3] > 0) {
              bufferbe += haromopgenB(sinewaveptr[28], sinewaveptr[36], sinewaveptr[44], op4level[3], op5level[3], op6level[3]);
            }
            if (gorbetime[4] > 0) {
              bufferbe += haromopgenB(sinewaveptr[29], sinewaveptr[37], sinewaveptr[45],  op4level[4], op5level[4], op6level[4]);
            }
            if (gorbetime[5] > 0) {
              bufferbe += haromopgenB(sinewaveptr[30], sinewaveptr[38], sinewaveptr[46],  op4level[5], op5level[5], op6level[5]);
            }
            break;
          case 2:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   ketopgenC(sinewaveptr[33], sinewaveptr[41], op5level[0], op6level[0]);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[34], sinewaveptr[42], op5level[1], op6level[1]);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[35], sinewaveptr[43], op5level[2], op6level[2]);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[36], sinewaveptr[44], op5level[3], op6level[3]);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[37], sinewaveptr[45], op5level[4], op6level[4]);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[38], sinewaveptr[46], op5level[5], op6level[5]);
            }
            break;
          case 3:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   egyopgenD(sinewaveptr[25], op4level[0]);
              bufferbe +=   egyopgenE(sinewaveptr[33], op5level[0]);
              bufferbe +=   egyopgenF(sinewaveptr[41], op6level[0]);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[26], op4level[1]);
              bufferbe +=   egyopgenE(sinewaveptr[34], op5level[1]);
              bufferbe +=   egyopgenF(sinewaveptr[42], op6level[1]);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[27], op4level[2]);
              bufferbe +=   egyopgenE(sinewaveptr[35], op5level[2]);
              bufferbe +=   egyopgenF(sinewaveptr[43], op6level[2]);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[28], op4level[3]);
              bufferbe +=   egyopgenE(sinewaveptr[36], op5level[3]);
              bufferbe +=   egyopgenF(sinewaveptr[44], op6level[3]);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[29], op4level[4]);
              bufferbe +=   egyopgenE(sinewaveptr[37], op5level[4]);
              bufferbe +=   egyopgenF(sinewaveptr[45], op6level[4]);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   egyopgenD(sinewaveptr[30], op4level[5]);
              bufferbe +=   egyopgenE(sinewaveptr[38], op5level[5]);
              bufferbe +=   egyopgenF(sinewaveptr[46], op6level[5]);
            }

            break;
          case 4:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   ketopgenC(sinewaveptr[33], sinewaveptr[41], op5level[0], op6level[0]);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[34], sinewaveptr[42], op5level[1], op6level[1]);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[35], sinewaveptr[43], op5level[2], op6level[2]);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[36], sinewaveptr[44], op5level[3], op6level[3]);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[37], sinewaveptr[45], op5level[4], op6level[4]);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[38], sinewaveptr[46], op5level[5], op6level[5]);
            }
            break;
          //algoritmus5 pwm
          case 5:
            if (gorbetime[0] > 0 ) {
              bufferbe +=   ketopgenC(sinewaveptr[33], sinewaveptr[41], op5level[0], op6level[0]);
            }
            if (gorbetime[1] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[34], sinewaveptr[42], op5level[1], op6level[1]);
            }
            if (gorbetime[2] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[35], sinewaveptr[43], op5level[2], op6level[2]);
            }
            if (gorbetime[3] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[36], sinewaveptr[44], op5level[3], op6level[3]);
            }
            if (gorbetime[4] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[37], sinewaveptr[45], op5level[4], op6level[4]);
            }
            if (gorbetime[5] > 0) {
              bufferbe +=   ketopgenC(sinewaveptr[38], sinewaveptr[46], op5level[5], op6level[5]);
            }
            break;
          case 6:

            //második

            /*

              if (gorbetime[0] > 0 ) {


              }
              if (gorbetime[1] > 0) {


              }
              if (gorbetime[2] > 0) {


              }
              if (gorbetime[3] > 0) {


              }
              if (gorbetime[4] > 0) {


              }
              if (gorbetime[5] > 0) {


              }
              break;
            */
            byte kapcsolo;
            if (generatornumber == 0) {
              kapcsolo = 5;
            }
            else {
              kapcsolo = generatornumber - 1;
            }
            switch (kapcsolo) {
              case 0:
                if (gorbetime[5] > 0 ) {
                  bufferbe +=   ketopgenA(sinewaveptr[1], sinewaveptr[9], op1level[0], op2level[0]);
                  bufferbe +=   ketopgenB(sinewaveptr[17], sinewaveptr[25], op3level[0], op4level[0]);


                }
                break;
              case 1:
                if (gorbetime[0] > 0 ) {

                  bufferbe +=   ketopgenA(sinewaveptr[2], sinewaveptr[10], op1level[1], op2level[1]);
                  bufferbe +=   ketopgenB(sinewaveptr[18], sinewaveptr[26], op3level[1], op4level[1]);

                }
                break;
              case 2:
                if (gorbetime[1] > 0 ) {
                  bufferbe +=   ketopgenA(sinewaveptr[3], sinewaveptr[11], op1level[2], op2level[2]);
                  bufferbe +=   ketopgenB(sinewaveptr[19], sinewaveptr[27], op3level[2], op4level[2]);

                }
                break;
              case 3:
                if (gorbetime[2] > 0 ) {
                  bufferbe +=   ketopgenA(sinewaveptr[4], sinewaveptr[12], op1level[3], op2level[3]);
                  bufferbe +=   ketopgenB(sinewaveptr[20], sinewaveptr[28], op3level[3], op4level[3]);

                }
                break;
              case 4:
                if (gorbetime[3] > 0 ) {
                  bufferbe +=   ketopgenA(sinewaveptr[5], sinewaveptr[13], op1level[4], op2level[4]);
                  bufferbe +=   ketopgenB(sinewaveptr[21], sinewaveptr[29], op3level[4], op4level[4]);

                }
                break;
              case 5:
                if (gorbetime[4] > 0 ) {
                  bufferbe +=   ketopgenA(sinewaveptr[6], sinewaveptr[14], op1level[5], op2level[5]);
                  bufferbe +=   ketopgenB(sinewaveptr[22], sinewaveptr[30], op3level[5], op4level[5]);

                }
                break;
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
        bufferbe =   yadddelay(bufferbe, elozodelaybufferindex, lfo1volume, reverbtime2);
        delaybuffer[delaybufferindex2] = reverblevel2gain(reverblevel2, bufferbe);
        elozodelaybufferindex = delaybufferindex2;
        delaybufferindex2 += 2;
        if (delaybufferindex2 >= reverbtime2) {
          delaybufferindex2 = 1;
        }
        buffer[ bufferindex] = bufferbe;
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

    Audio.prepare(buffer, buffermeret, volume);
    // Feed samples to audio
    Audio.write(buffer, buffermeret);
  }
}

void ptrnullaz(byte gorbe) {
  switch (gorbe) {
    case 0:
      sinewaveptr[1] = 0;
      sinewaveptr[9] = 0;
      sinewaveptr[17] = 0;
      sinewaveptr[25] = 0;
      sinewaveptr[33] = 0;
      sinewaveptr[41] = 0;
      break;
    case 1:
      sinewaveptr[2] = 0;
      sinewaveptr[10] = 0;
      sinewaveptr[18] = 0;
      sinewaveptr[26] = 0;
      sinewaveptr[34] = 0;
      sinewaveptr[42] = 0;
      break;
    case 2:
      sinewaveptr[3] = 0;
      sinewaveptr[11] = 0;
      sinewaveptr[19] = 0;
      sinewaveptr[27] = 0;
      sinewaveptr[35] = 0;
      sinewaveptr[43] = 0;
      break;
    case 3:
      sinewaveptr[4] = 0;
      sinewaveptr[12] = 0;
      sinewaveptr[20] = 0;
      sinewaveptr[28] = 0;
      sinewaveptr[36] = 0;
      sinewaveptr[44] = 0;
      break;
    case 4:
      sinewaveptr[5] = 0;
      sinewaveptr[13] = 0;
      sinewaveptr[21] = 0;
      sinewaveptr[29] = 0;
      sinewaveptr[37] = 0;
      sinewaveptr[45] = 0;
      break;
    case 5:
      sinewaveptr[6] = 0;
      sinewaveptr[14] = 0;
      sinewaveptr[22] = 0;
      sinewaveptr[30] = 0;
      sinewaveptr[38] = 0;
      sinewaveptr[46] = 0;
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
