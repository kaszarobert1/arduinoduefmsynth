#include <DueFlashStorage.h>
DueFlashStorage dueFlashStorage;

void save() {
  //saveprog
  int kezdocim = saveprog * 128;
  dueFlashStorage.write(kezdocim, op1waveform);
  dueFlashStorage.write(kezdocim + 1, op2waveform);
  dueFlashStorage.write(kezdocim + 2, op3waveform);
  dueFlashStorage.write(kezdocim + 3, op4waveform);
  dueFlashStorage.write(kezdocim + 4, op5waveform);
  dueFlashStorage.write(kezdocim + 5, op6waveform);
  dueFlashStorage.write(kezdocim + 6, op1al);
  dueFlashStorage.write(kezdocim + 7, op2al);
  dueFlashStorage.write(kezdocim + 8, op3al);
  dueFlashStorage.write(kezdocim + 9, op4al);
  dueFlashStorage.write(kezdocim + 10, op5al);
  dueFlashStorage.write(kezdocim + 11, op6al);
  dueFlashStorage.write(kezdocim + 12, op1ar);
  dueFlashStorage.write(kezdocim + 13, op2ar);
  dueFlashStorage.write(kezdocim + 14, op3ar);
  dueFlashStorage.write(kezdocim + 15, op4ar);
  dueFlashStorage.write(kezdocim + 16, op5ar);
  dueFlashStorage.write(kezdocim + 17, op6ar);
  dueFlashStorage.write(kezdocim + 18, op1d1l);
  dueFlashStorage.write(kezdocim + 19, op2d1l);
  dueFlashStorage.write(kezdocim + 20, op3d1l);
  dueFlashStorage.write(kezdocim + 21, op4d1l);
  dueFlashStorage.write(kezdocim + 22, op5d1l);
  dueFlashStorage.write(kezdocim + 23, op6d1l);
  dueFlashStorage.write(kezdocim + 24, op1d1r);
  dueFlashStorage.write(kezdocim + 25, op2d1r);
  dueFlashStorage.write(kezdocim + 26, op3d1r);
  dueFlashStorage.write(kezdocim + 27, op4d1r);
  dueFlashStorage.write(kezdocim + 28, op5d1r);
  dueFlashStorage.write(kezdocim + 29, op6d1r);
  dueFlashStorage.write(kezdocim + 30, op1d2l);
  dueFlashStorage.write(kezdocim + 31, op2d2l);
  dueFlashStorage.write(kezdocim + 32, op3d2l);
  dueFlashStorage.write(kezdocim + 33, op4d2l);
  dueFlashStorage.write(kezdocim + 34, op5d2l);
  dueFlashStorage.write(kezdocim + 35, op6d2l);
  dueFlashStorage.write(kezdocim + 36, op1d2r);
  dueFlashStorage.write(kezdocim + 37, op2d2r);
  dueFlashStorage.write(kezdocim + 38, op3d2r);
  dueFlashStorage.write(kezdocim + 39, op4d2r);
  dueFlashStorage.write(kezdocim + 40, op5d2r);
  dueFlashStorage.write(kezdocim + 41, op6d2r);
  dueFlashStorage.write(kezdocim + 42, op1rl);
  dueFlashStorage.write(kezdocim + 43, op2rl);
  dueFlashStorage.write(kezdocim + 44, op3rl);
  dueFlashStorage.write(kezdocim + 45, op4rl);
  dueFlashStorage.write(kezdocim + 46, op5rl);
  dueFlashStorage.write(kezdocim + 47, op6rl);
  dueFlashStorage.write(kezdocim + 48, op1rr);
  dueFlashStorage.write(kezdocim + 49, op2rr);
  dueFlashStorage.write(kezdocim + 50, op3rr);
  dueFlashStorage.write(kezdocim + 51, op4rr);
  dueFlashStorage.write(kezdocim + 52, op5rr);
  dueFlashStorage.write(kezdocim + 53, op6rr);
  dueFlashStorage.write(kezdocim + 54, pichal);
  dueFlashStorage.write(kezdocim + 55, pichar);
  dueFlashStorage.write(kezdocim + 56, pichd1l);
  dueFlashStorage.write(kezdocim + 57, pichd1r);
  dueFlashStorage.write(kezdocim + 58, pichd2l);
  dueFlashStorage.write(kezdocim + 59, pichd2r);
  dueFlashStorage.write(kezdocim + 60, pichrl);
  dueFlashStorage.write(kezdocim + 61, pichrr);
  dueFlashStorage.write(kezdocim + 62, op1volume );
  dueFlashStorage.write(kezdocim + 63, op2volume );
  dueFlashStorage.write(kezdocim + 64, op3volume );
  dueFlashStorage.write(kezdocim + 65, op4volume );
  dueFlashStorage.write(kezdocim + 66, op5volume );
  dueFlashStorage.write(kezdocim + 67, op6volume );
  dueFlashStorage.write(kezdocim + 68, op1veloc );
  dueFlashStorage.write(kezdocim + 69, op2veloc );
  dueFlashStorage.write(kezdocim + 70, op3veloc );
  dueFlashStorage.write(kezdocim + 71, op4veloc );
  dueFlashStorage.write(kezdocim + 72, op5veloc );
  dueFlashStorage.write(kezdocim + 73, op6veloc );
  dueFlashStorage.write(kezdocim + 74, op1generatorfreq );
  dueFlashStorage.write(kezdocim + 75, op2generatorfreq );
  dueFlashStorage.write(kezdocim + 76, op3generatorfreq );
  dueFlashStorage.write(kezdocim + 77, op4generatorfreq );
  dueFlashStorage.write(kezdocim + 78, op5generatorfreq );
  dueFlashStorage.write(kezdocim + 79, op6generatorfreq );
  dueFlashStorage.write(kezdocim + 80, fixfreqstep );
  dueFlashStorage.write(kezdocim + 81, (op1generatorfreqfix / 800 ) / fixfreqstep);
  dueFlashStorage.write(kezdocim + 82, (op2generatorfreqfix / 800) / fixfreqstep);
  dueFlashStorage.write(kezdocim + 83, (op3generatorfreqfix / 800) / fixfreqstep);
  dueFlashStorage.write(kezdocim + 84, (op4generatorfreqfix / 800 ) / fixfreqstep);
  dueFlashStorage.write(kezdocim + 85, (op5generatorfreqfix / 800 ) / fixfreqstep);
  dueFlashStorage.write(kezdocim + 86, (op6generatorfreqfix / 800 ) / fixfreqstep);
  dueFlashStorage.write(kezdocim + 87, pichop1 );
  dueFlashStorage.write(kezdocim + 88, pichop2 );
  dueFlashStorage.write(kezdocim + 89, pichop3 );
  dueFlashStorage.write(kezdocim + 90, pichop4 );
  dueFlashStorage.write(kezdocim + 91, pichop5 );
  dueFlashStorage.write(kezdocim + 92, pichop6 );
  dueFlashStorage.write(kezdocim + 93, notefixedop1 );
  dueFlashStorage.write(kezdocim + 94, notefixedop2 );
  dueFlashStorage.write(kezdocim + 95, notefixedop3 );
  dueFlashStorage.write(kezdocim + 96, notefixedop4 );
  dueFlashStorage.write(kezdocim + 97, notefixedop5 );
  dueFlashStorage.write(kezdocim + 98, notefixedop6 );
  dueFlashStorage.write(kezdocim + 99,  frame );
  dueFlashStorage.write(kezdocim + 100,   szorzo );
  dueFlashStorage.write(kezdocim + 101,   alg );
  dueFlashStorage.write(kezdocim + 102,   level );
  dueFlashStorage.write(kezdocim + 103,   pichkezd );
  dueFlashStorage.write(kezdocim + 104,   picheglevel / 500 );
  dueFlashStorage.write(kezdocim + 105,  oplfo );
  dueFlashStorage.write(kezdocim + 106,  oplfo2max );
  dueFlashStorage.write(kezdocim + 107,  oplfo4max );
  dueFlashStorage.write(kezdocim + 108,  oplfo6max );
  dueFlashStorage.write(kezdocim + 109,  lfo2step );
  dueFlashStorage.write(kezdocim + 110,  lfo4step );
  dueFlashStorage.write(kezdocim + 111,  lfo6step );
  dueFlashStorage.write(kezdocim + 112,  lfo1step );
  dueFlashStorage.write(kezdocim + 113,  lfo1max );
  dueFlashStorage.write(kezdocim + 114,  lfo1min );//!!!
  dueFlashStorage.write(kezdocim + 115,  eqvalue );
  dueFlashStorage.write(kezdocim + 116,  lfofreq);
  dueFlashStorage.write(kezdocim + 117,  reverblevel );
  dueFlashStorage.write(kezdocim + 118,  reverbtime / 23 );
  dueFlashStorage.write(kezdocim + 119,  reverblevel2 );
  dueFlashStorage.write(kezdocim + 120,  reverbtime2 / 23 );
  dueFlashStorage.write(kezdocim + 121,  gorbeszorzo );
  dueFlashStorage.write(kezdocim + 122,  released);
}

