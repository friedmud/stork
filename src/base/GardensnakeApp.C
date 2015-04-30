#include "GardensnakeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<GardensnakeApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

GardensnakeApp::GardensnakeApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  GardensnakeApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  GardensnakeApp::associateSyntax(_syntax, _action_factory);
}

GardensnakeApp::~GardensnakeApp()
{
}

void
GardensnakeApp::registerApps()
{
  registerApp(GardensnakeApp);
}

void
GardensnakeApp::registerObjects(Factory & factory)
{
}

void
GardensnakeApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
