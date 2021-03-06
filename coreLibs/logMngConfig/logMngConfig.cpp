/******************************************************************************************************************
 *	File Name    - logMngConfig.cpp
 * Author       - gnarayana
 * Modifier     - gnarayana
 * Create Date  - 11/April/2014 
 * Modifed Date - 11/April/2014
 * Description  - Container class LogMngConfig implementation.
 * Project		 - NAL ( Network application logging )					
 * Module		 - LogManger
 * BU				 - DevGnana
 * Company		 - Cliff S
 * License		 - GPLV2 ( Open Source ) 
 ******************************************************************************************************************/
#include "logMngConfig.h"

atomic<LogMngConfig*> LogMngConfig::_instance ;
mutex	LogMngConfig::_mutex;

LogMngConfig* LogMngConfig::getInstance()
{
	if (_instance == nullptr) {
		_mutex.lock();
		_instance = new LogMngConfig();
		_mutex.unlock();
	}
	return _instance;
}

LogMngConfig::LogMngConfig():_statRdCfg(false)
{

}

void LogMngConfig::readConfig(const string filePath)
{
	if(_statRdCfg)
	{
		//Implement read config and del ME :)
	}
}

void LogMngConfig::updateConfig(const string& key,const string& value)
{
	if( !key.empty() || !value.empty() )	
	{
		try
		{
			if(_logApiCfg.find(key) == _logApiCfg.end() )
			{
				vector<string> tmp;
				_logApiCfg[key] =tmp; 
				_logApiCfg[key].push_back(value);
			}
			_logApiCfg[key].push_back(value);
		}
		catch(...)
		{
			throw;
		}
	}
}

bool LogMngConfig::getConfigValue(const string& key,vector<string>& values) 
{
	if(_logApiCfg.find(key) != _logApiCfg.end() )
	{
		values = _logApiCfg[key];
		return true;
	}
	return false;
}

LogMngConfig::~LogMngConfig()
{

}

ostream& operator << ( ostream& out,const LogMngConfig& cfg)
{
	return out;
}