void load(byte loadprog) {
  int kezdocim = loadprog * 128;
  op1waveform = dueFlashStorage.read(kezdocim + 0);
  op2waveform = dueFlashStorage.read(kezdocim + 1);
  op3waveform = dueFlashStorage.read(kezdocim + 2);
  op4waveform = dueFlashStorage.read(kezdocim + 3);
  op5waveform = dueFlashStorage.read(kezdocim + 4);
  op6waveform = dueFlashStorage.read(kezdocim + 5);
  op1al = dueFlashStorage.read(kezdocim + 6);
  op2al = dueFlashStorage.read(kezdocim + 7);
  op3al = dueFlashStorage.read(kezdocim + 8);
  op4al = dueFlashStorage.read(kezdocim + 9);
  op5al = dueFlashStorage.read(kezdocim + 10);
  op6al = dueFlashStorage.read(kezdocim + 11);
  op1ar = dueFlashStorage.read(kezdocim + 12);
  op2ar = dueFlashStorage.read(kezdocim + 13);
  op3ar = dueFlashStorage.read(kezdocim + 14);
  op4ar = dueFlashStorage.read(kezdocim + 15);
  op5ar = dueFlashStorage.read(kezdocim + 16);
  op6ar = dueFlashStorage.read(kezdocim + 17);
  op1d1l = dueFlashStorage.read(kezdocim + 18);
  op2d1l = dueFlashStorage.read(kezdocim + 19);
  op3d1l = dueFlashStorage.read(kezdocim + 20);
  op4d1l = dueFlashStorage.read(kezdocim + 21);
  op5d1l = dueFlashStorage.read(kezdocim + 22);
  op6d1l = dueFlashStorage.read(kezdocim + 23);
  op1d1r = dueFlashStorage.read(kezdocim + 24);
  op2d1r = dueFlashStorage.read(kezdocim + 25);
  op3d1r = dueFlashStorage.read(kezdocim + 26);
  op4d1r = dueFlashStorage.read(kezdocim + 27);
  op5d1r = dueFlashStorage.read(kezdocim + 28);
  op6d1r = dueFlashStorage.read(kezdocim + 29);
  op1d2l = dueFlashStorage.read(kezdocim + 30);
  op2d2l = dueFlashStorage.read(kezdocim + 31);
  op3d2l = dueFlashStorage.read(kezdocim + 32);
  op4d2l = dueFlashStorage.read(kezdocim + 33);
  op5d2l = dueFlashStorage.read(kezdocim + 34);
  op6d2l = dueFlashStorage.read(kezdocim + 35);
  op1d2r = dueFlashStorage.read(kezdocim + 36);
  op2d2r = dueFlashStorage.read(kezdocim + 37);
  op3d2r = dueFlashStorage.read(kezdocim + 38);
  op4d2r = dueFlashStorage.read(kezdocim + 39);
  op5d2r = dueFlashStorage.read(kezdocim + 40);
  op6d2r = dueFlashStorage.read(kezdocim + 41);
  op1rl = dueFlashStorage.read(kezdocim + 42);
  op2rl = dueFlashStorage.read(kezdocim + 43);
  op3rl = dueFlashStorage.read(kezdocim + 44);
  op4rl = dueFlashStorage.read(kezdocim + 45);
  op5rl = dueFlashStorage.read(kezdocim + 46);
  op6rl = dueFlashStorage.read(kezdocim + 47);
  op1rr = dueFlashStorage.read(kezdocim + 48);
  op2rr = dueFlashStorage.read(kezdocim + 49);
  op3rr = dueFlashStorage.read(kezdocim + 50);
  op4rr = dueFlashStorage.read(kezdocim + 51);
  op5rr = dueFlashStorage.read(kezdocim + 52);
  op6rr = dueFlashStorage.read(kezdocim + 53);
  pichal = dueFlashStorage.read(kezdocim + 54);
  pichar = dueFlashStorage.read(kezdocim + 55);
  pichd1l = dueFlashStorage.read(kezdocim + 56);
  pichd1r = dueFlashStorage.read(kezdocim + 57);
  pichd2l = dueFlashStorage.read(kezdocim + 58);
  pichd2r = dueFlashStorage.read(kezdocim + 59);
  pichrl = dueFlashStorage.read(kezdocim + 60);
  pichrr = dueFlashStorage.read(kezdocim + 61);
  op1volume = dueFlashStorage.read(kezdocim + 62);
  op2volume = dueFlashStorage.read(kezdocim + 63);
  op3volume = dueFlashStorage.read(kezdocim + 64);
  op4volume = dueFlashStorage.read(kezdocim + 65);
  op5volume = dueFlashStorage.read(kezdocim + 66);
  op6volume = dueFlashStorage.read(kezdocim + 67);
  op1veloc = dueFlashStorage.read(kezdocim + 68);
  op2veloc = dueFlashStorage.read(kezdocim + 69);
  op3veloc = dueFlashStorage.read(kezdocim + 70);
  op4veloc = dueFlashStorage.read(kezdocim + 71);
  op5veloc = dueFlashStorage.read(kezdocim + 72);
  op6veloc = dueFlashStorage.read(kezdocim + 73);
  op1generatorfreq = dueFlashStorage.read(kezdocim + 74);
  op2generatorfreq = dueFlashStorage.read(kezdocim + 75);
  op3generatorfreq = dueFlashStorage.read(kezdocim + 76);
  op4generatorfreq = dueFlashStorage.read(kezdocim + 77);
  op5generatorfreq = dueFlashStorage.read(kezdocim + 78);
  op6generatorfreq = dueFlashStorage.read(kezdocim + 79);
  fixfreqstep = dueFlashStorage.read(kezdocim + 80);
  op1generatorfreqfix  = dueFlashStorage.read(kezdocim + 81) * 800 * fixfreqstep;
  op2generatorfreqfix  = dueFlashStorage.read(kezdocim + 82) * 800 * fixfreqstep;
  op3generatorfreqfix  = dueFlashStorage.read(kezdocim + 83) * 800 * fixfreqstep;
  op4generatorfreqfix  = dueFlashStorage.read(kezdocim + 84) * 800 * fixfreqstep;
  op5generatorfreqfix  = dueFlashStorage.read(kezdocim + 85) * 800 * fixfreqstep;
  op6generatorfreqfix  = dueFlashStorage.read(kezdocim + 86) * 800 * fixfreqstep;
  pichop1  = dueFlashStorage.read(kezdocim + 87);
  pichop2  = dueFlashStorage.read(kezdocim + 88);
  pichop3  = dueFlashStorage.read(kezdocim + 89);
  pichop4  = dueFlashStorage.read(kezdocim + 90);
  pichop5  = dueFlashStorage.read(kezdocim + 91);
  pichop6  = dueFlashStorage.read(kezdocim + 92);
  notefixedop1  = dueFlashStorage.read(kezdocim + 93);
  notefixedop2  = dueFlashStorage.read(kezdocim + 94);
  notefixedop3  = dueFlashStorage.read(kezdocim + 95);
  notefixedop4  = dueFlashStorage.read(kezdocim + 96);
  notefixedop5  = dueFlashStorage.read(kezdocim + 97);
  notefixedop6  = dueFlashStorage.read(kezdocim + 98);
  frame  = dueFlashStorage.read(kezdocim + 99);
  szorzo  = dueFlashStorage.read(kezdocim + 100);
  alg  = dueFlashStorage.read(kezdocim + 101);
  level  = dueFlashStorage.read(kezdocim + 102);
  pichkezd  = dueFlashStorage.read(kezdocim + 103);
  picheglevel  = dueFlashStorage.read(kezdocim + 104) * 500;
  oplfo  = dueFlashStorage.read(kezdocim + 105);
  oplfo2max  = dueFlashStorage.read(kezdocim + 106);
  oplfo4max  = dueFlashStorage.read(kezdocim + 107);
  oplfo6max  = dueFlashStorage.read(kezdocim + 108);
  lfo2step  = dueFlashStorage.read(kezdocim + 109);
  lfo4step  = dueFlashStorage.read(kezdocim + 110);
  lfo6step  = dueFlashStorage.read(kezdocim + 111);
  lfo1step  = dueFlashStorage.read(kezdocim + 112);
  lfo1max = dueFlashStorage.read(kezdocim + 113);
  lfo1min  = dueFlashStorage.read(kezdocim + 114);
  eqvalue  = dueFlashStorage.read(kezdocim + 115);
  lfofreq  = dueFlashStorage.read(kezdocim + 116);
  reverblevel  = dueFlashStorage.read(kezdocim + 117);
  reverbtime  = dueFlashStorage.read(kezdocim + 118) * 23;
  reverblevel2  = dueFlashStorage.read(kezdocim + 119);
  reverbtime2  = dueFlashStorage.read(kezdocim + 120) * 23;
  gorbeszorzo = dueFlashStorage.read(kezdocim + 121);
  released  = dueFlashStorage.read(kezdocim + 122);
}
