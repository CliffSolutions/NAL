#include "logApiConfig.h"

int main(void)
{
	LogApiConfig *ptr = LogApiConfig::getInstance(); 
	ptr->readConfig("../cong/logApi.cgf");
}
