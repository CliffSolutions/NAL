/******************************************************************************************************************
 *	File Name    - logApiConfig.h
 * Author       - gnarayana
 * Modifier     - gnarayana
 * Create Date  - 14/April/2014 
 * Modifed Date - 14/April/2014
 * Description  - Container class to hold configuration related logging infra 
 *						 - Current Implementation is for text file and XML file
 *						 - Database stubs will be not be implemented.
 * Project		 - NAL ( Network application logging )					
 * Module		 - LogManger
 * BU				 - DevGnana
 * Company		 - Cliff S
 * License		 - GPLV2 ( Open Source ) 
 ******************************************************************************************************************/
#ifndef __LOG_API_CONFIG__
#define __LOG_API_CONFIG__
#include <vector>
#include <map>
#include <mutex>
#include <thread>
#include <atomic>
#include <string>
#include <iostream>

typedef std::map<std::string,std::vector<std::string> > logApiConfig_t;

class LogApiConfig
{
	public:
		static LogApiConfig* getInstance();
		void readConfig(const std::string cfgFilePath);	
		bool getConfigValue(const std::string& key,std::vector<std::string>& value) ;
		~LogApiConfig();
	private:
		void updateConfig(const std::string& key,const std::string& value);
		LogApiConfig();
		LogApiConfig(const LogApiConfig&);
		LogApiConfig& operator = ( const LogApiConfig&);
	private:
		logApiConfig_t _logApiCfg;
		static std::atomic<LogApiConfig*> _instance;
		static std::mutex _mutex;
		bool   _statRdCfg;
	friend
		std::ostream& operator << ( std::ostream& out,const LogApiConfig&);
};

#endif
