#include <a_samp>
#include <Pawn.CMD>
#include <AudioVolume>

CMD:playaudio(playerid, params[])
{
	if(isnull(params)) return SendClientMessage(playerid, 0xDADADAFF, "/playaudio <audio url>");
	PlayAudioStreamForPlayer(playerid, params);
	return 1;
}

CMD:volumeaudio(playerid, params[])
{
	if(!strval(params)) return SendClientMessage(playerid, 0xDADADAFF, "/volumeaudio <volume>");
	if(!IsValidAudioStreamVolume(strval(params))) return SendClientMessage(playerid, 0xDADADAFF, "Volume: 10, 15, 20, 25, 30, 35...");
	VolumeAudioStreamForPlayer(playerid, strval(params));
	return 1;
}
CMD:playaudio2(playerid, params[])
{
	new url[128], volume;
	if(sscanf(params, "s[128]d", url, volume)) return SendClientMessage(playerid, 0xDADADAFF, "/playaudio2 <audio url> <volume>");
	PlayAudioStreamForPlayerEx(playerid, url, volume);
	return 1;
}

CMD:stopaudio(playerid)
	return StopAudioStreamForPlayer(playerid);
