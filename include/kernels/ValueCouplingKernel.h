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

#ifndef VALUECOUPLINGKERNEL_H
#define VALUECOUPLINGKERNEL_H

#include "Kernel.h"

class ValueCouplingKernel;

template<>
InputParameters validParams<ValueCouplingKernel>();

/**
 * Kernel that is calling coupledDot
 */
class ValueCouplingKernel : public Kernel
{
public:
  ValueCouplingKernel(const std::string & name, InputParameters parameters);
  virtual ~ValueCouplingKernel();

protected:
  virtual Real computeQpResidual();

  VariableValue & _v;
};


#endif /* VALUECOUPLINGKERNEL_H */
