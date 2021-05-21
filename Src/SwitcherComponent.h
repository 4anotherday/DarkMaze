#pragma once
#include "InteractiveObjectComponent.h"
#include <string>

class LightComponent;
class SwitcherComponent : public InteractiveObjectComponent
{
public:
    SwitcherComponent();

    virtual void awake(luabridge::LuaRef& data) override;

    virtual void start() override;

    /// <summary>
    /// Activates or deactivates an deactivatable object
    /// </summary>
    virtual void interact() override;

private:
    LightComponent* _light;
    std::string _deactivatableName;   
};

