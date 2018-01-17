#include "Request.h"

#include <string>
#include <iostream>
#include <limits>

using namespace std;

istream& operator >> (istream& is, Request& r)
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
    cout << "IP : " << r.ip << "\r\n";
    cout << "logName : " << r.logName << "\r\n";
    cout << "authName : " << r.authName << "\r\n";
    cout << "dateTime : " << r.dateTime << "\r\n";
    cout << "method : " << r.method << "\r\n";
    cout << "document : " << r.document << "\r\n";
    cout << "httpVersion : " << r.httpVersion << "\r\n";
    cout << "httpCode : " << r.httpCode << "\r\n";
    cout << "contentLength : " << r.contentLength << "\r\n";
    cout << "referer : " << r.referer << "\r\n";
    cout << "userAgent : " << r.userAgent << endl;
#endif // DEBUG

    return is;
}

