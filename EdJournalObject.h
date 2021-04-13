#ifndef EDJOURNALOBJECT_H
#define EDJOURNALOBJECT_H

#include "json.hpp"

class EdJournalObject		/**< Elite Dangerous journal object processing class */
{
	public:
		EdJournalObject();
        EdJournalObject(const std::string &sObject);
		virtual ~EdJournalObject();
		void Set(const std::string &sObject);
		std::string GetKeyValue(const std::string sKey);
		std::string ReceiveText();

    private:
        nlohmann::json m_jObject;
};

#endif // EDJOURNALOBJECT_H
