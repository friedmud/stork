#ifndef PROTOZOAAPP_H
#define PROTOZOAAPP_H

#include "MooseApp.h"

class ProtozoaApp;

template<>
InputParameters validParams<ProtozoaApp>();

class ProtozoaApp : public MooseApp
{
public:
  ProtozoaApp(const std::string & name, InputParameters parameters);
  virtual ~ProtozoaApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* PROTOZOAAPP_H */
