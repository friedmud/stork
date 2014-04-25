#include "ProtozoaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

#include "ValueKernel.h"
#include "ValueCouplingKernel.h"

template<>
InputParameters validParams<ProtozoaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ProtozoaApp::ProtozoaApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ProtozoaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ProtozoaApp::associateSyntax(_syntax, _action_factory);
}

ProtozoaApp::~ProtozoaApp()
{
}

void
ProtozoaApp::registerApps()
{
  registerApp(ProtozoaApp);
}

void
ProtozoaApp::registerObjects(Factory & factory)
{
  registerKernel(ValueKernel);
  registerKernel(ValueCouplingKernel);
}

void
ProtozoaApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
