/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef COUPLINGKERNEL_H
#define COUPLINGKERNEL_H

#include "Kernel.h"

class CouplingKernel;

template<>
InputParameters validParams<CouplingKernel>();

/**
 * Kernel that is calling coupledDot
 */
class CouplingKernel : public Kernel
{
public:
  CouplingKernel(const std::string & name, InputParameters parameters);
  virtual ~CouplingKernel();

protected:
  virtual Real computeQpResidual();

  VariableValue & _v;
};


#endif /* COUPLINGKERNEL_H */
