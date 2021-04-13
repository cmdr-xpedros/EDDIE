#include "stdafx.h"
#include "EdJournalObject.h"

using json = nlohmann::json;

EdJournalObject::EdJournalObject()
:m_jObject()
{
	//ctor
}

EdJournalObject::EdJournalObject(const std::string &sObject)
:m_jObject()
{
	//ctor
	Set(sObject);
}

EdJournalObject::~EdJournalObject()
{
	//dtor
}

//convert string sObject to a json object and store it to a member variable m_jObject
void EdJournalObject::Set(const std::string &sObject)
{
    m_jObject = json::parse(sObject);
}

std::string EdJournalObject::GetKeyValue(const std::string sKey)
{
    if(!m_jObject.empty())
        return m_jObject.value(sKey, "");   //return empty string as default
    else
        return {};
}

std::string EdJournalObject::ReceiveText()
{
    std::string sRet;
    std::string sFrom;
    std::string sValue = GetKeyValue("event");
    if(!sValue.compare("ReceiveText"))
    {
        sValue = GetKeyValue("Channel");
        if(!sValue.compare("npc"))
        {
            //From an NPC
            sFrom = GetKeyValue("From_Localised");
            if(sFrom.empty())
            {
                sFrom = GetKeyValue("From");
            }
            if(!sFrom.empty())
            {
                sRet = sFrom + " (NPC): "; //name
            }
            sValue = GetKeyValue("Message_Localised");
        }
        else
        {
            //From a player
            sFrom = GetKeyValue("From");
            if(!sFrom.empty())
            {
                sRet = sFrom + ": "; //name
            }
            sValue = GetKeyValue("Message");
        }
        sRet += sValue;  //return message
    }
    return sRet;
}
