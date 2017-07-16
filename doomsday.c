/*
 * doomsday.c - small, shiny Doomsday Device Controller
 * Copyright (C) 2016-2017, phip (/dev/tal e. V.)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


char a =   0;  //   a
char b =   2;  // f   b
char c =   4;  //   g
char d =   7;  // e   c
char e =   8;  //   d
char f =   1;  //
char g =   3;  // see <https://de.wikipedia.org/wiki/Segmentanzeige> 
char ld =  6;  //
//char rd =  5;  //
enum {nn = 6}; //

char l[nn] = {5, 9, 10, 11, 12, 13};
unsigned int del = 100;
unsigned int plexdel = 1;

void nOut(char n) {
  switch(n) {
    case 0:
    //default:
      digitalWrite(a,  LOW);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  LOW);
      digitalWrite(e,  LOW);
      digitalWrite(f,  LOW);
      digitalWrite(g,  HIGH);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 1:
      digitalWrite(a,  HIGH);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  HIGH);
      digitalWrite(e,  HIGH);
      digitalWrite(f,  HIGH);
      digitalWrite(g,  HIGH);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 2:
      digitalWrite(a,  LOW);
      digitalWrite(b,  LOW);
      digitalWrite(c,  HIGH);
      digitalWrite(d,  LOW);
      digitalWrite(e,  LOW);
      digitalWrite(f,  HIGH);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 3:
      digitalWrite(a,  LOW);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  LOW);
      digitalWrite(e,  HIGH);
      digitalWrite(f,  HIGH);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 4:
      digitalWrite(a,  HIGH);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  HIGH);
      digitalWrite(e,  HIGH);
      digitalWrite(f,  LOW);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 5:
      digitalWrite(a,  LOW);
      digitalWrite(b,  HIGH);
      digitalWrite(c,  LOW);
      digitalWrite(d,  LOW);
      digitalWrite(e,  HIGH);
      digitalWrite(f,  LOW);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 6:
      digitalWrite(a,  LOW);
      digitalWrite(b,  HIGH);
      digitalWrite(c,  LOW);
      digitalWrite(d,  LOW);
      digitalWrite(e,  LOW);
      digitalWrite(f,  LOW);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 7:
      digitalWrite(a,  LOW);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  HIGH);
      digitalWrite(e,  HIGH);
      digitalWrite(f,  HIGH);
      digitalWrite(g,  HIGH);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 8:
      digitalWrite(a,  LOW);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  LOW);
      digitalWrite(e,  LOW);
      digitalWrite(f,  LOW);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;

    case 9:
      digitalWrite(a,  LOW);
      digitalWrite(b,  LOW);
      digitalWrite(c,  LOW);
      digitalWrite(d,  LOW);
      digitalWrite(e,  HIGH);
      digitalWrite(f,  LOW);
      digitalWrite(g,  LOW);
      digitalWrite(ld, HIGH);
      //digitalWrite(rd, HIGH);
      break;
  }
}

void getOut(unsigned long int n){
  char z[nn] = {
    char( n/100000),
    char((n/10000)%10),
    char((n/1000) %10),
    char((n/100)  %10),
    char((n/10)   %10),
    char( n       %10)
  };

  unsigned int countadd = del/plexdel;
  unsigned int count = 0;

  while(count<del) {
    for (char i=0; i<nn; i++){
      for (char j=0; j<nn; j++){
        if (i != j) digitalWrite(l[j], LOW);
        else digitalWrite(l[j], HIGH);
      }
      nOut(z[i]);
      delay(plexdel);
      count++;
    }
  }
}

void setup() {
  pinMode(a,  OUTPUT);
  pinMode(b,  OUTPUT);
  pinMode(c,  OUTPUT);
  pinMode(d,  OUTPUT);
  pinMode(e,  OUTPUT);
  pinMode(f,  OUTPUT);
  pinMode(g,  OUTPUT);
  pinMode(ld, OUTPUT);
  //pinMode(rd, OUTPUT);

  for (char i=0; i<nn; i++){
    pinMode(l[i], OUTPUT);
    digitalWrite(l[0], LOW);
  }

  digitalWrite(a,  LOW);
  digitalWrite(b,  LOW);
  digitalWrite(c,  LOW);
  digitalWrite(d,  LOW);
  digitalWrite(e,  LOW);
  digitalWrite(f,  LOW);
  digitalWrite(g,  LOW);
  digitalWrite(ld, LOW);
  //digitalWrite(rd, LOW);
}

void loop() {
  unsigned long int i = 216000;
  while (i>0) {
    getOut(i);
    i--;
  }
  getOut(0);
}
