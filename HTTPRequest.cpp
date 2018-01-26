#include "HTTPRequest.h"

#include <string>
#include <iostream>
#include <limits>

using namespace std;

istream& operator >> (istream& is, HTTPRequest& r)
{
    is >> r.ip;
    is >> r.logName;
    is >> r.authName;

    is.ignore(numeric_limits<streamsize>::max(), '[');
    getline(is, r.dateTime, ']');

    is >> r.method;
    r.method.erase(0, 1);

    is >> r.document;

    is >> r.httpVersion;
    r.httpVersion.erase(r.httpVersion.length() - 1, 1);

    is >> r.httpCode;
    is >> r.contentLength;

    is.ignore(numeric_limits<streamsize>::max(), '"');
    getline(is, r.referer, '"');

    is.ignore(numeric_limits<streamsize>::max(), '"');
    getline(is, r.userAgent, '"');

#ifdef DEBUG
    cerr << "IP : " << r.ip << "\n";
    cerr << "logName : " << r.logName << "\n";
    cerr << "authName : " << r.authName << "\n";
    cerr << "dateTime : " << r.dateTime << "\n";
    cerr << "method : " << r.method << "\n";
    cerr << "document : " << r.document << "\n";
    cerr << "httpVersion : " << r.httpVersion << "\n";
    cerr << "httpCode : " << r.httpCode << "\n";
    cerr << "contentLength : " << r.contentLength << "\n";
    cerr << "referer : " << r.referer << "\n";
    cerr << "userAgent : " << r.userAgent << endl;
#endif // DEBUG

    return is;
}

