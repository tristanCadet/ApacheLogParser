/*************************************************************************
                                HTTPRequest
                             -------------------
    copyright            : (C) 2018 par CADET DU
*************************************************************************/
//---------- Implémentation de la classe <HTTPRequest> (fichier HTTPRequest.cpp) ------------
#include "HTTPRequest.h"

#include <iostream>
#include <limits>

using namespace std;

HTTPRequest::HTTPRequest() : ip(), logName(), authName(), dateTime(), method(),
    document(), httpVersion(), httpCode(), contentLength(), referer(), userAgent()
{

}

istream &operator >> (istream &is, HTTPRequest &r)
{
    is >> r.ip;
    is >> r.logName;
    is >> r.authName;

    is.ignore(numeric_limits<streamsize>::max(), '[');
    getline(is, r.dateTime, ']');

    is.ignore(numeric_limits<streamsize>::max(), '"');
    is >> r.method;

    is >> r.document;

    getline(is, r.httpVersion, '"');

    is >> r.httpCode;
    is >> r.contentLength;

    is.ignore(numeric_limits<streamsize>::max(), '"');
    getline(is, r.referer, '"');

    is.ignore(numeric_limits<streamsize>::max(), '"');
    getline(is, r.userAgent, '"');

#ifdef DEBUG
    cerr << "IP : " << r.ip << "\n"
         << "logName : " << r.logName << "\n"
         << "authName : " << r.authName << "\n"
         << "dateTime : " << r.dateTime << "\n"
         << "method : " << r.method << "\n"
         << "document : " << r.document << "\n"
         << "httpVersion : " << r.httpVersion << "\n"
         << "httpCode : " << r.httpCode << "\n"
         << "contentLength : " << r.contentLength << "\n"
         << "referer : " << r.referer << "\n"
         << "userAgent : " << r.userAgent << endl;
#endif // DEBUG

    return is;
}

