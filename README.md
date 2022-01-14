# Introduction

##### this program was made by @sp193 al credits go to him

##### [Original download site](https://sites.google.com/view/ysai187/home/projects/hdlgameinstaller)

##### this repository holds the latest version, with minor changes.


The HDLoader game installer allows the user to install PlayStation 2 games onto the installed Harddisk Drive, for direct booting with the HDDOSD (Browser v2.00 update).

It can also be used as an alternative to HDLDump, as this software does not use the HDLDump protocol and hence entirely uses TCP for data transfer. This means that unlike HDLDump, it's more reliable.

# features: 

- Installs all PlayStation 2 games from the CD/DVD drive.
- Installs all PlayStation 2 games remotely from a PC, over a network.
- Installed games can be booted directly from the HDDOSD.
- Allows the user to manage games locally on the PlayStation 2 console itself.
- Allows the user to manage games remotely from a PC, over a network.
- Network performance uses the latest ethernet modules from the PS2SDK, giving about 4MB/s.
- Allows the user to specify the savedata icon to use with the game.
- Supports games >4GB and DVD-DL games.
- Game list can be sorted alphabetically (controlled from the PlayStation 2).
- Supports the Dynamic Host Configuration Protocol (DHCP), for easy set up.
- Setting Storage


Settings are now saved into the HDLGameInstaller save data folder: 
```
hdd0:__common/Your Saves/HDLGAMEINSTALLER
```

__If you wish to delete the save, you may do so with the HDD Browser or compatible homebrew (e.g. LaunchELF).__

## Notes on network support
HDLGameInstaller now maintains its own network configuration file on the HDD unit.

If you have not configured HDLGameInstaller before, your existing homebrew network settings will be automatically imported from IPCONFIG.DAT.

Network settings can now be configured from the Options menu.

Please ensure that TCP ports `45061` and `45062` are allowed in your network.

If you use the Windows Firewall, you may have to allow "public" access for HDLGManClient.exe.

Pad support worsens performance. However, it is possible to connect to the PS2 at any time, even when the options screen is displayed.  If this is done, then the software will not disable pad input until the options menu is closed. For best performance, keep the options menu closed.

## Supported Devices

HDLGameInstaller may be installed (copied) onto and can be booted from: 

```
USB Mass Storage Devices. 
Only USB disks are supported. Multi-function devices are not supported.
The disk must have only one partition. Otherwise, the first partition will be accessed.
PlayStation 2 HDD Unit.
```
#### Other devices are not supported.


## Known limitations/bugs
- The icon preview does not totally right. I don't have the knowledge nor resources to commit towards fixing it up. Someone else will have to solve this, sorry.
- The UI isn't the nicest one, but it works.
- No Japanese input support on the PS2 installer's end.
- DVD9 games are supported from the PC client only, as the CDVDMAN module within the boot ROMs of all consoles does not support DVD9 layer 1.
- Not compatible with the APAEXT partitioning scheme (i.e. ToxicOS).  !!!Do not use this software with a disk formatted with APAEXT, or data loss will occur!!! 
- As the variable-width font may result in an uneven number of characters being displayed on the screen as a line is scrolled, the user may observe that the cursor might jump back by one place while scrolling. This is not a bug. 

