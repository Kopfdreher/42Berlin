import sys
import os

# Read the body sent by the C++ Server via the pipe
body = sys.stdin.read()
method = os.environ.get("REQUEST_METHOD", "UNKNOWN")

# CGI scripts must print their own headers!
print("Content-Type: text/html\r\n", end="")

# Print the dynamic HTML body
print(f"""
<html>
    <body>
        <h1>CGI Execution Successful!</h1>
        <p>Your server executed this Python script.</p>
        <p><strong>Method used:</strong> {method}</p>
        <p><strong>Data received from POST:</strong> {body}</p>
    </body>
</html>
""")
