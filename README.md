# AudioVolume
SA-MP AudioVolume.inc 

## Instação

Faça download do arquivo e coloque na pasta Pawno -> include de seu projeto:
Coloque em seu projeto:

```pawn
#include <AudioVolume>
```

 * **Example**
 
 ```pawn
CMD:playaudio(playerid, params[])
{
	new url[128], volume;
	if(sscanf(params, "s[128]d", url, volume)) return SendClientMessage(playerid, 0xDADADAFF, "/playaudio <audio url> <volume>");
	PlayAudioStreamForPlayerEx(playerid, url, volume);
	return 1;
}

CMD:volumeaudio(playerid, params[])
{
	if(!strval(params)) return SendClientMessage(playerid, 0xDADADAFF, "/volumeaudio <volume>");
	if(!IsValidAudioStreamVolume(strval(params))) return SendClientMessage(playerid, 0xDADADAFF, "Volume: 10, 15, 20, 25, 30, 35...");
	VolumeAudioStreamForPlayer(playerid, strval(params));
	return 1;
}
 ```
