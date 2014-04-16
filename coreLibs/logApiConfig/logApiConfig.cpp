/******************************************************************************************************************
 *	File Name    - logApiConfig.cpp
 * Author       - gnarayana
 * Modifier     - gnarayana
 * Create Date  - 11/April/2014 
 * Modifed Date - 11/April/2014
 * Description  - Container class LogApiConfig implementation.
 * Project		 - NAL ( Network application logging )					
 * Module		 - LogManger
 * BU				 - DevGnana
 * Company		 - Cliff S
 * License		 - GPLV2 ( Open Source ) 
 ******************************************************************************************************************/
#include "logApiConfig.h"
#include <fstream>

std::atomic<LogApiConfig*> LogApiConfig::_instance ;
std::mutex	LogApiConfig::_mutex;

LogApiConfig* LogApiConfig::getInstance()
{
	if (_instance == nullptr) {
		_mutex.lock();
		_instance = new LogApiConfig();
		_mutex.unlock();
	}
	return _instance;
}

LogApiConfig::LogApiConfig():_statRdCfg(false)
{

}

void LogApiConfig::readConfig(const std::string filePath)
{
	if(!_statRdCfg)
	{
		//Implement read config and del ME :)
		std::ifstream ifile(filePath);
		while( !ifile.eof() )
		{
		}
	}
}

void LogApiConfig::updateConfig(const std::string& key,const std::string& value)
{
	if( !key.empty() || !value.empty() )	
	{
		try
		{
			if(_logApiCfg.find(key) == _logApiCfg.end() )
			{
				std::vector<std::string> tmp;
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

bool LogApiConfig::getConfigValue(const std::string& key,std::vector<std::string>& values) 
{
	if(_logApiCfg.find(key) != _logApiCfg.end() )
	{
		values = _logApiCfg[key];
		return true;
	}
	return false;
}

LogApiConfig::~LogApiConfig()
{

}

std::ostream& operator << ( std::ostream& out,const LogApiConfig& cfg)
{
	return out;
}


