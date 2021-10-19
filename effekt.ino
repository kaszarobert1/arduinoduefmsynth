/*
void reverbold(){
    //Delay:
      bufferbe += delaybuffer[delaybufferindex];
      delaybuffer[delaybufferindex] = (reverblevel - 1) * bufferbe / reverblevel;
      if (bufferindex % revalg == 0) {
        delaybufferindex++;
      }
      if (delaybufferindex > reverbtime) {
        delaybufferindex = 0;
      }
  }

long limiter(long ertek, long vagas) {
  long haromnegyed = vagas / 4 * 3;
  if (ertek < vagas && ertek > haromnegyed) {
    ertek = ertek - (ertek - haromnegyed) / 4;
  }
  if (ertek > (vagas * -1) && ertek < (haromnegyed * -1)) {
    ertek = ertek - (ertek + haromnegyed) / 4;
  }

  if (ertek > vagas) {
    ertek = vagas;
  }
  if (ertek < vagas * -1) {
    ertek = vagas * -1;
  }
  return ertek;
}

long eq(long ertek, int f1, int  f2, long buff) {
  ertek = (f1 * y + f2 * buff) / 10000;
  return ertek;
}


*/
//samplefilter
