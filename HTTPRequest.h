/**
 * @class HTTPRequest
 * @brief est une classe de données munie de ses getters et d'une surcharge de 
          l'opérateur <<. L'objectif est de structurer les informations 
          concernant une requête HTTP parsées depuis des log Apache.
 * @date 07/02/2018
 * @author CADET DU
 */
//---------- Interface de la classe <HTTPRequest> (fichier HTTPRequest.h) ------------

#ifndef HTTPREQUEST_H_INCLUDED
#define HTTPREQUEST_H_INCLUDED

#include <string>

class HTTPRequest
{

public:
    HTTPRequest();
    HTTPRequest(const HTTPRequest &aHTTPRequest) = default;
    HTTPRequest &operator = (const HTTPRequest &aHTTPRequest) = default;
    virtual ~HTTPRequest() = default;


    /** @brief Surcharge de l'opérateur <<. Parse une requête r à partir d'un 
               flux d'entrée is sur un fichier de log Apache
     *
     * @param is flux d'entrée
     * @param r requête HTTP à parser
     *
     * @return Le flux d'entrée
     */
    friend std::istream &operator >> (std::istream &is, HTTPRequest &r);

    inline std::string IP() const { return ip; }
    inline std::string LogName() const { return logName; }
    inline std::string AuthName() const { return authName; }
    inline std::string DateTime() const { return dateTime; }
    inline std::string Method() const { return method; }
    inline std::string Document() const { return document; }
    inline std::string HTTPVersion() const { return httpVersion; }
    inline std::uint32_t HTTPCode() const { return httpCode; }
    inline std::string ContentLength() const { return contentLength; }
    inline std::string Referer() const { return referer; }
    inline std::string UserAgent() const { return userAgent; }

protected:
    std::string ip;
    std::string logName;
    std::string authName;
    std::string dateTime;
    std::string method;
    std::string document;
    std::string httpVersion;
    std::uint32_t httpCode;
    std::string contentLength;
    std::string referer;
    std::string userAgent;
};

#endif // HTTPREQUEST_H_INCLUDED
