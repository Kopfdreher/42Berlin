## Essential CGI-ENV

`REQUEST_METHOD`: (e.g. `GET`, `POST`), decides to read from `QUERY_STRING` or `stdin`
`PATH_INFO`: the path being executed (e.g. after `.py` `/users/123` in `test.py/users/123`)
`PATH_TRANSLATED`: full absolute path (e.g. `/home/user/webserv/www/cgi-bin/script.py`)
`SCRIPT_NAME`: virtual path to script (e.g. `/cgi-bin/script.py`)

### GET Essentials
`QUERY_STRING`: for `GET` requests, contains everything after `?` (e.g. if URL `index.py?id=123`, it's `id=123`)

GET method indicates that the script should produce a document based on the meta-variable value.
[RFC3875](https://datatracker.ietf.org/doc/html/rfc3875#section-4.3.1)

### POST Essentials
`CONTENT_LENGTH`: size of request body in bytes, script reads the exact amount from `stdin`
`CONTENT_TYPE`: tells the script how to parse the body (e.g., `application/x-www-form-urlencoded` ...)

POST request the script to perform processing and produce a doc based on the data in the body in additio to the variables. (e.g. initiate processing by script with permanent affect, such as database manipulation) Checks CONTENT_LENGTH and CONTENT_TYPE, before reading body.
[RFC3875](https://datatracker.ietf.org/doc/html/rfc3875#section-4.3.2)

### Server Context
`GATEWAY_INTERFACE`: should be set to `CGI/1.1`
`SERVER_PROTOCOL`: for webserv `HTTP/1.1`

### HTTP Variables
`HTTP_COOKIE`: original http-header is `Cookie`

## execve(char *path, char *argv[], char *envp[])

`path`: the path to the interpreter (e.g. `/usr/bin/python3`)
`argv`: the strArr, `argv[0] = path`, `argv[1] = cgi_path`, `argv[2] = NULL`
`envp`: the converted `envMap`


## CGI TL;DR

### Config Syntax
```c++
location /cgi-bin {
    root ./www/cgi-bin;
    allow_methods GET POST;
    cgi_path .php /usr/bin/php-cgi;
    cgi_path .py /usr/bin/python3;
}
```

### URL (Uniform Resource Locator)
URL | http:// | localhost | :8080 | /cgi-bin/ | folder/test.php | /extra/path | ? | name=example
Component | Protocol | Host | Port | Location | File in root | Path Info |  | Query
CGI Variable | REQUEST_SCHEME | SERVER_NAME | SERVER_PORT | SCRIPT_NAME | SCRIPT_NAME | PATH_INFO |  | QUERY_STRING

### HTTP Header (Hypertext Transfer Protocol
HTTP Header | POST | /cgi-bin/ | folder/test.php | /extra/path | ? | name=example | HTTP/1.1
CGI Variable | REQUEST_METHOD | SCRIPT_NAME | SCRIPT_NAME | PATH_INFO |  | QUERY_STRING | SERVER_PROTOCOL

### Important "Hidden" Variables
`CONTENT_LENGTH`: in HTTP-Header as `Content-Length`
`CONTENT_TYPE`: in HTTP-Header as `Content-Type`
`PATH_TRANSLATED`: `root` + `PATH_INFO`
