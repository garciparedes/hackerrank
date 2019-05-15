#!/usr/bin/env python3

import sys
import re


def main():
    regex_pattern = r'^[^\d][^aeiou][^bcDF][^\r\n\t ][^AEIOU][^\.,]$'
    print(str(bool(re.search(regex_pattern, input()))).lower())


if __name__ == '__main__':
    main()
