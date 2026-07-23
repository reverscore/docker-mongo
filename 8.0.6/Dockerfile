FROM mongo:8.0.6-noble

ENV DEBIAN_FRONTEND=noninteractive
ENV GLIBC_TUNABLES=glibc.pthread.rseq=0

COPY mongodb.conf /etc/mongo/mongodb.conf

# Raise nofile ulimit to prevent "Too many open files" under heavy load
RUN sed -i '1a ulimit -n 65536 2>/dev/null || true' /usr/local/bin/docker-entrypoint.sh

# Expose the default port
EXPOSE 27017
EXPOSE 28017

HEALTHCHECK --interval=30s --timeout=5s --start-period=30s --retries=3 \
  CMD mongosh --eval 'db.runCommand("ping").ok' --quiet || exit 1
