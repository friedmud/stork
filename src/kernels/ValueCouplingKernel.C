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

#include "ValueCouplingKernel.h"

template<>
InputParameters validParams<ValueCouplingKernel>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("v", "Variable being coupled");
  return params;
}

ValueCouplingKernel::ValueCouplingKernel(const std::string & name, InputParameters parameters) :
    Kernel(name, parameters),
    _v(coupledValue("v"))
{
}

ValueCouplingKernel::~ValueCouplingKernel()
{
}

Real
ValueCouplingKernel::computeQpResidual()
{
  return _v[_qp];
}
