#include <iostream>
#include <string>
#include <map>
#include <tinyxml2.h>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if defined(MINGW32) || defined(__MINGW32__)
    #include <io.h>  // mkdir
#else
	#include <sys/stat.h>	// mkdir
#endif

#include "AppSettings.h"

using namespace std;
using namespace tinyxml2;

// STDOUT dump and indenting utility functions
const unsigned int NUM_INDENTS_PER_SPACE=2;

/** \brief
 *
 * \param numIndents unsigned int
 * \return const char*
 *
 */
const char * getIndent(unsigned int numIndents )
{
    static const char * pINDENT="                                      + ";
    static const unsigned int LENGTH=strlen( pINDENT );
    unsigned int n = numIndents * NUM_INDENTS_PER_SPACE;
    if ( n > LENGTH ) { n = LENGTH; }

    return &pINDENT[ LENGTH - n ];
}

/** \brief
 *
 * \param numIndents unsigned int
 * \return const char*
 *
 */
const char * getIndentAlt( unsigned int numIndents )
{
    static const char * pINDENT="                                        ";
    static const unsigned int LENGTH=strlen( pINDENT );
    unsigned int n = numIndents * NUM_INDENTS_PER_SPACE;
    if ( n > LENGTH ) { n = LENGTH; }

    return &pINDENT[ LENGTH - n ];
}

/** \brief
 *
 * \param pElement XMLElement*
 * \param indent unsigned int
 * \return int
 *
 */
int dump_attribs_to_stdout(XMLElement* pElement, unsigned int indent)
{
	if ( !pElement ) return 0;

	const XMLAttribute* pAttrib=pElement->FirstAttribute();
	int i=0;
	int ival=0;
	double dval=0.0;
	const char* pIndent = getIndent(indent);
	printf("\n");

	while(pAttrib) {
        printf( "%s%s: value=[%s]", pIndent, pAttrib->Name(), pAttrib->Value() );

        if (pAttrib->QueryIntValue(&ival) == XML_SUCCESS) { printf( " int=%d", ival ); }
        if (pAttrib->QueryDoubleValue(&dval) == XML_SUCCESS) { printf( " int=%1.1f", dval ); }
        printf( "\n" );
        i++;
        pAttrib = pAttrib->Next();
	}
	return i;
}

void CreateAppSettings2()
{
	// block: customise and save settings
    AppSettings settings;
    settings.set_name("HitchHikerApp");
    settings.set_message("Welcome","Don't Panic");
    settings.set_message("Farewell","Thanks for all the fish");
    settings.get_windows().push_back(WindowSettings("BookFrame",15,25,300,250));
    settings.get_connection().Set_ip("192.168.0.77");
    settings.get_connection().Set_timeout(42.0);

    settings.save("appsettings2.xml");

}

void LoadAppSettings2()
{
    AppSettings settings;
    settings.load("appsettings2.xml");

    printf("%s: %s\n", settings.get_name().c_str(),
        settings.get_messages()["Welcome"].c_str());

    WindowSettings & w=settings.get_windows().front();
    printf("%s: Show window \"%s\" at %d,%d (%d x %d)\n",
        settings.get_name().c_str(),
           w.get_name_cs(),
           w.get_x(),
           w.get_y(),
           w.get_cx(),
           w.get_cy()
           );
    printf("%s: %s\n", settings.get_name().c_str(), settings.get_messages()["Farewell"].c_str());
}

/** \brief recursive decent parse XML document
 *
 * \param pParent XMLNode*
 * \param 0 int indent=
 * \return void
 *
 */
