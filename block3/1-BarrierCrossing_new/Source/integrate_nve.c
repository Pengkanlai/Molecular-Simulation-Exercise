#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"

// integrate the equations of motion for an NVE system
// use either velocity verlet or leap-frog. you do not
// have to declare any new variables
//
// hint: use the following symbols:
//
// Tstep            : timestep integration
// Position         : old position
// OldF             : old force
// ConservedEnergy  : conserved quantity
//
// to calculate the force and energy for a given position,
// see force.c

//变量都定义在system.c里，所以这里不用重新定义

void IntegrateNVE(void)
{
  double U,F,NewVelocity;

  // start modification
  F= Force(Position,&U,&F);//calculate the force
  NewVelocity=Velocity+Tstep*F; //update the velocity
  Position = Position + NewVelocity*Tstep;
  //Conserved quantity is v(t)=(v_pos + v_new)/2.
  //We square them, so we need to factor of 8.
  ConservedEnergy=U+SQR(NewVelocity+Velocity)/8.0;
  Velocity=NewVelocity;
  OldF=F;
  // end modification
} 
