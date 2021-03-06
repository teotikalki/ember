/*
    Copyright (C) 2002  Hans Häggström
    Copyright (C) 2005	Erik Ogenvik

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "EmberServices.h"

#include "logging/LoggingService.h"
#include "config/ConfigService.h"
#include "input/InputService.h"
#include "sound/SoundService.h"
#include "metaserver/MetaserverService.h"
#include "server/ServerService.h"
#include "scripting/ScriptingService.h"
#include "wfut/WfutService.h"
#include "serversettings/ServerSettings.h"


template<> Ember::EmberServices* Ember::Singleton<Ember::EmberServices>::ms_Singleton = 0;
namespace Ember{


	EmberServices::~EmberServices()
	{
		if (mWfutService) {
			mWfutService->stop();
			delete mWfutService;
		}
		if (mServerService) {
			mServerService->stop();
			delete mServerService;
		}
		if (mServerSettingsService) {
			mServerSettingsService->stop();
			delete mServerSettingsService;
		}
		if (mMetaserverService) {
			mMetaserverService->stop();
			delete mMetaserverService;
		}
		if (mScriptingService) {
			mScriptingService->stop();
			delete mScriptingService;
		}
		if (mSoundService) {
			mSoundService->stop();
			delete mSoundService;
		}
		if (mInputService) {
			mInputService->stop();
			delete mInputService;
		}
		if (mConfigService) {
			mConfigService->stop();
			delete mConfigService;
		}
		if (mLoggingService) {
			mLoggingService->stop();
			delete mLoggingService;
		}
	}

	LoggingService& EmberServices::getLoggingService()
	{
		return *mLoggingService;
	}

	ConfigService& EmberServices::getConfigService()
	{
		return *mConfigService;
	}

	InputService& EmberServices::getInputService()
	{
		return *mInputService;
	}

	MetaserverService& EmberServices::getMetaserverService()
	{
		return *mMetaserverService;
	}
  
	ServerService& EmberServices::getServerService()
	{
		return *mServerService;
	}

	SoundService& EmberServices::getSoundService()
	{
		return *mSoundService;
	}

	ScriptingService& EmberServices::getScriptingService()
	{
		return *mScriptingService;
	}
  
	WfutService& EmberServices::getWfutService()
	{
		return *mWfutService;
	}
  
	Services::ServerSettings& EmberServices::getServerSettingsService() {
		return *mServerSettingsService;
	}

	EmberServices::EmberServices(Eris::Session& session)
	: mLoggingService(new LoggingService())
	, mScriptingService(new ScriptingService())
	, mSoundService(new SoundService())
	, mServerService(new ServerService(session))
	, mMetaserverService(new MetaserverService(session))
	, mInputService(new InputService())
	, mWfutService(new WfutService())
	, mConfigService(new ConfigService())
	, mServerSettingsService(new Services::ServerSettings())
	{
	}

}
