#!/bin/sh
set -eu

/usr/bin/env python3 "$@" -Dq='2**140 - 27' -Dmodulus_bytes='35' -Da24='121665'
