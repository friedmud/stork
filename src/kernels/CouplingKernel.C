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

#include "CouplingKernel.h"

template<>
InputParameters validParams<CouplingKernel>()
{
  InputParameters params = validParams<Kernel>();
  params.addCoupledVar("v", "Variable being coupled");
  return params;
}

CouplingKernel::CouplingKernel(const std::string & name, InputParameters parameters) :
    Kernel(name, parameters),
    _v(coupledValue("v"))
{
}

CouplingKernel::~CouplingKernel()
{
}

Real
CouplingKernel::computeQpResidual()
{
  return _v[_qp];
}
