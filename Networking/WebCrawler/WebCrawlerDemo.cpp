#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/regex.hpp>

using boost::asio::ip::tcp;

class WebCrawler {
public:
    WebCrawler(boost::asio::io_service& io_service, const std::string& server, const std::string& path)
        : resolver_(io_service), socket_(io_service) {
        std::ostream request_stream(&request_);
        request_stream << "GET " << path << " HTTP/1.0\r\n";
        request_stream << "Host: " << server << "\r\n";
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: close\r\n\r\n";

        tcp::resolver::query query(server, "http");
        resolver_.async_resolve(query, boost::bind(&WebCrawler::handle_resolve, this, boost::asio::placeholders::error, boost::asio::placeholders::iterator));
    }

private:
    void handle_resolve(const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator) {
        if (!err) {
            boost::asio::async_connect(socket_, endpoint_iterator, boost::bind(&WebCrawler::handle_connect, this, boost::asio::placeholders::error));
        } else {
            std::cout << "Error: " << err.message() << "\n";
        }
    }

    void handle_connect(const boost::system::error_code& err) {
        if (!err) {
            boost::asio::async_write(socket_, request_, boost::bind(&WebCrawler::handle_write_request, this, boost::asio::placeholders::error));
        } else {
            std::cout << "Error: " << err.message() << "\n";
        }
    }

    void handle_write_request(const boost::system::error_code& err) {
        if (!err) {
            boost::asio::async_read_until(socket_, response_, "\r\n", boost::bind(&WebCrawler::handle_read_status_line, this, boost::asio::placeholders::error));
        } else {
            std::cout << "Error: " << err.message() << "\n";
        }
    }

    void handle_read_status_line(const boost::system::error_code& err) {
        if (!err) {
            std::istream response_stream(&response_);
            std::string http_version;
            response_stream >> http_version;
            unsigned int status_code;
            response_stream >> status_code;
            std::string status_message;
            std::getline(response_stream, status_message);
            if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
                std::cout << "Invalid response\n";
                return;
            }
            if (status_code != 200) {
                std::cout << "Response returned with status code " << status_code << "\n";
                return;
            }

            boost::asio::async_read_until(socket_, response_, "\r\n\r\n", boost::bind(&WebCrawler::handle_read_headers, this, boost::asio::placeholders::error));
        } else {
            std::cout << "Error: " << err.message() << "\n";
        }
    }

    void handle_read_headers(const boost::system::error_code& err) {
        if (!err) {
            std::istream response_stream(&response_);
            std::string header;
            while (std::getline(response_stream, header) && header != "\r")
                std::cout << header << "\n";
            std::cout << "\n";

            if (response_.size() > 0)
                std::cout << &response_;

            boost::asio::async_read(socket_, response_, boost::asio::transfer_at_least(1), boost::bind(&WebCrawler::handle_read_content, this, boost::asio::placeholders::error));
        } else {
            std::cout << "Error: " << err << "\n";
        }
    }

    void handle_read_content(const boost::system::error_code& err) {
        if (!err) {
            std::cout << &response_;

            boost::asio::async_read(socket_, response_, boost::asio::transfer_at_least(1), boost::bind(&WebCrawler::handle_read_content, this, boost::asio::placeholders::error));
        } else if (err != boost::asio::error::eof) {
            std::cout << "Error: " << err << "\n";
        }
    }

    tcp::resolver resolver_;
    tcp::socket socket_;
    boost::asio::streambuf request_;
    boost::asio::streambuf response_;
};

int main() {
    try {
        boost::asio::io_service io_service;
        WebCrawler c(io_service, "example.com", "/");
        io_service.run();
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
