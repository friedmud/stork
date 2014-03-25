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

#ifndef VALUEKERNEL_H
#define VALUEKERNEL_H

#include "Kernel.h"

class ValueKernel;

template<>
InputParameters validParams<ValueKernel>();

/**
 * Kernel that is calling coupledDot
 */
class ValueKernel : public Kernel
{
public:
  ValueKernel(const std::string & name, InputParameters parameters);
  virtual ~ValueKernel();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
};


#endif /* VALUECOUPLINGKERNEL_H */
