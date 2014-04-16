/******************************************************************************************************************
 *	File Name    - logMngConfig.h
 * Author       - gnarayana
 * Modifier     - gnarayana
 * Create Date  - 11/April/2014 
 * Modifed Date - 11/April/2014
 * Description  - Container class to hold configuration related to logManager
 *						 - Current Implementation is for text file and XML file
 *						 - Database stubs will be not be implemented.
 * Project		 - NAL ( Network application logging )					
 * Module		 - LogManger
 * BU				 - DevGnana
 * Company		 - Cliff S
 * License		 - GPLV2 ( Open Source ) 
 ******************************************************************************************************************/
 
#ifndef __LOG_MNG_CONFIG__
#define __LOG_MNG_CONFIG__

#include<thread>
#include<string>
#include<mutex>
#include<map>
#include<vector>
#include <atomic>

using namespace std;

class LogMngConfig
{
	public :
		static LogMngConfig* getInstance();
		void readConfig(const string cfgFilePath);	
		bool getConfigValue(const string& key,vector<string>& value) ;
		~LogMngConfig();
	private:
		void updateConfig(const string& key,const string& value);
		LogMngConfig();
		LogMngConfig(const LogMngConfig&);
		LogMngConfig& operator = ( const LogMngConfig&);

	private:
		map<string,vector<string> > _logMngCfg;
		static atomic<LogMngConfig*> _instance;
		static mutex			_mutex;
		bool   _statRdCfg;
		
	friend
		ostream& operator << ( ostream& out , const LogMngConfig&);
};

#endif
