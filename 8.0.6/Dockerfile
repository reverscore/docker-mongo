FROM mongo:8.0.6-noble

ENV DEBIAN_FRONTEND=noninteractive
ENV GLIBC_TUNABLES=glibc.pthread.rseq=0
ENV LD_PRELOAD=/usr/local/lib/libno_rseq.so

COPY mongodb.conf /etc/mongo/mongodb.conf
COPY no_rseq.c /tmp/no_rseq.c

# Build rseq-blocking library and raise ulimit
RUN set -eux; \
    apt-get update; \
    apt-get install -y --no-install-recommends gcc libc6-dev; \
    gcc -shared -fPIC -o /usr/local/lib/libno_rseq.so /tmp/no_rseq.c -ldl; \
    rm /tmp/no_rseq.c; \
    apt-get purge -y --auto-remove gcc; \
    rm -rf /var/lib/apt/lists/*; \
    sed -i '1a ulimit -n 65536 2>/dev/null || true' /usr/local/bin/docker-entrypoint.sh

# Expose the default port
EXPOSE 27017
EXPOSE 28017

CMD ["mongod", "--config", "/etc/mongo/mongodb.conf"]
HEALTHCHECK --interval=30s --timeout=5s --start-period=30s --retries=3 \
  CMD mongosh --eval 'db.runCommand("ping").ok' --quiet || exit 1
