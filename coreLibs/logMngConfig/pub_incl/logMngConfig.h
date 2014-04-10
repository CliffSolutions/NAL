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
