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

#include "ValueKernel.h"

template<>
InputParameters validParams<ValueKernel>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

ValueKernel::ValueKernel(const std::string & name, InputParameters parameters) :
    Kernel(name, parameters)
{
}

ValueKernel::~ValueKernel()
{
}

Real
ValueKernel::computeQpResidual()
{
  return -_test[_i][_qp]*_u[_qp];
}

Real
ValueKernel::computeQpJacobian()
{
  return -_test[_i][_qp]*_phi[_j][_qp];
}
