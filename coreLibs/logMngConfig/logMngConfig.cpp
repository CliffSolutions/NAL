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
			if(_logMngCfg.find(key) == _logMngCfg.end() )
			{
				vector<string> tmp;
				_logMngCfg[key] =tmp; 
				_logMngCfg[key].push_back(value);
			}
			_logMngCfg[key].push_back(value);
		}
		catch(...)
		{
			throw;
		}
	}
}

bool LogMngConfig::getConfigValue(const string& key,vector<string>& values) 
{
	if(_logMngCfg.find(key) != _logMngCfg.end() )
	{
		values = _logMngCfg[key];
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


