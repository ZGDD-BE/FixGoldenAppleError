/**
 * @file plugin.cpp
 * @brief The main file of the plugin
 */

#include <llapi/LoggerAPI.h>

#include "version.h"

// We recommend using the global logger.
extern Logger logger;

/**
 * @brief The entrypoint of the plugin. DO NOT remove or rename this function.
 *        
 */
void PluginInit()
{
    // Your code here

    logger.info("loaded!");
    logger.info("Author: Dofes");
}

#include <llapi/mc/Actor.hpp>
#include <llapi/mc/AbsorptionMobEffect.hpp>
#include <llapi/mc/MobEffect.hpp>
#include <llapi/mc/SharedAttributes.hpp>
#include <llapi/mc/AttributeInstance.hpp>
THook(void, "?updateEffects@MobEffect@@UEAAXPEAVActor@@HH@Z",
      MobEffect *_this,
      Actor *target,
      int durationTicks,
      int amplification)
{
    if (_this->getId() == (int)MobEffect::EffectType::Absorption)
    {
        target->getMutableAttribute(SharedAttributes::ABSORPTION)->resetToDefaultValue();
    }
    original(_this, target, durationTicks, amplification);
}