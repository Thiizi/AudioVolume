/*
 *  AudioVolume.inc by Thiizi
 *
 *  (c) Copyright 2021, https://github.com/Thiizi
 *
 * native bool:IsValidAudioStreamVolume(volume);
 * native PlayAudioStreamForPlayerEx(playerid, const url[], volume);
 * native VolumeAudioStreamForPlayer(playerid, volume);
*/

#if defined _AdV_included
	#endinput
#endif
#define _AdV_included

#include <a_samp>

#if !defined NULL
	new stock NULL[2] = {1, 0};
#endif

#if !defined isnull
	#define isnull(%1) \
		((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#if defined MAX_URL_AUDIO_STREAM
    #undef MAX_URL_AUDIO_STREAM
#endif
#define MAX_URL_AUDIO_STREAM 2084

static AudioVolumeURL[MAX_PLAYERS][MAX_URL_AUDIO_STREAM];

stock bool:IsValidAudioStreamVolume(volume)
{
	static const integerVolumes[] = { 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 };
	for(new i; i < sizeof integerVolumes; i++) if(volume == integerVolumes[i]) return true;
	return false;
}

stock PlayAudioStreamForPlayerEx(playerid, const url[], volume)
{
    format(AudioVolumeURL[playerid], MAX_URL_AUDIO_STREAM, url);
    return VolumeAudioStreamForPlayer(playerid, volume);
}

stock VolumeAudioStreamForPlayer(playerid, volume)
{
	if(!IsValidAudioStreamVolume(volume) || isnull(AudioVolumeURL[playerid])) return 0;
    StopAudioStreamForPlayer(playerid);
	switch(volume)
	{
		case 10: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 90000.0, 100000.0, true);
		case 15: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 80000.5, 100000.0, true);
		case 20: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 80000.0, 100000.0, true);
		case 25: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 70000.5, 100000.0, true);
		case 30: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 70000.0, 100000.0, true);
		case 35: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 60000.5, 100000.0, true);
		case 40: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 60000.0, 100000.0, true);
		case 45: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 50000.5, 100000.0, true);
		case 50: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 50000.0, 100000.0, true);
		case 55: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 40000.5, 100000.0, true);
		case 60: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 40000.0, 100000.0, true);
		case 65: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 30000.5, 100000.0, true);
		case 70: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 30000.0, 100000.0, true);
		case 75: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 20000.5, 100000.0, true);
		case 80: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 20000.0, 100000.0, true);
		case 85: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 10000.5, 100000.0, true);
		case 90: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 10000.0, 100000.0, true);
		case 95: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid], 0.0, 0.0, 00000.5, 100000.0, true);
		case 100: return PlayAudioStreamForPlayer(playerid, AudioVolumeURL[playerid]);
	}
    return 0;
}

stock ALS_AudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0)
{
	format(AudioVolumeURL[playerid], MAX_URL_AUDIO_STREAM, url);
	return PlayAudioStreamForPlayer(playerid, url, posX, posY, posZ, distance, usepos);
}

stock ALS_StopAudioStreamForPlayer(playerid)
{
    AudioVolumeURL[playerid] = NULL;
    return StopAudioStreamForPlayer(playerid);
}

public OnPlayerConnect(playerid)
{
    AudioVolumeURL[playerid] = NULL;

	#if defined AdV_OnPlayerConnect
		return AdV_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect AdV_OnPlayerConnect
#if defined AdV_OnPlayerConnect
	forward AdV_OnPlayerConnect(playerid);
#endif


#if defined _ALS_PlayAudioStreamForPlayer
	#undef PlayAudioStreamForPlayer
#else
	#define _ALS_PlayAudioStreamForPlayer
#endif
#define PlayAudioStreamForPlayer ALS_AudioStreamForPlayer

#if defined _ALS_StopAudioStreamForPlayer
	#undef StopAudioStreamForPlayer
#else
	#define _ALS_StopAudioStreamForPlayer
#endif
#define StopAudioStreamForPlayer ALS_StopAudioStreamForPlayer