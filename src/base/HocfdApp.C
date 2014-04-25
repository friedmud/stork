#include "HocfdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<HocfdApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

HocfdApp::HocfdApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  HocfdApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  HocfdApp::associateSyntax(_syntax, _action_factory);
}

HocfdApp::~HocfdApp()
{
}

void
HocfdApp::registerApps()
{
  registerApp(HocfdApp);
}

void
HocfdApp::registerObjects(Factory & factory)
{
}

void
HocfdApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
