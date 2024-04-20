"""
This module contains the argument parser.

This module is responsible for parsing the arguments and returning them as a tuple.

Example:
```
    foo = parse_args() # returns a tuple of (IP: str, Port: int)
    print(foo) # prints the IP and Port ('127.0.0.1', 8000)
```
"""

from argparse import ArgumentParser
from typing import Union
from socket import inet_aton


def parse_args() -> Union[tuple[str, int], None]:
    """Parses arguments

    Returns:
        Union[tuple[str, int], None]: Tuple of (IP: str, Port: int)
    """
    parser = ArgumentParser(description="BSLE v4B Capstone Client")
    parser.add_argument(
        "--ip",
        "-i",
        default="127.0.0.1",
        help="IP the server",
    )
    parser.add_argument(
        "--port",
        "-p",
        type=int,
        default=8000,
        help="Port number of the server",
    )

    parsed = parser.parse_args()

    if parsed.port < 1024 or parsed.port > 65535:
        parser.error("Port must be between 1024 and 65535")

    try:
        inet_aton(parsed.ip)
    except OSError:
        parser.error("Invalid IP address")

    return (parsed.ip, parsed.port)
