#pragma once
class VolumeManager
{
private:
	static float masterVolume;
public:
	VolumeManager();
	static void setMasterVolume(float volume);
	static int getMasterVolume();
	static float apply(float volume);
};

