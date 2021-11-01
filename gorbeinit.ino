//---------------------------------GORBEINIT---------------------------------------
#define opattackinit(al, i, ar)(al*i*i/(ar*ar))

void pichgorbeinit() {
  //maxtime = op1ar + op1d1r + op1d2r + op1rr;
  for (int i = 0; i < GORBE_SIZE; i++)
  {
    pichgorbe[i] = 0;
  }
  if (pichar > 0) {
    for (uint16_t i = 0; i <= pichar; i++)
    {
      pichgorbe[i] = (pichal - pichkezd) / pichar * i + pichkezd;
    }
  }
  else {
    pichgorbe[0] = op1al;
  }
  for (uint16_t i = 0; i <= pichd1r; i++)
  {
    pichgorbe[pichar + i] = (pichal - (pichal - pichd1l) * i / pichd1r);
  }
  uint16_t segedindex = pichar + pichd1r;
  for (uint16_t i = 0; i <= pichd2r; i++)
  {
    pichgorbe[segedindex + i] = (pichd1l - (pichd1l - pichd2l) * i / pichd2r);
  }
  segedindex = pichar + pichd1r + pichd2r;
  uint16_t temprr = released * pichrr;
  for (uint16_t i = 0; i <= temprr; i++)
  {
    pichgorbe[segedindex + i] = (pichd2l - (pichd2l - pichrl) * i / temprr);
  }
}

void op1gorbeinit() {
 
  tvagorbegenerator(op1ar, op1al, op1d1l , op1d1r, op1d2l, op1d2r, op1rl, op1rr, op1gorbe);
  
 
}

void op2gorbeinit() {
  tvagorbegenerator(op2ar, op2al, op2d1l , op2d1r, op2d2l, op2d2r, op2rl, op2rr, op2gorbe);
}

void op3gorbeinit() {
  tvagorbegenerator(op3ar, op3al, op3d1l , op3d1r, op3d2l, op3d2r, op3rl, op3rr, op3gorbe);
}

void op4gorbeinit() {
  tvagorbegenerator(op4ar, op4al, op4d1l , op4d1r, op4d2l, op4d2r, op4rl, op4rr, op4gorbe);
}

void op5gorbeinit() {
  tvagorbegenerator(op5ar, op5al, op5d1l , op5d1r, op5d2l, op5d2r, op5rl, op5rr, op5gorbe);
}

void op6gorbeinit() {
  tvagorbegenerator(op6ar, op6al, op6d1l , op6d1r, op6d2l, op6d2r, op6rl, op6rr, op6gorbe);
}

void tvainit() {
  tvagorbegenerator(op1ar, op1al, op1d1l , op1d1r, op1d2l, op1d2r, op1rl, op1rr, op1gorbe);
  tvagorbegenerator(op2ar, op2al, op2d1l , op2d1r, op2d2l, op2d2r, op2rl, op2rr, op2gorbe);
  tvagorbegenerator(op3ar, op3al, op3d1l , op3d1r, op3d2l, op3d2r, op3rl, op3rr, op3gorbe);
  tvagorbegenerator(op4ar, op4al, op4d1l , op4d1r, op4d2l, op4d2r, op4rl, op4rr, op4gorbe);
  tvagorbegenerator(op5ar, op5al, op5d1l , op5d1r, op5d2l, op5d2r, op5rl, op5rr, op5gorbe);
  tvagorbegenerator(op6ar, op6al, op6d1l , op6d1r, op6d2l, op6d2r, op6rl, op6rr, op6gorbe);
}

void tvagorbegenerator (uint16_t ar, uint16_t al, uint16_t d1l, uint16_t d1r, uint16_t d2l, uint16_t d2r, uint16_t rl, uint16_t rr, uint16_t  opgorbe[]) {
  al *= gorbeszorzo;
  d1l *= gorbeszorzo;
  d2l *= gorbeszorzo;
  rl *= gorbeszorzo;
  // ar*=gorbeszorzo;
  rr *= released;

  for (int i = 0; i < GORBE_SIZE; i++)
  {
    opgorbe[i] = 0;
  }
  if (ar > 0) {
    for ( uint16_t i = 0; i <= ar; i++)
    {
      //opgorbe[i] = (al / ar * i);
      // opgorbe[i] = al*i*i/(ar*ar);
      opgorbe[i] = opattackinit(al, i, ar);
    }
  }
  else {
    opgorbe[0] = al;
  }
  for (int i = 0; i <= d1r; i++)
  {
    opgorbe[ar + i] = (al - (al - d1l) * i / d1r);
  }
  uint16_t segedindex = 0;
  segedindex = ar + d1r;
  for (int i = 0; i <= d2r; i++)
  {
    opgorbe[ segedindex + i] = (d1l - (d1l - d2l) * i / d2r);
  }
  segedindex = ar + d1r + d2r;

  for (int i = 0; i <= rr; i++)
  {
    // opgorbe[segedindex + i] = (d2l - (d2l - rl) * i / temprr);
    opgorbe[segedindex + i] = (d2l - rl) * (rr - i) * (rr - i) / (rr * rr) + rl;
  }
}

void maxreleaseset() {
  maxrelease0 = op1ar + op1d1r + op1d2r;
  maxrelease1 = op2ar + op2d1r + op2d2r;
  maxrelease2 = op3ar + op3d1r + op3d2r;
  maxrelease3 = op4ar + op4d1r + op4d2r;
  maxrelease4 = op5ar + op5d1r + op5d2r;
  maxrelease5 = op6ar + op6d1r + op6d2r;
}

void maxtimeset() {
  maxtime0 = op1ar + op1d1r + op1d2r + op1rr * released+1;
  maxtime1 = op2ar + op2d1r + op2d2r + op2rr * released+1;
  maxtime2 = op3ar + op3d1r + op3d2r + op3rr * released+1;
  maxtime3 = op4ar + op4d1r + op4d2r + op4rr * released+1;
  maxtime4 = op5ar + op5d1r + op5d2r + op5rr * released+1;
  maxtime5 = op6ar + op6d1r + op6d2r + op6rr * released+1;
}
/*
  void maxtimesetold() {
  maxtime = op1ar + op1d1r + op1d2r + op1rr * released;
  if ((op2ar + op2d1r + op2d2r + op2rr * released) > maxtime) {
    maxtime = op2ar + op2d1r + op2d2r + op2rr * released;
  }
  if ((op3ar + op3d1r + op3d2r + op3rr * released) > maxtime) {
    maxtime = op3ar + op3d1r + op3rr * released;
  }
  if ((op4ar + op4d1r + op4d2r + op4rr * released) > maxtime) {
    maxtime = op4ar + op4d1r + op4rr * released;
  }
  if ((op5ar + op5d1r + op5d2r + op5rr * released) > maxtime) {
    maxtime = op5ar + op5d1r + op5rr * released;
  }
  if ((op6ar + op6d1r + op6d2r + op6rr * released) > maxtime) {
    maxtime = op6ar + op6d1r + op6rr * released;
  }
  maxtime++;
  }
*/
