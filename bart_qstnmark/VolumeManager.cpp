#include "VolumeManager.h"
#include <algorithm>



VolumeManager::VolumeManager()
{
}
void VolumeManager::setMasterVolume(float volume)
{
    masterVolume = std::clamp(volume, 0.f, 100.f);
}

int VolumeManager::getMasterVolume()
{
    return masterVolume;
}


float VolumeManager::apply(float volume)
{
    return volume * masterVolume / 100.f;
}


   


