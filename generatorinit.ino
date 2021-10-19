//----------------------------GENERATORINIT-------------------------------------
void sinusinit() {
  for (int i = 0; i < FG_SIZE; i++)
  { sinusfg[i] = sin(i *  PI / 512) * 32000 ;
  }
}

void fmsinusinit() {
  for (int i = 0; i < FG_SIZE; i++)
  { fmsinusfg[i] = sin(i *  PI / 512) * 1024 ;
  }
}

void negyszoginit() {
  int db = FG_SIZE;
  int fel = db / 2;
  int max = 8000;
  int min = -8000;
  int ertek = 0;
  for (int i = 0; i < db; i++)
  {
    if (i > fel) {
      ertek = max;
    }
    if (i < fel)
    { ertek = min;
    }
    negyszogfg[i] = ertek;
  }
  // negyszogfg[0] = 0;
  //negyszogfg[FG_SIZE] = 0;
}

void fmnegyszoginit() {
  int db = FG_SIZE;
  int fel = db / 2;
  int max = 1023;
  int min = -1023;
  int ertek = 0;
  for (int i = 0; i < db; i++)
  {
    if (i >= fel) {
      ertek = max;
    }
    if (i < fel)
    { ertek = min;
    }
    fmnegyszogfg[i] = ertek;
  }
  //fmnegyszogfg[0] = 0;
  //negyszogfg[FG_SIZE] = 0;
}

void fureszoginit() {
  int db = FG_SIZE;
  int ertek = 0;
  for (int i = 0; i < db; i++) {
    ertek = i  * 16;
    fureszfg[i] = ertek;
  }
  //fureszfg[0] = 0;
  // fureszfg[FG_SIZE] = 0;
}

void fmfureszoginit() {
  int db = FG_SIZE;
  int ertek = 0;
  for (int i = 0; i < db; i++) {
    ertek = i - (FG_SIZE / 2);
    fureszfg[i] = ertek;
  }
  fmfureszfg[0] = 0;
  fmfureszfg[FG_SIZE] = 0;
}

void haromszoginit() {
  int db = FG_SIZE;
  for (int i = 0; i < db; i++) {
    int16_t haromnegyed = db / 4 * 3;
    int16_t fel = db / 2;
    int16_t negyed = db / 4;
    int ertek = 0;
    if (i <= negyed) {
      ertek = i;
    }
    if ((i > negyed) && (i <= haromnegyed)) {
      ertek = -1 * i + fel;
    }
    if (i > haromnegyed) {
      ertek = i - db;
    }
    haromszogfg[i] = ertek * 33;
  }
}

void fmharomszoginit() {
  int db = FG_SIZE;
  for (int i = 0; i < db; i++) {
    int16_t haromnegyed = db / 4 * 3;
    int16_t fel = db / 2;
    int16_t negyed = db / 4;
    int ertek = 0;
    if (i <= negyed) {
      ertek = i;
    }
    if ((i > negyed) && (i <= haromnegyed)) {
      ertek = -1 * i + fel;
    }
    if (i > haromnegyed) {
      ertek = i - db;
    }
    fmharomszogfg[i] = ertek;
  }
}

void fmharomszoginitold() {
  int db = FG_SIZE;
  int dbfel = FG_SIZE / 2;
  for (int i = 0; i < dbfel; i++) {
    fmharomszogfg[i] = i * 2;
  }
  for (int i = 0; i < dbfel; i++) {
    fmharomszogfg[i + dbfel] = FG_SIZE - i * 2;
  }
  for (int i = 0; i < db; i++) {
    fmharomszogfg[i] = fmharomszogfg[i] - FG_SIZE / 2;
  }
}

void zajinit() {
  int db = FG_SIZE;
  for (int i = 0; i < db; i++) {
    zajfg[i] = random(-10000, 10000);
  }
}

void duplafginit() {
  for (int i = 0; i <= FG_SIZE; i++)
  {
    douplafg[i] = sin(i *  PI / 512) * 16000 ;
  }
  for (int i = 0; i <= FG_SIZE / 2; i++) {
    douplafg[i] += sinusfg[i * 2] / 2 ;
    douplafg[i + FG_SIZE / 2] += sinusfg[i * 2] / 2 ;
  }
}

void triplafginit() {
  for (int i = 0; i <= FG_SIZE; i++)
  {
    triplafg[i] = sin(i *  PI / 512) * 16000 ;
  }
  for (int i = 0; i <= FG_SIZE / 2; i++) {
    triplafg[i] += sinusfg[i * 2] / 2 ;
    triplafg[i + FG_SIZE / 2] += sinusfg[i * 2] / 2 ;
  }
  for (int i = 0; i <= FG_SIZE / 4; i++) {
    triplafg[i] += sinusfg[i * 4] / 4 ;
    triplafg[i + FG_SIZE / 4] += sinusfg[i * 4] / 4 ;
    triplafg[i + FG_SIZE / 2] += sinusfg[i * 4] / 4 ;
    triplafg[i + 3 * FG_SIZE / 4] += sinusfg[i * 4] / 4 ;
  }
}


void generatorinitone(byte opwaveform, int16_t generator[]) {
  switch (opwaveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = sinusfg[i];
      }
      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator[i] = triplafg[i];
      }
      break;
  }
}



void generatorinit(byte op1waveform, byte op2waveform, byte op3waveform, byte op4waveform, byte op5waveform, byte op6waveform) {
  generatorinitone(op1waveform, generator1);
  generatorinitone(op2waveform, generator2);
  generatorinitone(op3waveform, generator3);
  generatorinitone(op4waveform, generator4);
  generatorinitone(op5waveform, generator5);
  generatorinitone(op6waveform, generator6);
/*

  switch (op1waveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = sinusfg[i];
      }
      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = triplafg[i];
      }
      break;
  }

  switch (op2waveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = sinusfg[i];
      }
      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator2[i] = triplafg[i];
      }
      break;
  }

  switch (op3waveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = sinusfg[i];
      }
      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator3[i] = triplafg[i];
      }
      break;
  }
  switch (op4waveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = sinusfg[i];
      }
      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator4[i] = triplafg[i];
      }
      break;
  }

  switch (op5waveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = sinusfg[i];
      }

      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator1[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator5[i] = triplafg[i];
      }
      break;
  }

  switch (op6waveform) {
    case 0:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = 0;
      }
      break;
    case 1:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = sinusfg[i];
      }

      break;
    case 2:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = fmsinusfg[i];
      }
      break;
    case 3:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = haromszogfg[i];
      }
      break;
    case 4:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = fmharomszogfg[i];
      }
      break;
    case 5:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = fureszfg[i];
      }
      break;
    case 6:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = fmfureszfg[i];
      }
      break;
    case 7:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = negyszogfg[i];
      }
      break;
    case 8:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = fmnegyszogfg[i];
      }
      break;
    case 9:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = zajfg[i];
      }
      break;
    case 10:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = fmzajfg[i];
      }
      break;
    case 11:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = douplafg[i];
      }
      break;
    case 12:
      for (int i = 0; i < FG_SIZE; i++) {
        generator6[i] = triplafg[i];
      }
      break;
  }
  */
}
