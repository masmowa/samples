#include "AppSettings.h"
#include <tinyxml2.h>
#include <string>

using namespace std;
using namespace tinyxml2;


AppSettings::AppSettings()
{
    //ctor
}

AppSettings::~AppSettings()
{
    //dtor
}

void AppSettings::save(const char* pFilename)
{
	XMLDocument doc;
	XMLElement* msg;
	XMLComment * comment;
	string s;

 	XMLDeclaration* decl = doc.NewDeclaration();
	doc.LinkEndChild( decl );

	XMLElement * root = doc.NewElement(m_name.c_str());
	doc.LinkEndChild( root );

	s=" Settings for "+m_name+" ";
	comment = doc.NewComment(s.c_str());
	root->LinkEndChild( comment );

	// block: messages
	{
		MessageMap::iterator iter;

		XMLElement * msgs = doc.NewElement( "Messages" );
		root->LinkEndChild( msgs );

		for (iter=m_messages.begin(); iter != m_messages.end(); iter++)
		{
			const string & key=(*iter).first;
			const string & value=(*iter).second;
			msg = doc.NewElement(key.c_str());
			msg->LinkEndChild( doc.NewText(value.c_str()));
			msgs->LinkEndChild( msg );
		}
	}

	// block: windows
	{
		XMLElement * windowsNode = doc.NewElement( "Windows" );
		root->LinkEndChild( windowsNode );

		list<WindowSettings>::iterator iter;

		for (iter=m_windows.begin(); iter != m_windows.end(); iter++)
		{
			const WindowSettings& w=*iter;

			XMLElement * window;
			window = doc.NewElement( "Window" );
			windowsNode->LinkEndChild( window );
			window->SetAttribute("name", w.get_name_cs());
			window->SetAttribute("x", w.get_x());
			window->SetAttribute("y", w.get_y());
			window->SetAttribute("cx", w.get_cx());
			window->SetAttribute("cy", w.get_cy());
		}
	}

	// block: connection
	{
		XMLElement * cxn = doc.NewElement( "Connection" );
		root->LinkEndChild( cxn );
		cxn->SetAttribute("ip", m_connection.get_ip().c_str());
		cxn->SetAttribute("timeout", m_connection.get_timeout());
	}

	doc.SaveFile(pFilename);
}

void AppSettings::load(const char* pFilename)
{
	XMLDocument doc;
	if (doc.LoadFile(pFilename) != XML_SUCCESS) return;

	XMLHandle hDoc(&doc);
	XMLElement* pElem;
	XMLHandle hRoot(0);

	// block: name
	{
		pElem=hDoc.FirstChildElement().ToElement();
		// should always have a valid root but handle gracefully if it does
		if (!pElem) return;
		m_name=pElem->Value();

		// save this for later
		hRoot=XMLHandle(pElem);
	}

	// block: string table
	{
		m_messages.clear(); // trash existing table

		pElem=hRoot.FirstChildElement( "Messages" ).FirstChild().ToElement();
		for( pElem; pElem; pElem=pElem->NextSiblingElement())
		{
			const char *pKey=pElem->Value();
			const char *pText=pElem->GetText();
			if (pKey && pText)
			{
				m_messages[pKey]=pText;
			}
		}
	}

	// block: windows
	{
		m_windows.clear(); // trash existing list

		XMLElement* pWindowNode=hRoot.FirstChildElement( "Windows" ).FirstChild().ToElement();
		for( pWindowNode; pWindowNode; pWindowNode=pWindowNode->NextSiblingElement())
		{
			WindowSettings w;
			const char *pName=pWindowNode->Attribute("name");
			if (pName) w.Set_name(pName);

			int val = 0;
			pWindowNode->QueryIntAttribute("x", &val); // If this fails, original value is left as-is
			w.Set_x(val);
			val = 0;
			pWindowNode->QueryIntAttribute("y", &val);
			w.Set_y(val);
			val = 0;
			pWindowNode->QueryIntAttribute("w", &val);
			w.Set_cx(val);
			val = 0;
			pWindowNode->QueryIntAttribute("hh", &val);
			w.Set_cy(val);

			m_windows.push_back(w);
		}
	}

	// block: connection
	{
		pElem=hRoot.FirstChildElement("Connection").ToElement();
		if (pElem)
		{
			m_connection.Set_ip(pElem->Attribute("ip"));
			double dv = 0.0;
			pElem->QueryDoubleAttribute("timeout",&dv);
			m_connection.Set_timeout(dv);
		}
	}
}
