#!/bin/bash
ulimit -n 65536 2>/dev/null || true
exec /usr/local/bin/docker-entrypoint.sh "$@"