void dump_to_stdout(XMLNode* pParent, int indent = 0)
{
    if (!pParent) {
        return;
    }
    printf("%s", getIndent(indent));
    int num = 0;
#if 1
    XMLPrinter p(stdout);
    do {

    XMLDocument* xd = pParent->ToDocument();
    if (xd) {
        printf("Document");
        break;
    }
    XMLComment * xc = pParent->ToComment();
    if (xc) {
        printf("Comment [%s]", pParent->Value());
        break;
    }
    XMLElement * xe = pParent->ToElement();
    if (xe) {
//        XMLAttribute *xa
        printf("Element [%s]", pParent->Value());
        break;
    }
    XMLUnknown * xu = pParent->ToUnknown();
    if (xu) {
        printf("Unknown");
        break;
    }
    XMLText * xt = pParent->ToText();
    if (xt) {
        printf("Text [%s]", xt->Value());
        break;
    }
//    XMLElement * nt = pParent->ToElement();
//    if (nt) {
//        printf("Element [%s]", pParent->Value());
//        break;
//    }

    } while(false); // one pass scope control.

    printf( "\n" );

    XMLNode * pChild = NULL;
    for ( pChild = pParent->FirstChild(); pChild != NULL; pChild = pChild->NextSibling() ) {
        dump_to_stdout(pChild, indent+1);
    }

#else
    int t = pParent->Type();
    switch (t) {
        case XMLNode::DOCUMENT:
            printf("Document");
            break;

        case XMLNode::ELEMENT:
            printf( "Element [%s]", pParent->Value() );
            switch (num) {
                case 0: { printf( " (No attributes)" ); }
                case 1: { printf( "%s1 attribute", getIndentAlt(indent) ); break; }
                default: { printf( "%s%d atributes", getIndentAlt(indent), num ); break; }
            }
            break;

        case XMLNode::COMMENT:
            printf( "Comment: [%s]", pParent->Value() );
            break;

        case XMLNode::UNKNOWN:
            printf( "Unknown" );
            break;

        case XMLNode:TEXT:
            pText = pParent->ToText();
            printf( "Text: [%s]", pText->Value() );
            break;

        default:
            break;
    }
    printf( "\n" );

    for ( pChid = pParent->FirstChild(); pChild != NULL; pChild = pChild->NextSibling() ) {
        dump_to_stdout(pChild, indent+1);
    }
#endif // 1
}

/** \brief load the named file and dump its structure to STDOUT
 *
 * \param pFileName const char*
 * \return void
 *
 */
void dump_to_stdout(const char* pFileName)
{
    if (!pFileName) {
        std::cout << "ERROR: void dump_to_stdout(const char* pFileName) Invalid fine name" << endl;
        return;
    }
    XMLDocument doc;
    XMLError loadOkay = doc.LoadFile(pFileName);
    if (loadOkay == XML_SUCCESS) {
        std::cout << "\n" << pFileName << ":" << endl;
        dump_to_stdout( &doc );
    }
    else {
        std::cout << "Failed to load file \"" << pFileName << "\"" << std::endl;

    }
}

void test_load_delete(const char * pFilePath)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;

    if ( pFilePath ) {
        XMLDocument* doc = new XMLDocument();
        clock_t startTime = clock();
        doc->LoadFile( pFilePath );
        clock_t loadTime = clock();
        int errorID = doc->ErrorID();
        delete doc; doc = 0;
        clock_t deleteTime = clock();

        printf( "Test file '%s' loaded. ErrorID=%d\n", pFilePath, errorID );
        if ( !errorID ) {
            printf( "Load time=%u\n",   (unsigned)(loadTime - startTime) );
            printf( "Delete time=%u\n", (unsigned)(deleteTime - loadTime) );
            printf( "Total time=%u\n",  (unsigned)(deleteTime - startTime) );
        }
	}
    std::cout << "--" << __PRETTY_FUNCTION__ << std::endl;

}
// gcc C:\etc\CodeBlocks\MinGW
int main( int argc, const char ** argv )
{
	#if defined(_MSC_VER) || defined(MINGW32) || defined(__MINGW32__)
		#if defined __MINGW64_VERSION_MAJOR && defined __MINGW64_VERSION_MINOR
			//MINGW64: both 32 and 64-bit
			mkdir( "resources/out/" );
            #else
                _mkdir( "resources/out/" );
            #endif
	#else
		mkdir( "resources/out/", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	#endif

	if ( argc > 1 ) {
        printf("argv[1] == %s\n", argv[1]);
        test_load_delete(argv[1]);
	}
	if (argc > 1) {
        printf("argv[1] == %s\n", argv[1]);
        dump_to_stdout(argv[1]);
	}

	CreateAppSettings2();

	LoadAppSettings2();

	cout << "" << endl;
    cout << "--Hello world!" << endl;
    return 0;
}
