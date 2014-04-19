#ifndef HOCFDAPP_H
#define HOCFDAPP_H

#include "MooseApp.h"

class HocfdApp;

template<>
InputParameters validParams<HocfdApp>();

class HocfdApp : public MooseApp
{
public:
  HocfdApp(const std::string & name, InputParameters parameters);
  virtual ~HocfdApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HOCFDAPP_H */
