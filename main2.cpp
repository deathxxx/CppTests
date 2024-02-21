//
// Created by Лира on 21.02.2024.
//

/*
 *
 * chatgpt -
 * modify this method in cpp from curl to non curl - std::string ReqUrl::sendGet(const std::string& url, bool printResponse) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(CURLE_OK == res && printResponse) {
            std::cout << readBuffer << std::endl;
        }
    }
    return readBuffer;
}

 */

#include <iostream>
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::string sendGet(const std::string& url, bool printResponse) {
    std::string readBuffer;
    std::string host = "example.com"; // Placeholder - you need to parse the URL to extract the host
    std::string target = "/"; // Placeholder - you need to parse the URL to extract the target path
    std::string port = "80"; // Use "443" for HTTPS, which also requires SSL setup in Asio

    // Parse the URL to extract the host, port, and target. This step is skipped in this example.

    try {
        asio::io_context context;

        // Resolve the host name to an IP address
        asio::ip::tcp::resolver resolver(context);
        auto endpoints = resolver.resolve(host, port);

        // Create a socket and connect to the server
        asio::ip::tcp::socket socket(context);
        asio::connect(socket, endpoints);

        // Formulate the request message
        std::string request = "GET " + target + " HTTP/1.1\r\n";
        request += "Host: " + host + "\r\n";
        request += "User-Agent: Mozilla/5.0\r\n";
        request += "Accept: */*\r\n";
        request += "Connection: close\r\n\r\n";

        // Send the request
        socket.write_some(asio::buffer(request, request.length()));

        // Read the response
        for(;;) {
            char buf[1024];
            std::error_code ec;
            size_t len = socket.read_some(asio::buffer(buf), ec);
            if(ec == asio::error::eof) {
                break; // Connection closed cleanly by peer
            } else if(ec) {
                throw asio::system_error(ec); // Some other error
            }

            readBuffer.append(buf, len);
        }

        if(printResponse) {
            std::cout << readBuffer << std::endl;
        }
    } catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return readBuffer;
}
