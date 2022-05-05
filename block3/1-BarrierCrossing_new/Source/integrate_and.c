#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "ran_uniform.h"

// integrate the equations of motion for the Andersen thermostat
void IntegrateAndersen(void)
{
  double U,F;

  // start modification
    Position+=0.5*OldF*SQR(Tstep)+Tstep*Velocity;
    Velocity+=0.5*OldF*Tstep;
    Force(Position,&U,&F);
    Velocity+=0.5*F*Tstep;
    ConservedEnergy=0.0; //because we are using Anderson Thermostat
    OldF=F;

    // Random Velocity 
    if(RandomNumber()<(Nu*Tstep))
    {
      Velocity=RandomVelocity(Temperature);
    }
  // end modification
}
